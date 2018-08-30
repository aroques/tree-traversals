#include <iostream>
#include <vector>

struct node
{
    char key;
    std::vector<std::string> values;
    node* left;
    node* right;
};
