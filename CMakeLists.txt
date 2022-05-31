cmake_minimum_required(VERSION 3.21)
project(mtm_ex3)

set(CMAKE_CXX_STANDARD 11)

add_executable(mtm_ex3 main.cpp HealthPointsExampleTest.cpp TestMain.cpp QueueExampleTests.cpp TestUtils.h
        HealthPoints.h HealthPoints.cpp Queue.h)
#add_executable(mtm_ex3 HealthPoints.h HealthPoints.cpp Queue.h
#        UnitTests/catch.hpp UnitTests/HealthPointsUnitTests.cpp UnitTests/QueueUnitTests.cpp
#        UnitTests/relativeIncludes.h UnitTests/UnitTestsMain.cpp)
