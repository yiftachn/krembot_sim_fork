# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/eli/Downloads/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/eli/Downloads/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/footbot_diffusion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/footbot_diffusion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/footbot_diffusion.dir/flags.make

CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.o: CMakeFiles/footbot_diffusion.dir/flags.make
CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.o: ../footbot_diffusion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.o -c /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/footbot_diffusion.cpp

CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/footbot_diffusion.cpp > CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.i

CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/footbot_diffusion.cpp -o CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.s

CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.o: CMakeFiles/footbot_diffusion.dir/flags.make
CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.o: ../rgba_sensor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.o -c /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/rgba_sensor.cpp

CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/rgba_sensor.cpp > CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.i

CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/rgba_sensor.cpp -o CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.s

CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.o: CMakeFiles/footbot_diffusion.dir/flags.make
CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.o: ../rgb_led.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.o -c /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/rgb_led.cpp

CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/rgb_led.cpp > CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.i

CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/rgb_led.cpp -o CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.s

# Object files for target footbot_diffusion
footbot_diffusion_OBJECTS = \
"CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.o" \
"CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.o" \
"CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.o"

# External object files for target footbot_diffusion
footbot_diffusion_EXTERNAL_OBJECTS =

libfootbot_diffusion.so: CMakeFiles/footbot_diffusion.dir/footbot_diffusion.cpp.o
libfootbot_diffusion.so: CMakeFiles/footbot_diffusion.dir/rgba_sensor.cpp.o
libfootbot_diffusion.so: CMakeFiles/footbot_diffusion.dir/rgb_led.cpp.o
libfootbot_diffusion.so: CMakeFiles/footbot_diffusion.dir/build.make
libfootbot_diffusion.so: CMakeFiles/footbot_diffusion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared module libfootbot_diffusion.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/footbot_diffusion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/footbot_diffusion.dir/build: libfootbot_diffusion.so

.PHONY : CMakeFiles/footbot_diffusion.dir/build

CMakeFiles/footbot_diffusion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/footbot_diffusion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/footbot_diffusion.dir/clean

CMakeFiles/footbot_diffusion.dir/depend:
	cd /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug /home/eli/ws/krembot_sim/argos3-examples/controllers/footbot_diffusion/cmake-build-debug/CMakeFiles/footbot_diffusion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/footbot_diffusion.dir/depend
