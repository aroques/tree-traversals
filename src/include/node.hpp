#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

struct node
{
    char key;
    std::vector<std::string> values;
    node* left;
    node* right;
};

struct node* new_node(std::string item);

#endif // !NODE_HPP
