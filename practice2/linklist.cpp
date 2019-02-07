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
    void insert_end (int ele);
    void sort01();
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
// insert assuming sorted.
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
//insert to the end always
void LinkList::insert_end(int ele)
{
    
    Node * iterator = root;
    Node * previous = 0;
    
    //find the right location
    while (iterator!=0 )
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
    }
    return;
}

void LinkList::sort01()
{
    //go through the list, take one out each time, put into two list
    Node* it = root;
    Node* head_0 = 0;
    Node* tail_0 = 0;
    Node* head_1 = 0;
    Node* tail_1 = 0;

    while (it !=0)
    {
        if(it->val == 0)
        {
            if (head_0 ==0)
            {
                head_0 = it;
                tail_0 = it;
            }else
            {
                tail_0->next = it;
                tail_0 = it;
            }
            
        }
        else if (it->val ==1)
        {
            if (head_1 ==0)
            {
                head_1 = it;
                tail_1 = it;
            }else
            {
                tail_1->next = it;
                tail_1 = it;
            }
        }

        Node* temp = it->next;
        it->next = 0;
        it = temp;    
    }
    //merge them together
    tail_0->next = head_1;
    

}




int main() {
    // insert 1, 3, 5
    LinkList l;
    l.insert_end(0);
    l.insert_end(1);
    l.insert_end(0);
    l.insert_end(1);
    l.print();

    l.sort01();

    l.print();
    
    
}
