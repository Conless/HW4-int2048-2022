test -e build/ || mkdir build
echo "mkdir build/"
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES ..
make
