#!/bin/sh
# ABI="x86" ./build.sh || exit 1
ABI="x86_64" ./build.sh || exit 1
ABI="armeabi-v7a" ./build.sh || exit 1
ABI="arm64-v8a" ./build.sh || exit 1
