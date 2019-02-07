#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
    std::unordered_map<std::string,int> mymap;

    mymap.emplace("hello", 1);
    mymap.emplace("world", 2);
    mymap.emplace("this", 3);
    mymap.emplace("is", 4);
    mymap.emplace("HashTable", 4);

    std::unordered_map<std::string,int>::const_iterator got = mymap.find ("hello");

    if ( got == mymap.end() )
        std::cout << "not found";
    else
        std::cout << got->first << " is " << got->second;

    got = mymap.find ("hollo");
    if ( got == mymap.end() )
        std::cout << "not found";
    else
        std::cout << got->first << " is " << got->second;

  return 0;
}