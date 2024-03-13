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
* Xcode version 14.1 or higher is already installed on your MacBook.
* You have some experience with developing apps using swift and swiftUI.
* You have a tool pre-installed for unarchiving RAR or Zip files like "The Unarchiver".
* Your Internet connectivity is up and running.
* You are available for 15 minutes.


### Download the V2X-SDK library for iOS

* Register yourself on the [STEP Web portal](https://step.vodafone.com/)
<img width="1145" alt="step1 (1)" src="https://user-images.githubusercontent.com/124599387/219050113-50e5a149-1559-4776-af0f-30d3ad16c5ef.png">

* Go to the [STEP Web portal](https://step.vodafone.com/) webpage and login.

   * Enter your credentials:
<img width="1145" alt="step2" src="https://user-images.githubusercontent.com/124599387/219050444-cf48a53c-60e4-458a-a021-5841a789ccc6.png">
   * Enter your PinCode:
<img width="1145" alt="Screenshot 2023-02-16 at 11 46 58 AM" src="https://user-images.githubusercontent.com/124599387/219347713-ae3ab91e-092d-4222-9241-91898eb10907.png">

* Navigate to the page "Documentation" and select the "SDK documentation for iOS" option.
<img width="1145" alt="sdkiOS" src="https://user-images.githubusercontent.com/124599387/219348034-8c6f63e1-9070-43b8-9e4c-27bdd92cb7f2.png">

* In the "SDK documentation for iOS" page.
   * click on the "Download SDK" button for the SDK xcframework.
   * click on the "Download documentation" button for the SDK documentation and user guide.
<img width="1145" alt="downloadSDKiOS (1)" src="https://user-images.githubusercontent.com/124599387/219348935-697b4ad1-2ac5-4689-9e14-184683b86f47.png">


=> Your browser downloads the archive "VodafoneV2X_iOS_SDK.rar".
* Open the archive, extract the V2X-SDK library file called "VodafoneV2X.xcframework" and save it on your laptop.

### Clone the HelloV2XWorld Application

* Open Xcode.
* Choose from the Xcode tab bar "Source Control" then "Clone".
* In the popup window enter the repository URL "https://github.com/Vodafone/HelloV2XWorld-iOS.git".
<img width="812" alt="Screenshot 2023-02-15 at 4 45 10 PM" src="https://user-images.githubusercontent.com/124599387/219060946-09effd69-2d20-4abb-956c-b93ddf2e9326.png">

* Press "Clone" button to start downloading the HelloV2XWorld project.
* Wait until the completion of this operation.
* Choose "main" branch from the popup then press "Clone" then desired save location on you MacBook.

### Import the V2X-SDK library in your project

* After opening the HelloV2XWorld project.
* Go to xcodproj settings page "General".
* Scroll down to "Frameworks" and click on the "+" sign.
<img width="1426" alt="Screenshot 2023-02-15 at 5 09 18 PM" src="https://user-images.githubusercontent.com/124599387/219067872-dfad32dc-1b96-4f96-87a1-c50fa88635e7.png">
* Choose "Add Others" then "Add Files" and select to add the pre-downloaded "VodafoneV2X.xcframework".
<img width="1426" alt="Screenshot 2023-02-15 at 5 13 50 PM" src="https://user-images.githubusercontent.com/124599387/219068916-3a921a60-3a4b-4ec6-8cdb-e794c6e35f6f.png">


### Build the HelloV2XWorld application

* Click from Xcode tab bar "Product" then "Build" (or use the shortcut "Command⌘ B").

### Run the HelloV2XWorld application

* You can run the app on any iOS Simulator or real device after providing your own Development provision profile.
* Select your iOS Simulator (for ex. iPhone 14.)
* Press the RUN button.
* Wait until the "Simulator" windows appears.
<img width="978" alt="Screenshot 2023-02-15 at 5 21 14 PM" src="https://user-images.githubusercontent.com/124599387/219073820-fda13846-2880-4e9f-8e4a-83bca6f85057.png">

* When the App opens, read the Term and Conditions, Click on the next button to navigate till the end then click on the "Accept" button.
<img width="978" alt="Screenshot 2023-02-15 at 5 22 38 PM" src="https://user-images.githubusercontent.com/124599387/219071275-fcb3d179-277f-40e4-956b-3469de927704.png">

* Accept the location permissions to provide your own location data.
<img width="978" alt="Screenshot 2023-02-15 at 5 24 14 PM" src="https://user-images.githubusercontent.com/124599387/219071498-53ee428d-07eb-4016-9d29-3976c463fd68.png">

* A map is displayed centered on your current location.
<img width="978" alt="Screenshot 2023-02-15 at 5 25 28 PM" src="https://user-images.githubusercontent.com/124599387/219071875-78b48c79-571d-4a6a-82a4-786ef045b84b.png">

* The blue icon represents yourself.
* The red icons represents the other road users close to you.
<img width="978" alt="Screenshot 2023-02-15 at 5 26 58 PM" src="https://user-images.githubusercontent.com/124599387/219072339-ec0c9f0a-e28f-44d7-a7ed-7236850d8940.png">

* When clicking on the blue icon, app displays you ITS information: StationID, StationType, Speed, Heading.
<img width="978" alt="Screenshot 2023-02-15 at 5 28 08 PM" src="https://user-images.githubusercontent.com/124599387/219073433-9fffe855-ff5b-49e9-985e-bdef510d7201.png">

* When clicking on any red icon, app displays you the CAM information: StationID, StationType, Speed, Heading.
<img width="978" alt="Screenshot 2023-02-15 at 5 29 30 PM" src="https://user-images.githubusercontent.com/124599387/219073535-4c4a736f-a3d0-4b78-9beb-2540c1cd1e31.png">

* You can change your station type by accessing the setting page
<img width="978" alt="Screenshot 2023-02-15 at 5 29 38 PM" src="https://user-images.githubusercontent.com/124599387/219073630-0802fe3e-20ba-4403-9ab7-99fdd0da5b6c.png">

## Version History

* 1.0
    * Initial Release.
* 1.0.1
    * Bug Fixing
        * Fix connectivity after changing station type from settings.
        * Fix ITS marker orientation according to the device orientation.
* 1.0.2
    * Bug Fixing
        * Fix ITS marker orientation according to the device orientation.
* 1.0.3
    * Bug Fixing
        * Fix map rotation according to the course value instead of heading.
        * Prevent the device screen from sleeping while the app is running.
        
## License

This project is licensed under the MIT License - see the LICENSE.md file for details
