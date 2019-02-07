#include <iostream>
#include <stack> 



std::stack<int> ReverseStack(std::stack<int> &stk)
{
    std::stack<int> returnstk;
    while(!stk.empty())
    {
        returnstk.push(stk.top());
        stk.pop();
    }
    return returnstk;

};

std::stack<int> ReverseStack_NoDestroy(std::stack<int> &stk)
{
    std::stack<int> returnstk;
    std::stack<int> tempstk;
    
    while(!stk.empty())
    {
        returnstk.push(stk.top());
        tempstk.push(stk.top());
        stk.pop();
    }

    while(!tempstk.empty())
    {
        stk.push(tempstk.top());
        tempstk.pop();
    }

    return returnstk;

};

void RemoveEven(std::stack<int> &stk)
{
    std::stack<int> tempstk;
    int i=0;
    
    while(!stk.empty())
    {
        if((i+1)%2 == 0)
            tempstk.push(stk.top());
        stk.pop();
        i++;
    }

    while(!tempstk.empty())
    {
        stk.push(tempstk.top());
        tempstk.pop();
    }

};


int main() {

    //init stack
    std::stack<int> stk;
    for (int i = 0; i<5; i++)
        stk.push(i);

    RemoveEven(stk);

    return 0;
   
   
}
