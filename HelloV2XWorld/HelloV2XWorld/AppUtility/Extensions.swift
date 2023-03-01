//
//  Extensions.swift
//  HelloV2XWorld
//
//  Created by Ahmed Hamdy on 30/12/2022.
//

import SwiftUI
import VodafoneV2X

extension Color {
    init(hex: Int, opacity: Double = 1.0) {
        let red = Double((hex & 0xff0000) >> 16) / 255.0
        let green = Double((hex & 0xff00) >> 8) / 255.0
        let blue = Double((hex & 0xff) >> 0) / 255.0
        self.init(.sRGB, red: red, green: green, blue: blue, opacity: opacity)
    }
    func ignoreColorForSafeArea() -> some View {
        if #available(iOS 14.0, *) {
            return self.ignoresSafeArea()
        }
        return self.edgesIgnoringSafeArea(.all)
    }
}

extension View {
    func previewLandScapeOrientation() -> some View {
        if #available(iOS 15.0, *) {
            return self.previewInterfaceOrientation(.landscapeRight)
        }
        return self
    }
}

extension UIImage {
    func rotate(radians: Float) -> UIImage? {
        let imageCGRect = CGRect(origin: CGPoint.zero, size: self.size)
        var newSize = imageCGRect.applying(CGAffineTransform(rotationAngle: CGFloat(radians))).size
        // Trim off the extremely small float value to prevent core graphics from rounding it up
        newSize.width = floor(newSize.width)
        newSize.height = floor(newSize.height)

        UIGraphicsBeginImageContextWithOptions(newSize, false, self.scale)
        let context = UIGraphicsGetCurrentContext()!

        // Move origin to middle
        context.translateBy(x: newSize.width/2, y: newSize.height/2)
        // Rotate around middle
        context.rotate(by: CGFloat(radians))
        // Draw the image at its center
        let width = self.size.width
        let height = self.size.height
        self.draw(in: CGRect(x: -width/2, y: -height/2, width: width, height: height))

        let newImage = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()

        return newImage
    }
}

extension StationKind {
    func getTextValue() -> String {
        let dictionary: [StationKind: String] = [
            .unknown: "Unknown",
            .pedestrian: "Pedestrian",
            .cyclist: "Cyclist",
            .moped: "Moped",
            .motorcycle: "Motorcycle",
            .passengerCar: "Passenger Car",
            .bus: "Bus",
            .lightTruck: "Light Truck",
            .heavyTruck: "Heavy Truck",
            .trailer: "Trailer",
            .specialVehicles: "Special Vehicles",
            .tram: "Tram",
            .roadSideUnit: "Road Side Unit"
        ]
        return dictionary[self] ?? .empty
    }
}
