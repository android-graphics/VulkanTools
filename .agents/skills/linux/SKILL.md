---
name: Build and test for Linux
description: Instructions for building and testing for Android
---

# Prerequisites for everything

You must be on a Linux host. If you are on a different host, you cannot build for Linux. Check the current host OS.

If the current host is not Linux, do not proceed. Tell the user that you cannot build for Linux from the current host OS.



# Build and test instructions


To build the project and run the tests, run the following command from the root of the repository:

```
./scripts/github_ci_linux.py
```


# Requirements for running the builds

1. Use CMake and Ninja from the Android SDK. Make sure they are available in $PATH. Use the `bin/` subdirectory of the CMake package from Android SDK. Make sure the CMake package you are using is version 3.22.1 or newer. 

The CMake package inside Android SDK also  contains a `ninja` binary next to the `cmake` binary, so you don't need to do anything other than adding that directory to PATH.

You will find Android SDK using the ANDROID_HOME environment variable. If it's not set, set it to the default location for the current operating system.






