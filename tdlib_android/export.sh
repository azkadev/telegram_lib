#!/bin/sh

mkdir -p build_native
cd build_native
cmake .. || exit 1
cmake --build . --target prepare_cross_compiling || exit 1
cd ..

./build-all.sh || exit 1

rm -rf tdlib_export
mkdir -p tdlib_export/tdlib
echo libs | xargs tar -c | tar -C tdlib_export/tdlib -xv

cd tdlib_export
find . -name '.DS_Store' -type f -print0 | xargs -0 rm -f
# jar -cMf tdlib_debug.zip tdlib
# rm tdlib/libs/*/*.debug
jar -cMf tdlib.zip tdlib

cd ..

rm -r -f libs/*