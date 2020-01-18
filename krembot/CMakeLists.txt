
project(Krembot)

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

add_library(Krembot MODULE

		## krembot ##
		src/krembot/krembot.cpp
		src/krembot/mobile_base.cpp
		src/krembot/rgba_sensor.cpp
		src/krembot/rgb_led.cpp
		src/krembot/cbumpers.cpp
		src/krembot/battery.cpp
		src/krembot/imu_sensor.cpp
		src/krembot/utils.cpp

		## sand timer ##
		src/sand_timer/SandTimer.cpp

		## particle application ##
		src/particle_app/application.h
		src/particle_app/serial.cpp
		src/particle_app/particle_string.cpp
		src/particle_app/timing.cpp
		src/particle_app/particle_observer.cpp

		## controller ##
		src/controller/controller.cpp)

#set_target_properties(krembot PROPERTIES PUBLIC_HEADER src/krembot.h src/mobile_base.h)

# Configuration file for pkg-config
configure_file(
		${CMAKE_SOURCE_DIR}/scripts/krembot.pc.in
		${CMAKE_SOURCE_DIR}/scripts/krembot.pc
		@ONLY)

#target_include_directories(krembot PRIVATE src/)

target_link_libraries(Krembot
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)

install(TARGETS Krembot
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_SOURCE_DIR}/scripts/krembot.pc
		DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)


# Install krembot library headers straigh inside Krembot, so
# include of krembot.h is the same as real robot
file(GLOB KREMBOT_HEADERS src/*.h)
install(FILES ${KREMBOT_HEADERS} DESTINATION include/${PROJECT_NAME})

file(GLOB KREMBOT_HEADERS src/krembot/*.h)
install(FILES ${KREMBOT_HEADERS} DESTINATION include/${PROJECT_NAME}/krembot)

file(GLOB PARTICLE_HEADERS src/particle_app/*.h)
install(FILES ${PARTICLE_HEADERS} DESTINATION include/${PROJECT_NAME}/particle_app)

file(GLOB SAND_TIMER_HEADERS src/sand_timer/*.h)
install(FILES ${SAND_TIMER_HEADERS} DESTINATION include/${PROJECT_NAME}/sand_timer)

file(GLOB SAND_TIMER_HEADERS src/controller/*.h)
install(FILES ${SAND_TIMER_HEADERS} DESTINATION include/${PROJECT_NAME}/controller)

install(TARGETS Krembot
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib/Krembot
		ARCHIVE DESTINATION lib/Krembot)
