//
//  CamAnnotation.swift
//  HelloV2XWorld
//
//  Created by Ahmed Hamdy on 10/01/2023.
//

import Foundation
import MapKit
import VodafoneV2X

final class CamAnnotation: NSObject, MKAnnotation {
    // dynamic variable for the user coordinate
    dynamic var coordinate: CLLocationCoordinate2D
    var id: UInt?
    var v2xCAM: V2XCAM?
    var title: String? { getTitleText() }
    var subtitle: String? { getSubtitleText() }
    var stationType: StationKind?
    var image: UIImage { getCamIcon() }
    var location: CLLocation {
        return CLLocation(latitude: self.coordinate.latitude, longitude: self.coordinate.longitude)
    }
    init(coordinate: CLLocationCoordinate2D) {
        self.coordinate = coordinate
    }
    init(id: UInt?, coordinate: CLLocationCoordinate2D, v2xCAM: V2XCAM?) {
        self.id = id
        self.coordinate = coordinate
        self.v2xCAM = v2xCAM
        self.stationType = v2xCAM?.object?.stationType
    }
    /// Give the suitable icon per CAM mm
    /// - Returns: Image of the CAM to present on the map
    func getCamIcon() -> UIImage {
        if id == ConfigsOnDemand.stationID {
            return UIImage(named: "currentLocationArrow") ?? UIImage()
        }
        return UIImage(named: "camUserArrow") ?? UIImage()
    }
    func getTitleText() -> String? {
        if let stationID = id {
            if id == ConfigsOnDemand.stationID {
                return "ITS: StationID=\(stationID)"
            }
            return "CAM: StationID=\(stationID)"
        }
        return nil
    }
    func getStationTypeText() -> String {
        if id == ConfigsOnDemand.stationID {
            return ConfigsOnDemand.stationType.getTextValue()
        }
        return v2xCAM?.object?.stationType.getTextValue() ?? ""
    }
    func getSubtitleText() -> String {
        let stationType = getStationTypeText()
        let speedKmH = Double(round(1000 * (v2xCAM?.object?.speedKmH ?? 0.0)) / 1000)
        let headingDegrees = v2xCAM?.object?.headingDegrees ?? 0.0

        return "StationType=\(stationType), Speed=\(speedKmH) Km/h, Heading=\(headingDegrees) Degree"
    }
}
