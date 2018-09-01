#include "node.hpp"

struct node* new_node(std::string item)
{
    struct node* temp =  new struct node();
    temp->key = item.front();
    temp->values.push_back(item);
    temp->left = temp->right = NULL;

    return temp;
}

