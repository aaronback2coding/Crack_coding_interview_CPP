#include <iostream>
#include <queue> 

bool QueueEqual(std::queue<int> & left, std::queue<int> & right)
{
    while (!left.empty() && !right.empty())
    {
        if(left.front() != left.front())
            return false;
        else
        {
            left.pop();
            right.pop();
        }
    }

    if(!left.empty() || !right.empty() )
        return false;

    return true;

}

int main() {

    //init stack
    std::queue<int> left;
    for (int i = 1; i<4; i++)
        left.push(i);

    std::queue<int> right;
    for (int i = 1; i<5; i++)
        right.push(i);

    bool eq = QueueEqual(left, right);

    return 0;
   
   
}
