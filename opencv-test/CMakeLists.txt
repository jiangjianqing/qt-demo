cmake_minimum_required(VERSION 3.0)

#解决方案名字 
set(PROJECT_NAME testcv)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE HEADERS *.h)
source_group("Header Files" FILES ${HEADERS})
aux_source_directory(src DIR_SRCS)
#添加源文件 

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
	#添加包含的头文件（如果需要的话）  
    include_directories(${OpenCV_INCLUDE_DIRS})
    #生成exe
    add_executable(${PROJECT_NAME} ${DIR_SRCS} ${HEADERS})
    target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
endif()