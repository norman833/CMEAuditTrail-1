cmake_minimum_required(VERSION 3.8)
project(CMEAuditTrail)

set(CMAKE_CXX_STANDARD 11)
message("CMAKE_SOURCE_DIR is " ${CMAKE_SOURCE_DIR} )
find_library(QuickFix_LIB quickfix)

message(STATUS "QuickFix_LIB is " ${QuickFix_LIB})


set(SOURCE_FILES main.cpp)
add_executable(CMEAuditTrail ${SOURCE_FILES})

target_link_libraries(CMEAuditTrail ${QuickFix_LIB})