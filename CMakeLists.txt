cmake_minimum_required(VERSION 3.0.0)
project(linal VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable( linal main.cpp Vector3D.h  Matrix3D.h Vector3D.cpp Matrix3D.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
