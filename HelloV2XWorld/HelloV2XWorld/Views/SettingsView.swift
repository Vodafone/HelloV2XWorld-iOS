//
//  SettingsView.swift
//  HelloV2XWorld
//
//  Created by Mohamed Elabd on 05/01/2023.
//

import SwiftUI
import VodafoneV2X

struct SettingsView: View {
    @Environment(\.presentationMode) var presentation
    @State private var stationType: StationKind = ConfigsOnDemand.stationType
    @State private var appID = Credentials.userName.rawValue
    @State private var appToken = Credentials.password.rawValue
    @State private var showActionSheet = false
    var body: some View {
        ZStack {
            // Background Color
            Color(hex: 0xAA0000)
                .ignoreColorForSafeArea()
            VStack {
                // Title
                HStack {
                    Spacer()
                    Text("Settings")
                        .fontWeight(.bold)
                        .font(.largeTitle)
                        .foregroundColor(.white)
                    Spacer()
                }
                Spacer()
                // Station Type Label and TextField
                HStack {
                    Text(Constants.stationType.rawValue)
                        .padding(.trailing, 40)
                        .foregroundColor(.white)
                    Color.white
                        .overlay(
                            Button {
                                self.showActionSheet = true
                            } label: {
                                Text("\($stationType.wrappedValue.getTextValue())")
                                    .foregroundColor(.black)
                            }
                                .frame(minWidth: 0,
                                       maxWidth: .infinity,
                                       minHeight: 35,
                                       maxHeight: 35,
                                       alignment: .leading)
                                .padding(.leading, 8)
                        )
                        .frame(minWidth: 0, maxWidth: .infinity, minHeight: 35, maxHeight: 35)
                        .cornerRadius(5)
                        .actionSheet(isPresented: $showActionSheet) {
                            ActionSheet(title: Text(Constants.stationType.rawValue),
                                        message: nil,
                                        buttons: stationTypeButtons())
                        }
                }
                // Application ID Label and TextField
                HStack {
                    Text("ApplicationID")
                        .padding(.trailing, 30)
                        .foregroundColor(.white)
                    TextField("", text: $appID)
                        .textFieldStyle(.roundedBorder)
                        .disabled(true)
                }
                // Application Token Label and TextField
                HStack {
                    Text("ApplicationToken")
                        .padding(.trailing, 3)
                        .foregroundColor(.white)
                    TextField("", text: $appToken)
                        .textFieldStyle(.roundedBorder)
                        .disabled(true)
                }
                Spacer()
                // Action Buttons
                HStack {
                    Spacer()
                    // Cancel Button
                    Color.white
                        .overlay(
                            Button(action: {
                                self.presentation.wrappedValue.dismiss()
                            }, label: {
                                Text("Cancel").foregroundColor(.black)
                            })
                        )
                        .frame(minWidth: 0, maxWidth: 150, minHeight: 50, maxHeight: 50)
                        .cornerRadius(25)
                    // Apply Button
                    Color.white
                        .overlay(
                            Button(action: {
                                let stationTypeKey = Constants.stationType.rawValue
                                UserDefaults.standard.set($stationType.wrappedValue.rawValue, forKey: stationTypeKey)
                                SDKConfigurator.sharedInstance.reconnectMQTT()
                                self.presentation.wrappedValue.dismiss()
                            }, label: {
                                Text("Apply").foregroundColor(.black)
                            })
                        )
                        .frame(minWidth: 150, maxWidth: 150, minHeight: 50, maxHeight: 50)
                        .cornerRadius(25)
                }
            }
            .padding()
        }
        .onAppear {
            stationType = ConfigsOnDemand.stationType
        }
    }
    /// Add station types to ActionSheet
    func stationTypeButtons() -> [ActionSheet.Button] {
        return [.default(Text(StationKind.passengerCar.getTextValue()),
                         action: { stationType = .passengerCar }),
            .default(Text(StationKind.bus.getTextValue()),
                     action: { stationType = .bus}),
            .default(Text(StationKind.cyclist.getTextValue()),
                     action: { stationType = .cyclist}),
            .default(Text(StationKind.motorcycle.getTextValue()),
                     action: { stationType = .motorcycle}),
            .default(Text(StationKind.pedestrian.getTextValue()),
                     action: { stationType = .pedestrian}),
            .default(Text(StationKind.roadSideUnit.getTextValue()),
                     action: { stationType = .roadSideUnit}),
            .default(Text(StationKind.moped.getTextValue()),
                     action: { stationType = .moped}),
            .default(Text(StationKind.lightTruck.getTextValue()),
                     action: { stationType = .lightTruck }),
            .default(Text(StationKind.heavyTruck.getTextValue()),
                     action: { stationType = .heavyTruck }),
            .default(Text(StationKind.specialVehicles.getTextValue()),
                     action: { stationType = .specialVehicles }),
            .default(Text(StationKind.trailer.getTextValue()),
                     action: { stationType = .trailer }),
            .default(Text(StationKind.tram.getTextValue()),
                     action: { stationType = .tram }),
            .cancel()]
    }
}

struct SettingsView_Previews: PreviewProvider {
    static var previews: some View {
        SettingsView()
            .previewLandScapeOrientation()
    }
}
