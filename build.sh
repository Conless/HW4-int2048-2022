rm -rf build
test -e build/ || mkdir build
echo "mkdir build/"
cd build
cmake ..
make
