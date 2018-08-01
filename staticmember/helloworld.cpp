#include <iostream>
#include <map>
#include <string>
#include <regex>


using namespace std;




class tracker {
    public:
        static map<string, string> UserErrorMsg;
        static void initializeUserErrorMsg();
        static void printUserErrorMsg();
};

map<string, string> tracker::UserErrorMsg;

void tracker::initializeUserErrorMsg () {

    UserErrorMsg[string("aaa")] = string("abc");
    UserErrorMsg[string("bbb")] = string("abc");
    UserErrorMsg[string("ccc")] = string("abc");
    UserErrorMsg[string("ddd")] = string("abc");

    printUserErrorMsg();

}




void tracker::printUserErrorMsg () {

    for( pair<string, string> item : UserErrorMsg ) {
         cout << item.first <<  "  " << item.second << "\n";
    }

};




int main()
{
    cout << "hellow world  \n";
    tracker::initializeUserErrorMsg();


    string teststring("Not able to find ov580 interface with serial number 0072510f14170807050000022c2400010072510f14170807050000031f1e0001s");
    string result;
    regex expr ("[0-9a-zA-Z]{20}[0-9a-zA-Z]*");
    result = regex_replace (teststring,  expr, "");

    cout <<result;




    return 0;
}