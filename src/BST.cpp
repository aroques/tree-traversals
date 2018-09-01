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
BST::BST()
{
    this->root = NULL;
}

// Destructor
BST::~BST()
{

}

/*
    Private
*/

// Private recursive insert
struct node* BST::insert(struct node* node, std::string str)
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
void BST::preorder(struct node *n, std::string indentation)
{
    if (n != NULL)
    {
        print_node(n, indentation);

        preorder(n->left, indentation += "  ");        

        preorder(n->right, indentation += "  ");
    }
}

// Private recursive inorder traversal
void BST::inorder(struct node *n, std::string indentation)
{
    if (n != NULL)
    {
        inorder(n->left, indentation += "  ");
        
        print_node(n, indentation);

        inorder(n->right, indentation += "  ");
    }
}

// Private recursive postorder traversal
void BST::postorder(struct node *n, std::string indentation)
{
    if (n != NULL)
    {
        postorder(n->left, indentation += "  ");
        
        postorder(n->right, indentation += "  ");

        print_node(n, indentation);
    }
}

void BST::print_node(struct node* n, std::string indentation)
{
    std::cout << indentation << n->key << std::endl;
    for(auto val : n->values)
    {
        std::cout << indentation << val << std::endl;
    }
}