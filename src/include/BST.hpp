#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"

class BST
{
public:
    void insert(std::string str);
    
    void print_preorder();
    void print_inorder();
    void print_postorder();

private:
    // Member variables
    struct Node* root = NULL;
    std::string indentation_amt = "  ";

    // Functions
    struct Node* insert(struct Node* node, std::string str);
    
    void preorder(struct Node *root, std::string indentation);
    void inorder(struct Node *root, std::string indentation);
    void postorder(struct Node *root, std::string indentation);
    
    void print_node(struct Node* n, std::string indentation);

};

#endif // !BST_HPP