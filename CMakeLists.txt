PROJECT(cetoBigTable)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fPIC -pthread")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
OPTION(BUILD_TEST "build testcase" FALSE)
# include header file
INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/src/include/container/
	${CMAKE_SOURCE_DIR}/src/include/os
	${CMAKE_SOURCE_DIR}/src/include/binary
	${CMAKE_SOURCE_DIR}/src/include/mem
	${CMAKE_SOURCE_DIR}/src/include/debug
	${CMAKE_SOURCE_DIR}/src/include/tools
)

# link dir
link_directories(${CMAKE_SOURCE_DIR}/build)
# cpp file
	ADD_LIBRARY(container STATIC
		${CMAKE_SOURCE_DIR}/src/container/cetoMemTableSL.cpp
	)
	ADD_LIBRARY(binary STATIC
		${CMAKE_SOURCE_DIR}/src/binary/cetoBinData.cpp 
		${CMAKE_SOURCE_DIR}/src/binary/cetoCoding.cpp
	)

IF(BUILD_TEST)
# build testcase
ADD_SUBDIRECTORY(test)
ENDIF()
