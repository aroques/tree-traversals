#include <iostream>
#include "BST.hpp"

/*
    Public
*/

// Public non-recursive insert
void BST::insert(std::string str)
{
    if (this->root == NULL)
    {
        this->root = new_node(str);
        return;
    }

    insert(this->root, str);

    return;
}

// Public non-recursive print_preorder
void BST::print_preorder()
{
    std::cout << "--- BST preorder ---" << std::endl;
    if (this->root != NULL)
    {
        print_node(this->root, "");

        preorder(this->root->left, "");
        
        preorder(this->root->right, "");
    }
}

// Public non-recursive print_inorder
void BST::print_inorder()
{
    std::cout << "--- BST inorder ---" << std::endl;
    if (this->root != NULL)
    {
        inorder(this->root->left, "");
        
        print_node(this->root, "");
        
        inorder(this->root->right, "");
    }
}

// Public non-recursive print_postorder
void BST::print_postorder()
{
    std::cout << "--- BST postorder ---" << std::endl;
    if (this->root != NULL)
    {
        postorder(this->root->left, "");

        postorder(this->root->right, "");
        
        print_node(this->root, "");
        
    }
}

// Constructor
BST::BST(std::vector<std::string> strings)
{
    for (auto str : strings) { insert(str); };
}

/*
    Private
*/

// Private recursive insert
struct Node* BST::insert(struct Node* node, std::string str)
{
    if (node == NULL)
    {
        return new_node(str);
    }
    
    char this_key = str.front();

    if (this_key < node->key) 
    {
        node->left  = insert(node->left, str);
    }
    else if (this_key > node->key)
    {
        node->right = insert(node->right, str);   
    }
    else  // this_key == node->key
    {
        node->values.push_back(str);
    }

    return node;

}

// Private recursive preorder traversal
void BST::preorder(struct Node *n, std::string indentation)
{
    if (n != NULL)
    {
        print_node(n, indentation);

        preorder(n->left, indentation += this->indentation_amt);        

        preorder(n->right, indentation += this->indentation_amt);
    }
}

// Private recursive inorder traversal
void BST::inorder(struct Node *n, std::string indentation)
{
    if (n != NULL)
    {
        inorder(n->left, indentation += this->indentation_amt);
        
        print_node(n, indentation);

        inorder(n->right, indentation += this->indentation_amt);
    }
}

// Private recursive postorder traversal
void BST::postorder(struct Node *n, std::string indentation)
{
    if (n != NULL)
    {
        postorder(n->left, indentation += this->indentation_amt);
        
        postorder(n->right, indentation += this->indentation_amt);

        print_node(n, indentation);
    }
}

void BST::print_node(struct Node* n, std::string indentation)
{
    std::cout << indentation << n->key << std::endl;
    for (auto val : n->values)
    {
        std::cout << indentation << val << std::endl;
    }
}