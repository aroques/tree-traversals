#ifndef BST_HPP
#define BST_HPP

#include "node.hpp"

class BST
{
public:
    void insert(std::string str);
    
    void print_preorder();
    void print_inorder();
    void print_postorder();
    
    BST();
    ~BST();

private:
    // Member variables
    struct node* root;

    // Functions
    struct node* insert(struct node* node, std::string str);
    
    void preorder(struct node *root, std::string indentation);
    void inorder(struct node *root, std::string indentation);
    void postorder(struct node *root, std::string indentation);
    
    void print_node(struct node* n, std::string indentation);

};

#endif // !BST_HPP