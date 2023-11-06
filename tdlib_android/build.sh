#!/bin/sh

mkdir -p build-$ABI
cd build-$ABI
cmake .. -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake -DCMAKE_BUILD_TYPE=MinSizeRel -GNinja -DANDROID_ABI=${ABI} || exit 1
cmake --build . || exit 1
cd ..

mkdir -p libs/$ABI/
cp build-$ABI/libtd*.so libs/$ABI/

rm -r -f build-$ABI/libtd*.so
rm -r -f build-$ABI/libtd*.so*