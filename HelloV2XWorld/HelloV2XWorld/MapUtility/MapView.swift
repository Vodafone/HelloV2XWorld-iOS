//
//  MapView.swift
//  HelloV2XWorld
//
//  Created by Mohamed Elabd on 03/01/2023.
//

import Foundation
import MapKit
import SwiftUI
import VodafoneV2X
import Combine

struct MapView: UIViewRepresentable, DIContainerProvider {
    // Region of the mapView
    @Binding var region: MKCoordinateRegion
    // Array of custom map annotations.
    @Binding var camAnnotations: [CamAnnotation]
    // Describe the connection state of the step instance
    @Binding var connectionState: String
    // Zoom level based on the zoom buttons on the mapView
    @EnvironmentObject var zoomSettings: ZoomSettings
    // Observable for the SDK CAM list changes
    @StateObject var sdkCamListObservable = SDKCAMListObservable()
    // SharedInstance of the SDK configurator class
    let sdkConfig = SDKConfigurator.sharedInstance
    // MapView Instance
    let mapView = MKMapView(frame: UIScreen.main.bounds)
    // preserve the last location received from the location updates
    var myLastKnownLocation: CLLocation?
    /// Create the mapView
    /// - Parameter context: context of  current view
    /// - Returns: Instance of mapView
    func makeUIView(context: Context) -> MKMapView {
        mapView.delegate = context.coordinator
        mapView.region = region
        mapView.showsUserLocation = true
        mapView.showsCompass = false
        mapView.isZoomEnabled = false
        return mapView
    }
    /// Update view fuction where to show V2X CAM messages
    /// - Parameters:
    ///   - view: Instance of the mapView
    ///   - context: Context of current view.
    func updateUIView(_ view: MKMapView, context: Context) {
        showV2XCAMMessagesList(camMessagesList: self.sdkCamListObservable.camList, mapView: view)
        adjustMapZoomLevel(zoomAltitude: self.zoomSettings.altitude, mapView: view)
    }
    func makeCoordinator() -> Coordinator {
        Coordinator(self)
    }
    class Coordinator: NSObject, MKMapViewDelegate {
        var parent: MapView
        init(_ parent: MapView) {
            self.parent = parent
        }
        // MARK: - MKMapViewDelegate
        /// Delegate method for new location updates
        /// - Parameters:
        ///   - mapView: Instance of the mapView
        ///   - userLocation: new user location updates
        func mapView(_ mapView: MKMapView, didUpdate userLocation: MKUserLocation) {
            DispatchQueue.main.async {
                if self.parent.myLastKnownLocation == nil {
                    let userLocation = userLocation.coordinate
                    let mapViewSpan = self.parent.region.span
                    self.parent.mapView.region = MKCoordinateRegion(center: userLocation, span: mapViewSpan)
                } else {
                    if self.parent.connectionState != "Connected" { return }
                    let zoomAltitude = self.parent.zoomSettings.altitude
                    let lastLocation = self.parent.myLastKnownLocation
                    self.parent.adjustMapZoomLevel(zoomAltitude: zoomAltitude, mapView: mapView)
                    let mapCamera = MKMapCamera(lookingAtCenter: userLocation.coordinate,
                                                fromEyeCoordinate: lastLocation?.coordinate ?? CLLocationCoordinate2D(),
                                                eyeAltitude: mapView.camera.centerCoordinateDistance)
                    mapCamera.pitch = 0
                    let shouldAnimate = self.parent.isMajorDistance(pre: lastLocation, current: userLocation.location)
                    mapView.setCamera(mapCamera, animated: !shouldAnimate)
                }
                self.parent.myLastKnownLocation = userLocation.location
            }
        }
        /// Create annotation view for every new annotation
        /// - Parameters:
        ///   - mapView: Instance of your MapView.
        ///   - annotation: Custom annotation object.
        /// - Returns: AnnotationView.
        func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
            if let annotation = annotation as? CamAnnotation {
                return self.parent.createAnnotationView(annotation: annotation)
            }
            return MKAnnotationView()
        }
    }
}

