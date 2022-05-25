cmake_minimum_required(VERSION 3.21)
project(mtm_ex3)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtm_ex3  HealthPoints.h TestUtils.h HealthPoints.cpp HealthPointsExampleTest.cpp TestMain.cpp)
#        main.cpp  QueueExampleTests.cpp )
