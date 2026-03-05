---
name: Build for Android
description: Instructions for building for Android
---


# Build instructions


To build the project for Android, run the following command from the root of the repository:


```
scripts/android.py
```


# Requirements for running the build script

1. Make sure the `ANDROID_HOME`  environment variable is set. If it's not set,
   then set it to the default location based on the current operating system.


2. Make sure the `ANDROID_NDK_HOME` environment variable is set.  Verify that it's set to NDK version 29 or newer. If it's not set, use the latest NDK version from the $ANDROID_HOME location, but make sure it satisfies the minimum NDK version required.



3. Use CMake and Ninja from the Android SDK. Make sure they are available in $PATH. Use the `bin/` subdirectory of the CMake package from Android SDK. Make sure the CMake package you are using is version 3.22.1 or newer. 

THe CMake package inside Android SDK also  contains a `ninja` binary next to the `cmake` binary, so you don't need to do anything other than adding that directory to PATH.

