ADD_EXECUTABLE(IterAdapter IterAdapter.cpp)

set(SRCS IterAdapter.cpp multiThread.cpp)
macro(get_pkg_name outname)
    file(TO_CMAKE_PATH ${CMAKE_CURRENT_SOURCE_DIR} _d)
    message("cmake path : ${_d}")
    set(_d ${_d}/${ARGV1})
    message("cmake path : ${_d}")
    file(RELATIVE_PATH _pth ${PROJECT_SOURCE_DIR} ${_d})
    message("Relative path : ${_pth}")
    string(REPLACE "/" "_" ${outname} "${_pth}")
endmacro()

get_pkg_name(_curpkg)
message("current pkg is : ${_curpkg}")

macro(add_pkg name corelib)
    message("Argument in add_pkg : ${ARGN}")
    message("corelib in add_pkg : ${corelib}")
    message("name in add_pkg : ${name}")
# ARGN表示多余的参数列表; name = src
    add_library(${name} OBJECT ${ARGN})
    set_property(GLOBAL APPEND PROPERTY nusmv_${corelib}_pkgs ${name})
# 可以同时叠加多个属性
    set_property(GLOBAL APPEND PROPERTY nusmv_${corelib}_pkgs ltl)
endmacro()

macro(add_pkg_lib)
    get_pkg_name(_curpkg)
    message("Total pkg name : ${_curpkg}")
    message("Total argument : ${ARGN}")
    add_pkg(${_curpkg} core ${ARGN})
endmacro()

add_pkg_lib(${SRCS})
get_property(_prop GLOBAL PROPERTY nusmv_core_pkgs)
message("property : ${_prop}")
