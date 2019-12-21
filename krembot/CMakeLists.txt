
project(krembot)

include(GNUInstallDirs)

set (CMAKE_CXX_STANDARD 11)

# Find the ARGoS package, make sure to save the ARGoS prefix
find_package(PkgConfig)
pkg_check_modules(ARGOS REQUIRED argos3_simulator)
set(ARGOS_PREFIX ${ARGOS_PREFIX} CACHE INTERNAL "")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ARGOS_PREFIX}/share/argos3/cmake)

# Check whether all the necessary libs have been installed to compile the
# code that depends on Qt and OpenGL
include(ARGoSCheckQTOpenGL)

# Find Lua
find_package(Lua52 REQUIRED)

# Set ARGoS include dir
include_directories(${CMAKE_SOURCE_DIR} ${ARGOS_INCLUDE_DIRS} ${LUA_INCLUDE_DIR})

# Set ARGoS link dir
link_directories(${ARGOS_LIBRARY_DIRS})

add_library(krembot MODULE
		src/krembot.h
		src/mobile_base.h
		src/mobile_base.cpp
		src/rgba_sensor.cpp
		src/rgba_sensor.h
		src/rgb_led.cpp
		src/rgb_led.h
		src/cbumpers.cpp
		src/cbumpers.h
		src/battery.cpp
		src/battery.h
		src/imu_sensor.cpp
		src/imu_sensor.h
		src/utils.h
		src/krembot.cpp
		src/SandTimer.cpp
		src/SandTimer.h
		src/utils.cpp
		src/SerialSim.cpp
		src/SerialSim.h)

#set_target_properties(krembot PROPERTIES PUBLIC_HEADER src/krembot.h src/mobile_base.h)

# Configuration file for pkg-config
configure_file(
		${CMAKE_SOURCE_DIR}/scripts/krembot.pc.in
		${CMAKE_SOURCE_DIR}/scripts/krembot.pc
		@ONLY)

#target_include_directories(krembot PRIVATE src/)

target_link_libraries(krembot
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)

install(TARGETS krembot
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_SOURCE_DIR}/scripts/krembot.pc
		DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# Install library headers
file(GLOB HEADERS src/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

install(TARGETS krembot
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib/krembot
		ARCHIVE DESTINATION lib/krembot)
