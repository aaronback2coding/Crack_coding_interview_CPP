#include <iostream>
#include <queue> 
#include <exception>
#include <cassert>


///-------------- didn't finish my own priority queue as i think i know how to do it already

// keep 3 2 1 order. with head pointing to 3, tail pointing to 1. pop will remove tail. top will return head. push will insert into the order.
class my_pq
{
public: 
    void push(int ele);
    void pop();
    int top();
    Node * bst(int ele);
    Node * head = 0;
    Node * tail = 0;
};

class Node
{
public:
    int val;
    Node * next = 0;
};


//need to use bst to make sure we can find the element under log(k)
void my_pq::push(int ele)
{
    Node * target_before_node = bst(ele);
    
    Node * newnode = new Node();
    Node * target_after_node = 0;

    if(!target_before_node)
    {
        target_after_node = target_before_node -> next;
        target_before_node -> next = newnode;
    }
    if(!newnode)
    {
        newnode -> next = target_after_node;
    }    
}

void my_pq::pop()
{
}

///-------------- didn't finish my own priority queue as i think i know how to do it already 000000000


void TopKfromN(int na[], int ka[], int n, int k)
{
    assert (k<=n);
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    for(int i = 0; i<n; i++)
    {
        pq.push(na[i]);
        if (i >= k)
            pq.pop();
    }
    for(int i = 0; i<k; i++)
    {
        ka[i] = pq.top();
        pq.pop();
    }
}



int main() {

    //init stack
    int na[5] = {1, 2, 3, 4, 5};
    int ka[3];

    TopKfromN(na, ka, 5, 3);

    return 0;
   
   
}
