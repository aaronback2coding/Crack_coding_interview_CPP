#include <iostream>

class Node
{
public:
    int val;
    Node * next = 0;
};

class LinkList
{
public:
    Node * root = 0;
    void print();
    void insert (int ele);
};

void LinkList::print()
{
    Node * p = root;
    while (p!=0)
    {
        std::cout << p->val << "\n";
        p = p->next;
    }
    return;
}

void LinkList::insert(int ele)
{
    
    Node * iterator = root;
    Node * previous = 0;
    
    //find the right location
    while (iterator!=0 && iterator->val < ele)
    {
        previous = iterator;
        iterator = iterator->next;   
    }
    
    //create node, and insert    
    Node * p = new Node();
    p->val = ele;
    if (previous == 0)
    {
        root = p;
    }
    else {
        previous->next = p;
        p->next = iterator;
    }
   
    return;
}



int main() {
    // insert 1, 3, 5
    LinkList l;
    l.insert(1);
    l.insert(3);
    l.insert(5);
    l.print();
    
    // print
    // insert 4
    l.insert(4);
    l.print();
    
    // print
    
}
