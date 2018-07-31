#include <iostream>
#include <map>
#include <string>

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
//    tracker::printUserErrorMsg();
 //   tracker::printUserErrorMsg();

    return 0;
}