#include "Node.hpp"

struct Node* new_node(std::string item)
{
    struct Node* temp =  new struct Node();
    temp->key = item.front();
    temp->values.push_back(item);
    temp->left = temp->right = NULL;

    return temp;
}

