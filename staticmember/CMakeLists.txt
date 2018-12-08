cmake_minimum_required(VERSION 2.8.9)
project (helloworld)
add_custom_command(
    OUTPUT
	AV2.o
    PRE_LINK
    DEPENDS
    COMMAND
        ld -r -b binary AV2.json -o AV2.o
    COMMENT
        "Generating object file of JSON"
    VERBATIM
    )
add_executable(
	helloworld_cmake
	AV2.o
	helloworld.cpp
)

