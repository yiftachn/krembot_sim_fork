#!/bin/bash

# this script is based on argos comilation instructions on github:
# https://github.com/ilpincy/argos3
# https://github.com/ilpincy/argos3-examples

echo "*** Installing Krembot Simulator ***" ; echo

SCRIPT_PATH=`pwd`

echo "To complete the installation process, you will need to provide administrative privileges." ; echo
sleep 1

########################################

echo "Installing argos3..." ; echo
install dependencies 
sudo apt-get install cmake libfreeimage-dev libfreeimageplus-dev \
  qt5-default freeglut3-dev libxi-dev libxmu-dev liblua5.3-dev \
  lua5.3 doxygen graphviz graphviz-dev asciidoc


cd argos3

mkdir build_simulator && cd build_simulator

cmake ../src

sudo make install

#compiling documentation
make doc

echo "Done." ; echo

########################################

echo "Installing krembot..." ; echo

cd $SCRIPT_PATH

cd krembot/

mkdir build && cd build

cmake ..

sudo make install

echo "Done." ; echo

########################################

echo "Compiling argos3-user..." ; echo

cd $SCRIPT_PATH

cd argos3-user/

mkdir build && cd build

cmake ..

make

echo "Done." ; echo

########################################

echo "Installation script finished" ; echo
