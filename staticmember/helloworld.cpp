#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <regex>

extern char _binary_AV2_json_start;
extern char _binary_AV2_json_end;
extern const int _binary_AV2_json_size;

using namespace std;

int main()

{
    char *p = &_binary_AV2_json_start;

    while (p != &_binary_AV2_json_end)
        putchar(*p++);

    return 0;
}
