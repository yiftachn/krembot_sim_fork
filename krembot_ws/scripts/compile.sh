!/bin/bash 


echo "Compiling krembot_ws..." ; echo

mkdir -p build && cd build

cmake ..

make

echo "Done." ; echo

