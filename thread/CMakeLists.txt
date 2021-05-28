cmake_minimum_required(VERSION 3.16)
project(Thread)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g ${CAMKE_CXX_FLAGS} -pthread")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SRC
	mythread/condition.cc
	mythread/thread.cc
	)

add_executable(join join.cc ${SRC})
add_executable(self self.cc ${SRC})
add_executable(hasht hasht.cc ${SRC})
add_executable(condtest condtest.cc ${SRC})
add_executable(timeout timeout.cc ${SRC})
add_executable(mutex_test mutex_test.cc ${SRC})
add_executable(sort sort.cc ${SRC})
add_executable(atomictest atomictest.cc ${SRC})
