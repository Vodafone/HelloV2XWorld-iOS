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
    func getSubtitleText() -> String {
        let stationType = v2xCAM?.object?.stationType.getTextValue() ?? ""
        let speedKmH = Double(round(1000 * (v2xCAM?.object?.speedKmH ?? 0.0)) / 1000)
        let headingDegrees = adjustHeading(v2xCAM?.object?.headingDegrees ?? 0.0)
        return "StationType=\(stationType), Speed=\(speedKmH) Km/h, Heading=\(headingDegrees) Degree"
    }
    /// Adjusts the heading value based on the current device orientation
    /// - Parameter heading: Heading value of v2xCAM
    /// - Returns: Adjusted heading value int the correct degree range
    func adjustHeading(_ heading: Float) -> Float {
        var newHeading = heading
        // If device is in landscape right orientation, add 90 degrees to the heading, Otherwise subtract 90 degrees
        if ConfigsOnDemand.customDeviceOrientation == .landscapeRight {
            newHeading += 90
        } else {
            newHeading -= 90
        }
        // If heading is less than 0, add 360 until it is in the range 0...360
        while newHeading < 0 {
            newHeading += 360
        }
        // If heading is greater than 360, subtract 360 until it is in the range 0...360
        while newHeading >= 360 {
            newHeading -= 360
        }
        return newHeading
    }
}
