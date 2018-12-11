cmake_minimum_required(VERSION 2.8.9)
project (helloworld)

macro(print_list alist)
	foreach(item ${alist})
		message("${item}")
	endforeach()
endmacro()

macro(change_list blist)
        list(APPEND ${blist} "c")
endmacro()




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

list(APPEND res_oo_list "a")
list(APPEND res_oo_list "b")

change_list(res_oo_list)
list(APPEND res_oo_list "c")

message("1====")
print_list(res_oo_list)

	foreach(item res_oo_list)
		message("${item}")
	endforeach()

message("2====")
print_list("${res_oo_list}")
	foreach(item ${res_oo_list})
		message("${item}")
	endforeach()

message("3=======")
print_list(${res_oo_list})
	foreach(item "a")
		message("${item}")
	endforeach()


add_executable(
	helloworld_cmake
	AV2.o
	helloworld.cpp
)

