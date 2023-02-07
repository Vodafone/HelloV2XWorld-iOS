# HelloV2XWorld-iOS

In this repository you can find an example of V2X application that show how to use the V2X-SDK in a ready to use iOS Application.

## Description

The HelloV2XWorld application demonstrates how easy it is to create a V2X application and exchange V2X messages with other road users.
This application is powered by the V2X-SDK and the STEP platform developed by Vodafone.
By cloning this project you will be able to create and execute your first V2X application in less than 15 minutes.
The HelloV2XWorld application shows a map with all the road users close to your location.
You can also use this application as a model to start developing your own application.

## Getting Started

### Prerequisites
* Xcode version 11 or higher is already installed on your MacBook.
* You have some experience with developing apps using swift and swiftUI.
* You have a tool pre-installed for unarchiving RAR or Zip files like "The Unarchiver".
* Your Internet connectivity is up and running.
* You are available for 15 minutes.


### Download the V2X-SDK library for iOS

* Register yourself on the [STEP Web portal](https://step.vodafone.com/)
* Go to the [STEP Web portal](https://step.vodafone.com/) webpage and login.
* Navigate to the page "Documentation" and select the "SDK documentation for iOS" option.
* In the "SDK documentation for iOS" page , click on the "Download SDK" button.
=> Your browser downloads the archive "VodafoneV2X_iOS_SDK.rar".
* Open the archive, extract the V2X-SDK library file called "VodafoneV2X.xcframework" and save it on your laptop.

### Clone the HelloV2XWorld Application

* Open Xcode.
* Choose from the Xcode tab bar "Source Control" then "Clone".
* In the popup window enter the repository URL "https://github.com/Vodafone/HelloV2XWorld-iOS.git".
* Press "Clone" button to start downloading the HelloV2XWorld project.
* Wait until the completion of this operation.
* Choose "main" branch from the popup then press "Clone" then desired save location on you MacBook.

### Import the V2X-SDK library in your project

* After opening the HelloV2XWorld project.
* Go to xcodproj settings page "General".
* Scroll down to "Frameworks" and click on the "+" sign then choose to add pre-downloaded "VodafoneV2X.xcframework".

### Build the HelloV2XWorld application

* Click from Xcode tab bar "Product" then "Build" (or use the shortcut "Command⌘ B").

### Run the HelloV2XWorld application on the any iOS Simulator or real device after providing your own Development provision profile.

* Select your iOS Simulator (for ex. iPhone 14.)
* Press the RUN button.
* Wait until the "Simulator" windows appears.
* When the App opens, read the Term and Conditions, Click on the next button to navigate till the end then click on the "Accept" button.
* Accept the location permissions to provide your own location data.
* A map is displayed centered on your current location.
* The blue icon represents yourself.
* The red icons represents the other road users close to you.
* You can change your station type by accessing the setting page


## Version History

* 1.0
    * Initial Release

## License

This project is licensed under the MIT License - see the LICENSE.md file for details
