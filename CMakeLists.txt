cmake_minimum_required( VERSION 3.16.4 )
project( FileParser VERSION 0 )

# target
add_executable( fileParser ./src/main.cpp ./src/JsonParser.cpp ./src/JsonObject.cpp ./src/Bool.cpp ./src/String.cpp ./src/Value.cpp ./src/Null.cpp )

configure_file( ${CMAKE_PROJECT_NAME}Config.hpp.in ../src/${CMAKE_PROJECT_NAME}Config.hpp )

# flags
set_property( TARGET fileParser PROPERTY CXX_STANDARD 17 )
set_property( TARGET fileParser PROPERTY CXX_STANDARD_REQUIRED True )
if (CMAKE_CXX_COMPILER_ID STREQUAL \"Clang\")
	target_compile_options( fileParser -Wall -Wextra -Werror )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL \"GNU\")
  target_compile_options( fileParser PUBLIC -Wall -Wextra -Werror -Wctor-dtor-privacy -Wno-init-list-lifetime -Wnoexcept -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wtemplates -fcallgraph-info)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL \"Intel\")
#	target_compile_options( fileParser -Wall -Wextra -Werror )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL \"MSVC\")
#	target_compile_options( fileParser -Wall -Wextra -Werror )
endif()

# include files
target_include_directories( fileParser PUBLIC ${PROJECT_BINARY_DIR} ./include ./src )

# 3rd party libs

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
