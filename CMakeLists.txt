cmake_minimum_required(VERSION 3.0)

project(QtCV LANGUAGES CXX)

#### Environment
if (UNIX AND NOT APPLE) #Ubuntu...
    message(STATUS ">>> Linux")

    set(OpenCV_LIBS /usr/local/lib)
    set(OpenCV_INCLUDE_DIRS /usr/local/include)

    include_directories(/usr/include)
    link_directories(/usr/lib/x86_64-linux-gnu)

else(APPLE)
    message(STATUS ">>> Mac")
        
    # If you installed Qt with homebrew and 'brew link --force qt5', you don't have to set QTDIR for find_package
    # set(QTDIR /usr/local/Cellar/qt/5.10.0_1)
    # set(CMAKE_PREFIX_PATH ${QTDIR})  
        
    set(OpenCV_DIR /Users/mhirano/opencv-3.2.0/build)

    # Add include directory	(environemt specific)
    include_directories(/usr/local/include)

    # Add library directory	
    # link_directories(/usr/local/Cellar/fftw/3.3.6-pl2/lib) # fftw3 via homebrew
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


######## ######## ######## ######## ######## ######## ######## ########
# Additional Libraries
######## ######## ######## ######## ######## ######## ######## ########

# Create a variable that contains libraries to be used
# When you add libraries, append them to the tail of 'accel_lib'
set(lib_list "")

# Qt
find_package( Qt5 COMPONENTS Quick Core Gui Concurrent REQUIRED)
qt5_add_resources(QT_RESOURCES resource.qrc)

set(lib_list
        "${lib_list};Qt5::Core;Qt5::Quick;Qt5::Gui;Qt5::Concurrent"
        )

# OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include )

set(lib_list
        "${lib_list};${OpenCV_LIBS}"
        )
######## ######## ######## ######## ######## ######## ######## ########



######## ######## ######## ######## ######## ######## ######## ########
# Compiler settings
######## ######## ######## ######## ######## ######## ######## ########
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g -pg")
message(STATUS "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DRELEASE -O3 -DNDEBUG")
message(STATUS "${CMAKE_CXX_FLAGS_RELEASE}")
######## ######## ######## ######## ######## ######## ######## ########

set( src_list
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        src/ImageProvider.cpp include/ImageProvider.h src/Application.cpp include/Application.h)

message(STATUS "Linked libraries: ${accel_lib}")

add_executable( ${PROJECT_NAME} ${src_list} ${QT_RESOURCES})

target_link_libraries( ${PROJECT_NAME} ${lib_list})
