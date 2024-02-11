# Experimental
A space for all Unreal Experiments

# Asset Validation
I created a small script that checks if the widget blueprints respect a specific naming convention, in this case, the widgets must start with "WBP_". If they violate the rule, an error is thrown when the asset is saved.
![assetValidatorName](https://github.com/yallen99/Experimental/assets/55985184/53cd04be-7e47-493a-9105-2a416affd703)

# Custom Project Settings 
Using the DeveloperSettings I created my section in Unreal's Project Settings (UI Settings). This section should enable fast iteration over the whole UI in a game, such as replacing assets, updating timer values, creating colour charts and so on. The usage of a config file is endless. In my little experiment, I added a section for Button Icons, for Xbox and PlayStation buttons. (This is for demonstration purposes only - if the project uses Common UI, this would be redundant)
![ConfigIcons](https://github.com/yallen99/Experimental/assets/55985184/03317889-db4c-4aea-9bf2-5aa22cdde5d2)

# Widget Safe Zone Component
I was curious about the safe zone component from UMg and how it reacts to different platforms, specifically mobile. I found out how to test with it using the unreal console.
![SafeZone](https://github.com/yallen99/Experimental/assets/55985184/b7bb3c1c-27f1-43a9-b6c1-f8a7fde3ea95)

# Automation & Testing part 1
I briefly touched the surface of unit testing and automation. It's a comprehensive topic I will explore more in the future, but because this project is just a little experiment, I didn't go too in-depth with it. I refreshed my memory on how to access the Session Frontend, the type of tests and how to run the tests.
![Testing_1](https://github.com/yallen99/Experimental/assets/55985184/78b457ed-f56d-4a70-9422-01487d784576)

# MVVM Plugin - Base setup using blueprints
Set up and used the MVVM Plugin provided by Epic in a very common case scenario - a health bar. Created an MVVM custom class, added a Health value to it and bound it using Field Notify to a progress bar in UMG. In a custom Player Controller I bound increase/decrease health functions to test the widget updates accordingly.
![image](https://github.com/yallen99/Experimental/assets/55985184/c7b3c20a-336f-411e-8778-a5b1aef02e8d)

# Unreal Insights Profiling
Although an extensive topic, I wanted to try Unreal Insights and managed to mark a function to show on the Unreal Insights graph. It was a silly function running a loop over a million elements (so it would be significant on the graph). Upsed a scope timer and a scope timer with a channel. 
![image](https://github.com/yallen99/Experimental/assets/55985184/4ba60ec3-b29b-4410-b2e5-178cc28cee62)
![image](https://github.com/yallen99/Experimental/assets/55985184/1f409639-885b-45ed-bf24-110768b90bfe)


