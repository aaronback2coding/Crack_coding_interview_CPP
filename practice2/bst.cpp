#include <iostream>
#include <queue> 
#include <stack> 


class Node
{
public:
    int val;
    Node * left = 0;
    Node * right = 0;

};

class BST
{
public:
    Node * root = 0;
    void print();
    void insert (int ele);
};

// use queu to do breadth based BST traversal
void BST::print()
{
    Node * p = root;
    std::queue<Node*> que;
    if(p!=0)
        que.push(p);
    while (!que.empty())
    {
        Node* it = que.front();
        que.pop();
        if (it!=0)
        {
            std::cout << it->val << "\n";
            if(it->left!=0)
                que.push(it->left);
            if(it->right!=0)
                que.push(it->right);
        }
    }
    return;
}

// BST insert - no need to use queue or stack.
void BST::insert(int ele)
{
    // locate
    Node* it = root;
    Node* target = 0;
    bool LeftOrRight = true;
    
    while(it !=0)
    {
        target = it; 
        if(it->val >= ele)
        {
            it = it->left;
            LeftOrRight = true;
        }
        else
        {
            it = it->right;
            LeftOrRight = false;
        }       
    }

    //create node
    Node* newNode = new Node();
    newNode->val = ele;
    
    //insert
    if(target ==0)
        root = newNode;
    else
    {
        if(LeftOrRight == true)
            target->left = newNode;
        else
            target->right = newNode;  
    }
}



int main() {
    BST tree;
    tree.insert(8);
  
    tree.insert(4);
  
    tree.insert(11);
  
    tree.insert(5);
  
    tree.insert(1);

    tree.insert(13);

    tree.print();
    
    return 0;
    
}
