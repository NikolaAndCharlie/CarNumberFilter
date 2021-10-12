cmake_minimum_required(VERSION 3.12)
project(CarNumber)

##set(APP_ICON IKD.ico)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/Debug/bin)
set(CMAKE_RUNTIME_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/Debug/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/Release/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/Release/lib)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5
    COMPONENTS
	Core
	Widgets
	Gui
	Sql
	Xml
	Concurrent
	Network
	AxContainer
	REQUIRED
)

set(Qt5_LIBS Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::Xml Qt5::Concurrent Qt5::Network Qt5::AxContainer)

file(GLOB SRCS src/*.cpp)
file(GLOB HDRS src/*.h)

message($ENV{OpenCV_DIR})
# find library
find_package(OpenCV REQUIRED)


add_executable(CarNumber WIN32)

target_sources(CarNumber
    PRIVATE
	${SRCS}
	${HDRS}
	${RC}
)

target_link_libraries(CarNumber
    ${Qt5_LIBS}
)



