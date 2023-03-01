//
//  SDKConfigurator.swift
//  V2XSDKTest
//
//  Created by Ahmed Hamdy on 07/09/2022.
//

import Foundation
import VodafoneV2X
import Combine
import SwiftUI

class SDKConfigurator: NSObject, DIContainerProvider {
    // Singleton Shared instance variable
    static let sharedInstance = SDKConfigurator()
    // Cancellable object for the list changes of the V2X Messages list updates
    var mqttCancellable: AnyCancellable?
    var mqttServiceCancellable: AnyCancellable?
    var camListenerCancellable: AnyCancellable?
    // CAM list provider for the V2XCAM Messages
    var camListProvider: CAMListProvider?
    // Store the received cam messages
    var camMessagesList: [V2XCAM]?
    // Private init to only used the sharedInstance variable
    private override init() { }
    /// Setup station type as your need for the project
    func setStationType() {
        let stationTypeValue = UInt(UserDefaults.standard.integer(forKey: Constants.stationType.rawValue))
        if let stationType = StationKind.init(rawValue: stationTypeValue), stationType != .unknown {
            ConfigsOnDemand.stationType = stationType
        } else {
            ConfigsOnDemand.stationType = .passengerCar
            UserDefaults.standard.set(StationKind.passengerCar.rawValue, forKey: Constants.stationType.rawValue)
        }
    }
    /// Provide correct credentials and connect to the STEP envionment
    func connectToSTEP() {
        setStationType()
        // Credentials for the step instance
        // Here we use the production instance as DE_PROD_FRANKFURT
        let mqttConfig = V2XMQTTConfigurator(stepInstance: .DE_PROD_FRANKFURT,
                                             username: Credentials.userName.rawValue,
                                             pass: Credentials.password.rawValue,
                                             reconnect: nil)
        // Provide V2X object time interval validity
        let locationServConfig = ServiceConfiguration(expiration: 5)
        // Provide the topic you desire to publish/subscribe according the registration step on STEP web portal
        let camPublicSubServiceGroup = MQTTSubServiceGroup(publish: "510298_1",
                                                           subscribe: "510298_1")
        // Provide CAM service config of validity, subServiceGroup for the topics and transmit/receive config
        let camConfig = ServiceConfiguration(expiration: 2,
                                             subServiceGroup: camPublicSubServiceGroup,
                                             txRxRole: RxTxRoles(tx: true, rx: true))
        // Provide the list of service you would like to config with SDK Framework
        let listServices = ListServices(location: locationServConfig,
                                        cam: camConfig,
                                        denm: nil,
                                        ivim: nil,
                                        mapem: nil,
                                        spatem: nil,
                                        vam: nil)
        // Provide the mqttConfig for credentials and service as showed above
        let config = V2XConfigurator(mqtt: mqttConfig, services: listServices)
        // Setup the SDK DI container with the config and custom geohasing if required "optional" from project side.
        V2XDIContainer.setupDIContainer(with: config, geohashing: nil)
    }
    /// Reconnect again with SDK step instance
    func reconnectMQTT() {
        setStationType()
        let mqttConfig = V2XMQTTConfigurator(stepInstance: .DE_PROD_FRANKFURT,
                                             username: Credentials.userName.rawValue,
                                             pass: Credentials.password.rawValue,
                                             reconnect: nil)
        V2XDIContainer.shared?.reconfigureMQTT(mqttConfig)
    }
    // MARK: - setup CAM
    /// Launch the CAM service
    func startCAM() {
        if let isActive = container?.camService?.isActive, isActive == false {
            _ = self.container?.camService?.start()
        }
    }
    /// Observe a real time changes of all the CAM messages which are nearby
    func setupCAMListProvider() {
        guard let listProvider = container?.camListProvider else { return }
        self.camListProvider = listProvider
        self.camListenerCancellable = listProvider.listChanged.receive(on: RunLoop.main).sink(receiveValue: { CAMList in
            self.camMessagesList = CAMList
            NotificationCenter.default.post(name: Notification.Name("isCamListUpdated"), object: nil)
        })
    }
    // MARK: - check Connection
    /// Check new SDK step instance connection state
    /// - Parameter completion: The current connection state
    func checkConnectionState(completion: @escaping (String) -> Void) {
        guard let mqttService = container?.mqttClient else {
            return
        }
        mqttCancellable = mqttService.connectionState.receive(on: RunLoop.main).sink { connectionState in
            if connectionState == .connected {
                self.setupCAMListProvider()
            }
            completion(("\(connectionState.rawValue)"))
        }
    }
}

/// Observe on the CAM list update changes
class SDKCAMListObservable: ObservableObject {
    @Published var camList: [V2XCAM] = []
    private var cancellable: AnyCancellable?

    init() {
        cancellable = NotificationCenter.default.publisher(for: Notification.Name("isCamListUpdated"))
        .receive(on: RunLoop.main)
        .sink { _ in
            self.camList = SDKConfigurator.sharedInstance.camMessagesList ?? []
        }
    }
}
