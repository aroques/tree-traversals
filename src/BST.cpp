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
void BST::traversePreorder()
{
    if (this->root != NULL)
    {
        print_node(this->root, "", this->preorder_file);

        preorder(this->root->left, "");
        
        preorder(this->root->right, "");
    }
}

// Public non-recursive print_inorder
void BST::traverseInorder()
{
    if (this->root != NULL)
    {
        inorder(this->root->left, "");
        
        print_node(this->root, "", this->inorder_file);
        
        inorder(this->root->right, "");
    }
}

// Public non-recursive print_postorder
void BST::traversePostorder()
{
    if (this->root != NULL)
    {
        postorder(this->root->left, "");

        postorder(this->root->right, "");
        
        print_node(this->root, "", this->postorder_file);
        
    }
}

// Constructor
BST::BST(std::vector<std::string> strings)
{
    for (auto str : strings) { insert(str); };
    
    this->preorder_file.open("preorder.out");
    this->inorder_file.open("inorder.out");
    this->postorder_file.open("postorder.out");
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
        print_node(n, indentation, this->preorder_file);

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
        
        print_node(n, indentation, this->inorder_file);

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

        print_node(n, indentation, this->postorder_file);
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