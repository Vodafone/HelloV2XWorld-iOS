//
//  HomeView.swift
//  HelloV2XWorld
//
//  Created by Ahmed Hamdy on 28/12/2022.
//

import SwiftUI
import VodafoneV2X
import MapKit

struct HomeView: View {
    // ZoomSetting state object to fire which zoom buttons action
    @StateObject var zoomSettings = ZoomSettings()
    // Region proberty for the mapView
    @State private var region = MKCoordinateRegion(center: CLLocationCoordinate2D(latitude: 0, longitude: 0),
                                                   span: MKCoordinateSpan(latitudeDelta: 0.005, longitudeDelta: 0.005))
    // List which will contains the V2XCAM users to present on the mapView
    @State var list = [CamAnnotation(coordinate: CLLocationCoordinate2D())]
    // STEP Instance connection state ("Stopped", "Connecting", "Connected")
    @State var connectionState: String = "Connecting.."
    // SDK configuration class instance
    let sdkInstance = SDKConfigurator.sharedInstance
    // SwiftUI Body variable
    var body: some View {
        NavigationView {
            ZStack(alignment: .topTrailing) {
                // Display Apple Maps
                MapView(region: $region, camAnnotations: $list, connectionState: $connectionState).onAppear {
                    // Start CAM service when mapView appears
                    sdkInstance.startCAM()
                }
                .frame(minWidth: 0, maxWidth: .infinity, minHeight: 0, maxHeight: .infinity)
                .edgesIgnoringSafeArea(.all)
                VStack(alignment: .trailing) {
                    // Connection Status View
                    Color.gray.opacity(0.5)
                        .overlay(
                            VStack {
                                Text("Status")
                                Text(connectionState)
                                    .bold()
                                    .onAppear {
                                        // Handle shows STEP instance connection's state
                                        sdkInstance.checkConnectionState { text in connectionState = text }
                                    }
                            }
                        )
                        .cornerRadius(10)
                        .frame(maxWidth: 200, maxHeight: 100)
                    Spacer()
                    HStack {
                        Spacer()
                        // Zoom Out Button
                        MapButtonView(action: {
                            // MAX Zoom Out
                            if zoomSettings.altitude < 10000000 {
                                zoomSettings.altitude += zoomSettings.altitude * 2
                            }
                        }, imageName: "minus.magnifyingglass")
                        // Zoom In Button
                        MapButtonView(action: {
                            // Minimum Zoom In
                            if zoomSettings.altitude > 100 {
                                zoomSettings.altitude -= zoomSettings.altitude / 2
                            }
                        }, imageName: "plus.magnifyingglass")
                        // Setting Screen Button
                        Color.gray.opacity(0.7)
                            .overlay(
                                NavigationLink {
                                    SettingsView()
                                        .navigationBarHidden(true)
                                } label: {
                                    Image(systemName: "gearshape.fill")
                                        .foregroundColor(.black)
                                }
                            )
                            .cornerRadius(20)
                            .frame(maxWidth: 75, maxHeight: 60)
                        Spacer()
                    }
                    .padding(.bottom, 15)
                }
                .edgesIgnoringSafeArea(.all)
            }
            .navigationBarHidden(true)
        }
        .navigationViewStyle(.stack)
        .environmentObject(zoomSettings)
    }
}

struct HomeView_Previews: PreviewProvider {
    static var previews: some View {
        HomeView()
            .previewLandScapeOrientation()
    }
}
// Mapview Zoom buttons
struct MapButtonView: View {
    let action: () -> Void
    var imageName: String
    var body: some View {
        Color.gray.opacity(0.7)
            .overlay(
                ZoomButtonView(imageName: imageName, action: action)
            )
            .cornerRadius(20)
            .frame(maxWidth: 75, maxHeight: 60)
    }
}
// Zoom button view
struct ZoomButtonView: View {
    let imageName: String
    let action: () -> Void
    var body: some View {
        Button(action: action, label: {
            Image(systemName: imageName).foregroundColor(.black)
        })
    }
}
