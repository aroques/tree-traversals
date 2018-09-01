#include <iostream>
#include <fstream>
#include <vector>

#include "BST.hpp"
#include "string_split.hpp"

// Prototypes
std::ifstream open_file(char* argv[]);
BST build_bst();

int main(int argc, char* argv[])
{
    std::ifstream file;

    if (argc > 2)
    {
        std::cout << "Too many arguments." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (argc == 2) // Filename provided in argv[1]
    {
        file = open_file(argv);
        // Set cin to read from file
        std::cin.rdbuf(file.rdbuf());
    }

    BST bst = build_bst();

    bst.print_preorder();
    bst.print_inorder();
    bst.print_postorder();

    if (file.is_open()) { file.close(); };

    return 0;
}

std::ifstream open_file(char* argv[])
{
    std::string filename = argv[1];
    filename += ".fs182";
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Failed to open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return file;
}

BST build_bst()
{
    BST bst;

    std::string line;
    std::vector<std::string> words;

    while (std::getline(std::cin, line))
    {
        words = split_str(line, ' ');

        for (auto word : words) { bst.insert(word); };
    }

    return bst;
}