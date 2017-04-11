# Android NDK r14, r14b, r15beta1 Boost compliation failure

Download Boost (e.g. 1.63.0) from http://www.boost.org/users/download/, and unzip it into `app/libs/boost_1_63_0`.

Run

```
./gradlew externalNativeBuildRelease
```

You will observe a Clang crash akin to the following:

```
  FAILED: /Users/kkaefer/Library/Android/sdk/ndk-bundle/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++  --target=x86_64-none-linux-android --gcc-toolchain=/Users/kkaefer/Library/Android/sdk/ndk-bundle/toolchains/x86_64-4.9/prebuilt/darwin-x86_64 --sysroot=/Users/kkaefer/Library/Android/sdk/ndk-bundle/platforms/android-21/arch-x86_64  -Dnative_lib_EXPORTS -isystem ../../../../libs/boost_1_63_0 -isystem /Users/kkaefer/Library/Android/sdk/ndk-bundle/sources/cxx-stl/gnu-libstdc++/4.9/include -isystem /Users/kkaefer/Library/Android/sdk/ndk-bundle/sources/cxx-stl/gnu-libstdc++/4.9/libs/x86_64/include -isystem /Users/kkaefer/Library/Android/sdk/ndk-bundle/sources/cxx-stl/gnu-libstdc++/4.9/include/backward -g -DANDROID -ffunction-sections -funwind-tables -fstack-protector-strong -no-canonical-prefixes -Wa,--noexecstack -Wformat -Werror=format-security  -g -DANDROID -ffunction-sections -funwind-tables -fstack-protector-strong -no-canonical-prefixes -Wa,--noexecstack -Wformat -Werror=format-security  -std=c++11 -frtti -fexceptions -O2 -DNDEBUG -O2 -DNDEBUG  -fPIC -MD -MT CMakeFiles/native-lib.dir/src/main/cpp/native-lib.cpp.o -MF CMakeFiles/native-lib.dir/src/main/cpp/native-lib.cpp.o.d -o CMakeFiles/native-lib.dir/src/main/cpp/native-lib.cpp.o -c /Users/kkaefer/Code/android-boost-rtree/app/src/main/cpp/native-lib.cpp
  clang++: error: unable to execute command: Segmentation fault: 11
  clang++: error: clang frontend command failed due to signal (use -v to see invocation)
  Android clang version 3.8.275480  (based on LLVM 3.8.275480)
  Target: x86_64-none-linux-android
  Thread model: posix
  InstalledDir: /Users/kkaefer/Library/Android/sdk/ndk-bundle/toolchains/llvm/prebuilt/darwin-x86_64/bin
  clang++: note: diagnostic msg: PLEASE submit a bug report to http://llvm.org/bugs/ and include the crash backtrace, preprocessed source, and associated run script.
  clang++: note: diagnostic msg:
  ********************

  PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:
  Preprocessed source(s) and associated run script(s) are located at:
  clang++: note: diagnostic msg: /var/folders/d9/49s5f6ln6qx7myj13xw4gztc0000gn/T/native-lib-4dc9cf.cpp
  clang++: note: diagnostic msg: /var/folders/d9/49s5f6ln6qx7myj13xw4gztc0000gn/T/native-lib-4dc9cf.sh
  clang++: note: diagnostic msg:

  ********************

```

This crash only occurs for x86_64, and only in Release mode (`-O2` and higher).
