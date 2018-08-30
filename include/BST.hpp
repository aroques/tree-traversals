#include <iostream>

#include "node.hpp"

class BST
{
public:
    BST();
    BST(BST &&) = default;
    BST(const BST &) = default;
    BST &operator=(BST &&) = default;
    BST &operator=(const BST &) = default;
    ~BST();

private:
    node* root;

    node* insert(std::string str, node* n)
    {
        // insert a node
    }
};

BST::BST()
{
}

BST::~BST()
{
}