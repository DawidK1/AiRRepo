# Install script for directory: /home/dawid/Pulpit/kuka/src/kuka_experimental/kuka_rsi_simulator

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dawid/Pulpit/kuka/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/dawid/Pulpit/kuka/build/kuka_experimental/kuka_rsi_simulator/catkin_generated/installspace/kuka_rsi_simulator.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kuka_rsi_simulator/cmake" TYPE FILE FILES
    "/home/dawid/Pulpit/kuka/build/kuka_experimental/kuka_rsi_simulator/catkin_generated/installspace/kuka_rsi_simulatorConfig.cmake"
    "/home/dawid/Pulpit/kuka/build/kuka_experimental/kuka_rsi_simulator/catkin_generated/installspace/kuka_rsi_simulatorConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kuka_rsi_simulator" TYPE FILE FILES "/home/dawid/Pulpit/kuka/src/kuka_experimental/kuka_rsi_simulator/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kuka_rsi_simulator/scripts" TYPE PROGRAM FILES "/home/dawid/Pulpit/kuka/src/kuka_experimental/kuka_rsi_simulator/scripts/kuka_rsi_simulator")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kuka_rsi_simulator" TYPE DIRECTORY FILES "/home/dawid/Pulpit/kuka/src/kuka_experimental/kuka_rsi_simulator/launch")
endif()