extension MapView {
    /// Create MKAnnotationView to be present on the map to show CAM message
    /// - Parameter annotation: Custom annotation object.
    /// - Returns: AnnotationView.
    func createAnnotationView(annotation: CamAnnotation) -> MKAnnotationView {
        let annotationView = MKAnnotationView(annotation: annotation, reuseIdentifier: String(annotation.id ?? 0))
        annotationView.canShowCallout = true
        annotationView.image = annotation.image
        annotationView.detailCalloutAccessoryView = getSubtitleView(subtitle: annotation.subtitle)
        return annotationView
    }
    /// Create subtitle view for the CAM annotation
    /// - Parameter subtitle: Subtitle string.
    /// - Returns: View to be used with the MKAnnotationView
    func getSubtitleView(subtitle: String?) -> UIView {
        let customSubtitleView = UILabel()
        customSubtitleView.font = customSubtitleView.font.withSize(12)
        customSubtitleView.numberOfLines = 0
        customSubtitleView.text = subtitle ?? ""
        return customSubtitleView
    }
    /// To check if the current location leaps a great distance which normally only happens in Testing environment
    /// - Parameters:
    ///   - pre: Previous location coordinates
    ///   - current: Current location coordinates
    /// - Returns: True incase the distance is greater than 500 meters.
    func isMajorDistance(pre: CLLocation?, current: CLLocation?) -> Bool {
        if let myLastKnownLocation = pre, let currentLocation = current {
            return myLastKnownLocation.distance(from: currentLocation) > 500
        }
        return false
    }
    /// Show or update new CAM messages received from the SDK framework
    /// - Parameters:
    ///   - camMessagesList: list of CAM messages received.
    ///   - mapView: Instance of your MapView.
    func showV2XCAMMessagesList(camMessagesList: [V2XCAM], mapView: MKMapView) {
        if let camList = self.sdkConfig.camMessagesList {
            for item in camList {
                var itemFound = false
                for camAnnotationItem in self.camAnnotations where item.object?.stationID == camAnnotationItem.id {
                    itemFound = true
                    break
                }
                if !itemFound {
                    addAnnotationToCamList(item: item, mapView: mapView)
                } else {
                    updateAnnotationInCamList(item: item, mapView: mapView)
                }
            }
            removeAnnotationIfNeeded(camList: camMessagesList, mapView: mapView)
        }
    }
    // MARK: Annotation CRUD Operations
    /// Function to add new CAM annotation to the mapView if not added before.
    /// - Parameters:
    ///   - item: CAM object Instance.
    ///   - mapView: Instance of your MapView.
    func addAnnotationToCamList(item: V2XCAM, mapView: MKMapView) {
        let latitude  = item.object?.coordinate.latitude ?? 0
        let longitude = item.object?.coordinate.longitude ?? 0
        let camAnnotation = CamAnnotation(id: item.object?.id ?? 0,
                                          coordinate: CLLocationCoordinate2D(latitude: latitude, longitude: longitude),
                                          v2xCAM: item)
        camAnnotations.append(camAnnotation)
        DispatchQueue.main.async {
            mapView.addAnnotation(camAnnotation)
        }
    }
    /// Function to update (location, Icon if station type changed) of all the pre-added CAM annotations.
    /// - Parameters:
    ///   - item: CAM object Instance.
    ///   - mapView: Instance of your MapView.
    func updateAnnotationInCamList(item: V2XCAM, mapView: MKMapView) {
        for (index, annotation) in self.camAnnotations.enumerated() where annotation.id == item.object?.id ?? 0 {
            let latitude  = item.object?.coordinate.latitude ?? 0
            let longitude = item.object?.coordinate.longitude ?? 0
            self.camAnnotations[index].coordinate = CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
            self.camAnnotations[index].v2xCAM = item
            self.camAnnotations[index].stationType = item.object?.stationType
            let annotationView = mapView.view(for: annotation)
            annotationView?.detailCalloutAccessoryView = getSubtitleView(subtitle: annotation.getSubtitleText())
            if ConfigsOnDemand.stationID != annotation.id {
                var rotationAngle = 0.0
                if let degree = item.object?.headingDegrees, degree > 0.0 {
                    rotationAngle = CGFloat(degree * .pi / 180 ) - (mapView.camera.heading * .pi / 180)
                }
                let updatedHeadingImage = annotation.image.rotate(radians: Float(rotationAngle))
                annotationView?.image = updatedHeadingImage
            }
            break
        }
    }
    /// Function to handle remove cam users whose no longer sending CAM messages.
    /// - Parameters:
    ///   - camList: List of the newly updated CAM messages.
    ///   - mapView: Instance of your MapView.
    func removeAnnotationIfNeeded(camList: [V2XCAM], mapView: MKMapView) {
        for annotation in self.camAnnotations {
            // Check if there are CamAnnotation with no present in the CamMessages list.
            let filteredList = camList.filter({
                $0.object?.stationID == annotation.id
            })
            if filteredList.isEmpty && annotation.v2xCAM != nil {
                mapView.removeAnnotation(annotation)
                camAnnotations.removeAll {
                    $0.id == annotation.id
                }
            }
        }
        if mapView.annotations.count - 1 > camList.count {
            mapView.removeAnnotations(mapView.annotations)
            camAnnotations.removeAll()
        }
    }
    /**
     Function responsible for updating the map zoom level according to  zoom buttons.
     
     - parameter zoomAltitude: zoom value represented in altitude
     - parameter mapView: Current used mapView.
     */
    func adjustMapZoomLevel(zoomAltitude: Double, mapView: MKMapView) {
        // update mapView with zoomLevel
        let camera = MKMapCamera(
            lookingAtCenter: mapView.userLocation.coordinate,
            fromDistance: zoomAltitude,
            pitch: mapView.camera.pitch,
            heading: mapView.camera.heading
        )
        mapView.setCamera(camera, animated: true)
    }
}

/// Observing the zoom level of the mapView
class ZoomSettings: ObservableObject {
    @Published var altitude = 200.0
}
