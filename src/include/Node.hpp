#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

struct Node
{
    char key;
    std::vector<std::string> values;
    struct Node* left;
    struct Node* right;
};

struct Node* new_node(std::string item);

#endif // !NODE_HPP
