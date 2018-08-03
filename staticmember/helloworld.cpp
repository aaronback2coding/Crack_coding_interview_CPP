#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <regex>

using namespace std;

class tracker
{
  public:
    static map<string, string> MsgMap;

    static string replaceString(string oldstring);
};

map<string, string> tracker::MsgMap = {
    {"Not able to find ov580 interface with serial number.*",
     "please re-plug your USB cable"}};

string tracker::replaceString(string oldstring)
{
    for (auto item : MsgMap)
    {
        regex expr(item.first);
        if (regex_match(oldstring, expr))
            return item.second;
    }
    return oldstring;
};

int main()

{
    string teststring("Not able to find ov580 interface with serial number 0072510f14170807050000022c2400010072510f14170807050000031f1e0001s");

    string resultstring = tracker::replaceString(teststring);

    string teststring2("222Not able to find ov580 interface with serial number 0072510f14170807050000022c2400010072510f14170807050000031f1e0001s");
    string resultstring2 = tracker::replaceString(teststring2);
    return 0;
}
