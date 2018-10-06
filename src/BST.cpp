#include <iostream>
#include <fstream>
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
void BST::traversePreorder(std::ofstream& file)
{
    if (this->root != NULL)
    {
        print_node(this->root, "", file);

        preorder(this->root->left, "", file);
        
        preorder(this->root->right, "", file);
    }
}

// Public non-recursive print_inorder
void BST::traverseInorder(std::ofstream& file)
{
    if (this->root != NULL)
    {
        inorder(this->root->left, "", file);
        
        print_node(this->root, "", file);
        
        inorder(this->root->right, "", file);
    }
}

// Public non-recursive print_postorder
void BST::traversePostorder(std::ofstream& file)
{
    if (this->root != NULL)
    {
        postorder(this->root->left, "", file);

        postorder(this->root->right, "", file);
        
        print_node(this->root, "", file);
        
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
void BST::preorder(struct Node *n, std::string indentation, std::ofstream& file)
{
    if (n != NULL)
    {
        print_node(n, indentation, file);

        preorder(n->left, indentation += this->indentation_amt, file);        

        preorder(n->right, indentation += this->indentation_amt, file);
    }
}

// Private recursive inorder traversal
void BST::inorder(struct Node *n, std::string indentation, std::ofstream& file)
{
    if (n != NULL)
    {
        inorder(n->left, indentation += this->indentation_amt, file);
        
        print_node(n, indentation, file);

        inorder(n->right, indentation += this->indentation_amt, file);
    }
}

// Private recursive postorder traversal
void BST::postorder(struct Node *n, std::string indentation, std::ofstream& file)
{
    if (n != NULL)
    {
        postorder(n->left, indentation += this->indentation_amt, file);
        
        postorder(n->right, indentation += this->indentation_amt, file);

        print_node(n, indentation, file);
    }
}

void BST::print_node(struct Node* n, std::string indentation, std::ofstream& file)
{
    file << indentation << n->key << std::endl;
    for (auto val : n->values)
    {
        file << indentation << val << std::endl;
    }
}