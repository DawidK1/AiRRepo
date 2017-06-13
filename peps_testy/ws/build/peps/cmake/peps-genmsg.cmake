# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "peps: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ipeps:/home/dawid/Pulpit/peps_testy/ws/src/peps/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(peps_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg" NAME_WE)
add_custom_target(_peps_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "peps" "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg" "geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(peps
  "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/peps
)

### Generating Services

### Generating Module File
_generate_module_cpp(peps
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/peps
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(peps_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(peps_generate_messages peps_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg" NAME_WE)
add_dependencies(peps_generate_messages_cpp _peps_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(peps_gencpp)
add_dependencies(peps_gencpp peps_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS peps_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(peps
  "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/peps
)

### Generating Services

### Generating Module File
_generate_module_eus(peps
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/peps
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(peps_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(peps_generate_messages peps_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg" NAME_WE)
add_dependencies(peps_generate_messages_eus _peps_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(peps_geneus)
add_dependencies(peps_geneus peps_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS peps_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(peps
  "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/peps
)

### Generating Services

### Generating Module File
_generate_module_lisp(peps
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/peps
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(peps_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(peps_generate_messages peps_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg" NAME_WE)
add_dependencies(peps_generate_messages_lisp _peps_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(peps_genlisp)
add_dependencies(peps_genlisp peps_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS peps_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(peps
  "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/peps
)

### Generating Services

### Generating Module File
_generate_module_nodejs(peps
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/peps
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(peps_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(peps_generate_messages peps_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg" NAME_WE)
add_dependencies(peps_generate_messages_nodejs _peps_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(peps_gennodejs)
add_dependencies(peps_gennodejs peps_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS peps_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(peps
  "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/peps
)

### Generating Services

### Generating Module File
_generate_module_py(peps
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/peps
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(peps_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(peps_generate_messages peps_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dawid/Pulpit/peps_testy/ws/src/peps/msg/gps_data.msg" NAME_WE)
add_dependencies(peps_generate_messages_py _peps_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(peps_genpy)
add_dependencies(peps_genpy peps_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS peps_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/peps)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/peps
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(peps_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(peps_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/peps)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/peps
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(peps_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(peps_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/peps)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/peps
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(peps_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(peps_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/peps)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/peps
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(peps_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(peps_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/peps)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/peps\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/peps
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(peps_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(peps_generate_messages_py geometry_msgs_generate_messages_py)
endif()
