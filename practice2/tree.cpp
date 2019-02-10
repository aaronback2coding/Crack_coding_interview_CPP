#include <iostream>
#include <queue> 
#include <stack> 
#include <exception>
#include <cassert>


class Node
{
public:
    Node(int ele);
    int val;
    bool visited = false;
    bool scanned = false;
    Node * left = 0;
    Node * right = 0;

};

Node::Node(int ele)
{
    val = ele;
}

class Tree
{
public:
    Node * root = 0;
    void print();
    void depthprint();
    bool depthsearch(int ele);
};

// breadth based traversal & print.
void Tree::print()
{
    std::queue<Node*> q; 
    if(root)
        q.push(root);
    while(!q.empty())
    {
        Node * cur_node = q.front();
        q.pop();
        if(cur_node)
        {
            std::cout << cur_node->val << "\n";
            if(cur_node->left)
            {
                q.push(cur_node->left);
            }
            if(cur_node->right)
            {
                q.push(cur_node->right);
            }
        }
    }
}

// inorder traversal and print
void Tree::depthprint()
{
    std::stack<Node*> s; 
    if(root)
    {
        s.push(root);
    }
    while(!s.empty())
    {
        Node* curr_node = s.top();
        assert(curr_node);
        
        if(!curr_node->scanned && curr_node->right)
            s.push(curr_node->right);
        if(!curr_node->scanned && curr_node->left)
            s.push(curr_node->left);        
        curr_node->scanned = true;
        
        bool left_null_or_visited = false;
        bool right_null_or_visited = false;
        left_null_or_visited = (!curr_node->left) || curr_node->left->visited;
        right_null_or_visited = (!curr_node->right) || curr_node->right->visited;


        if(left_null_or_visited && right_null_or_visited)
        {
            std::cout << curr_node->val << "\n";
            curr_node->visited = true;
            s.pop();
        }
    }
}

// depth first search
bool Tree::depthsearch(int ele)
{
    return false;
}



// breadth based search

int main() {
    Node a1 = Node(1);
    Node a2 = Node(2);
    Node a3 = Node(3);
    a1.left = &a2;
    a1.right = &a3;
    
    
    Node a4 = Node(4);
    Node a5 = Node(5);
    a2.left  = &a4;
    a2.right = &a5;
      
    Node a6 = Node(6);
    Node a7 = Node(7);
    a3.left  = &a6;
    a3.right = &a7;

    Tree tr;
    tr.root = &a1;
    tr.depthprint();
    return 0;
    
}
