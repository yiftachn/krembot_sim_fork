!/bin/bash 

# this script is based on argos comilation instructions on github:
# https://github.com/ilpincy/argos3
# https://github.com/ilpincy/argos3-examples

echo "*** Installing Krembot Simulator ***" ; echo

PKG_PATH="$( cd "$(dirname "$0")" ; pwd -P )"/../..

echo "To complete the installation process, you will need to provide administrative privileges." ; echo
sleep 1

########################################

echo "Installing argos3 dependencies..." ; echo
#install dependencies 
sudo apt-get install cmake libfreeimage-dev libfreeimageplus-dev \
  qt5-default freeglut3-dev libxi-dev libxmu-dev liblua5.3-dev \
  lua5.3 doxygen graphviz graphviz-dev asciidoc

# exit if any statement returns non true result
set -e

cd $PKG_PATH/argos3


mkdir -p build_simulator && cd build_simulator

echo "Generating argos3 cmake files..." ; echo

cmake ../src

echo "Compiling argos3 from source..." ; echo

make

echo "Generating argos3 documentation..." ; echo

make doc           # documentation is required!

echo "Installing argos3 binaries..." ; echo

sudo make install

########################################

echo "Installing krembot..." ; echo

cd $PKG_PATH/krembot

mkdir -p build && cd build

echo "Generating krembot cmake files..." ; echo

cmake ..

echo "Compiling and installing krembot binaries..." ; echo

sudo make install

echo "Done." ; echo

########################################

echo "Compiling argos3-user..." ; echo

cd $PKG_PATH/argos3-user/

mkdir -p build && cd build

cmake ..

make

echo "Done." ; echo

########################################

echo "Sourcing setup_env.sh, and adding to bashrc file..."; echo
source $PKG_PATH/krembot/scripts/setup_env.sh
SETUP_COMMAND="source $PKG_PATH/krembot/scripts/setup_env.sh"
if ! grep -Fxq "$SETUP_COMMAND" ~/.bashrc
then
echo "source $PKG_PATH/krembot/scripts/setup_env.sh" >> ~/.bashrc
fi
source ~/.bashrc
echo "Done."; echo

########################################

echo "Installation script finished."; echo
