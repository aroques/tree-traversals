#ifndef BST_HPP
#define BST_HPP

#include <fstream>

#include "Node.hpp"

class BST
{
public:
    void insert(std::string str);
    
    void traversePreorder();
    void traverseInorder();
    void traversePostorder();

    BST(std::vector<std::string> strings);

private:
    // Member variables
    struct Node* root = NULL;

    std::ofstream preorder_file;
    std::ofstream inorder_file;
    std::ofstream postorder_file;

    std::string indentation_amt = "  ";

    // Functions
    struct Node* insert(struct Node* node, std::string str);
    
    void preorder(struct Node *root, std::string indentation);
    void inorder(struct Node *root, std::string indentation);
    void postorder(struct Node *root, std::string indentation);
    
    void print_node(struct Node* n, std::string indentation, std::ofstream& file);

};

#endif // !BST_HPP