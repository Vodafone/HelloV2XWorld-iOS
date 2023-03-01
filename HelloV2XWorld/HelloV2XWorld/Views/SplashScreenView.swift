//
//  SplashScreenView.swift
//  HelloV2XWorld
//
//  Created by Ahmed Hamdy on 30/12/2022.
//

import SwiftUI
import PDFKit

struct SplashScreenView: View {
    @State private var enableAcceptButton = false
    @State private var document = PDFDocument()

    // To handle opening the app without showing terms and conditions in the second time
    private var isTermsAccepted = UserDefaults.standard.bool(forKey: Constants.termsAndConditionsAccepted.rawValue)
    var body: some View {
        NavigationView {
            ZStack {
                // Background Color
                Color(hex: 0xAA0000)
                    .ignoreColorForSafeArea()
                if isTermsAccepted {
                    // Navigate to HomeView if accepted
                    HomeView()
                        .navigationBarHidden(true)
                        .onAppear {
                            // Start Connect to STEP environment.
                            SDKConfigurator.sharedInstance.connectToSTEP()
                        }
                } else {
                    // Show Terms And Conditions
                    VStack {
                        Spacer(minLength: 20)
                        Text("Terms & Conditions")
                            .fontWeight(.bold)
                            .font(.largeTitle)
                            .padding(.bottom, -5)
                        ZStack {
                            PDFKitView(document: $document, enableAcceptButton: $enableAcceptButton)
                        }
                        HStack {
                            Spacer()
                            // Exit Button
                            Color.white.opacity(0.8)
                                .overlay(
                                    Button(action: {
                                        exit(0)
                                    }, label: {
                                        Text("Exit").foregroundColor(.black)
                                    })
                                )
                                .frame(minWidth: 0, maxWidth: 150, maxHeight: 50)
                                .cornerRadius(25)
                            // Accept Button
                            if enableAcceptButton {
                                // Enabled Button
                                Color.white.opacity(0.8)
                                    .overlay(
                                        NavigationLink {
                                            HomeView()
                                                .navigationBarHidden(true)
                                                .onAppear {
                                                    // Start Connect to STEP environment.
                                                    SDKConfigurator.sharedInstance.connectToSTEP()
                                                    // Mark terms and conditions as Read
                                                    let termsKey = Constants.termsAndConditionsAccepted.rawValue
                                                    UserDefaults.standard.set(true, forKey: termsKey)
                                                }
                                        } label: {
                                            Text("Accept")
                                                .foregroundColor(.black)
                                        }
                                    )
                                    .frame(minWidth: 0, maxWidth: 150, maxHeight: 50)
                                    .cornerRadius(25)
                            } else {
                                // Disabled Button
                                Color.white.opacity(0.4)
                                    .overlay(
                                        Text("Accept")
                                            .foregroundColor(.black)
                                    )
                                    .frame(minWidth: 0, maxWidth: 150, maxHeight: 50)
                                    .cornerRadius(25)
                            }
                            Spacer()
                        }
                        .padding(.bottom, 5)
                    }
                }
            }
            .navigationBarHidden(true)
        }
        .navigationViewStyle(.stack)
        .onAppear {
            // Load the terms and conditions PDF Document
            loadPDFDocument()
        }
    }
    /// Load Terms And Conditions PDF Document
    func loadPDFDocument() {
        // Load PDF from local path
        guard let path = Bundle.main.url(forResource: "TermsAndConditions", withExtension: "pdf")
        else { return }
        do {
            let data = try Data(contentsOf: path)
            if let document = PDFDocument(data: data) {
                self.document = document
            }
        } catch {
            print(error)
        }
    }
}

struct SplashScreenView_Previews: PreviewProvider {
    static var previews: some View {
        SplashScreenView()
            .previewLandScapeOrientation()
    }
}
