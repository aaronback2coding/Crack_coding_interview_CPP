#include <iostream>
#include <map>
#include <string>
#include <exception>


using namespace std;




class tracker {
    public:
        static map<string, string> UserErrorMsg;
 
        static void initializeUserErrorMsg();
        static void printUserErrorMsg();

    void nonstaticfunc();
};

map<string, string> tracker::UserErrorMsg = {
    {"aaaa", "bbb"},
    {"aabaa", "bbb"},
    {"acaaa", "bbb"}

};

void tracker::initializeUserErrorMsg () {

    throw 10;
    UserErrorMsg[string("aaa")] = string("abc");
    UserErrorMsg[string("bbb")] = string("abc");
    UserErrorMsg[string("ccc")] = string("abc");
    UserErrorMsg[string("ddd")] = string("abc");

    printUserErrorMsg();

};




void tracker::printUserErrorMsg () {

    for( pair<string, string> item : UserErrorMsg ) {
         cout << item.first <<  "  " << item.second << "\n";
    }

};

void tracker::nonstaticfunc()
{
    void initializeUserErrorMsg();
}







int main()
{
        cout << "before throw\n";
        
//        tracker::initializeUserErrorMsg();
//        throw 10;

        tracker tra;
        tra.nonstaticfunc();


        try {

            cout << "try really, really hard  \n";
            throw 10;
    
        } 
        catch (exception & e)
        {
            cout << "I can catch without a try" << '\n';
        }


        cout << "after throw";

}


 /*   

 {
    cout << "hellow world  \n";
    try {

        cout << "try really, really hard  \n";
    //    throw 10;
    
    } 

//    throw 11;

    
    catch (int a)
    {
        cout << a << '\n';
    }
    

    try {
         tracker::initializeUserErrorMsg();

    }   
        
    catch (int b)
    {
        cout << b << '\n';
    }
    

    return 0;
}

*/