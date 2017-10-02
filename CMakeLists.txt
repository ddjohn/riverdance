cmake_minimum_required (VERSION 2.6)

project (GoldenSample)

include_directories(include)

add_library(stomp STATIC 
	src/Frame.cxx
	src/FrameFactory.cxx
	src/TcpServer.cxx
	src/TcpClient.cxx
	src/Tcp.cxx
	src/StompService.cxx
	src/Trace.cxx
)

add_executable(stompserver 
	bin/stompserver.cxx
)

target_link_libraries(stompserver 
	stomp
)

add_executable(stompclient
	bin/stompclient.cxx
)

target_link_libraries(stompclient 
	stomp
)

enable_testing()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../google ${CMAKE_CURRENT_BINARY_DIR}/google)

include_directories(../google/googletest/include)
add_compile_options(--coverage -fprofile-arcs -ftest-coverage)
add_executable(unittest 
	src/Frame.cxx
	src/FrameFactory.cxx
	test/test.cxx
	src/Trace.cxx
)
target_link_libraries(unittest 
	gtest 
	gtest_main 
	gcov) 
