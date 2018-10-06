#ifndef BST_HPP
#define BST_HPP

#include <fstream>

#include "Node.hpp"

class BST
{
public:
    void insert(std::string str);
    
    void traversePreorder(std::ofstream& file);
    void traverseInorder(std::ofstream& file);
    void traversePostorder(std::ofstream& file);

    BST(std::vector<std::string> strings);

private:
    // Member variables
    struct Node* root = NULL;

    std::string indentation_amt = "  ";

    // Functions
    struct Node* insert(struct Node* node, std::string str);
    
    void preorder(struct Node *root, std::string indentation, std::ofstream& file);
    void inorder(struct Node *root, std::string indentation, std::ofstream& file);
    void postorder(struct Node *root, std::string indentation, std::ofstream& file);
    
    void print_node(struct Node* n, std::string indentation, std::ofstream& file);

};

#endif // !BST_HPP