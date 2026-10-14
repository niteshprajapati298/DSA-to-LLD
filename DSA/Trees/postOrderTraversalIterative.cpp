#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
void postOrderTraversalIterative()
{
}

int main()
{
    // Root
    Node *root = new Node(1);

    // Level 2
    root->left = new Node(2);
    root->right = new Node(3);

    // Level 3
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Level 4
    root->left->left->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right->left->left = new Node(10);
    root->right->right->right = new Node(11);

    return 0;
}