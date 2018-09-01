#include <iostream>
#include <fstream>
#include <vector>

#include "BST.hpp"
#include "split_str.hpp"

// Prototypes
std::vector<std::string> get_strings_from_stdin(int argc, char* argv[]);
std::ifstream open_file(char* argv[]);
BST build_bst(std::vector<std::string> strings);

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        std::cout << "Too many arguments." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    
    std::vector<std::string> strings = get_strings_from_stdin(argc, argv);
    
    BST bst = build_bst(strings);

    bst.print_preorder();
    bst.print_inorder();
    bst.print_postorder();

    return 0;
}

std::vector<std::string> get_strings_from_stdin(int argc, char* argv[])
{
    std::vector<std::string> strings;
    std::ifstream file;

    if (argc == 2) // Filename provided in argv[1]
    {
        file = open_file(argv);
        // Set cin to read from file
        std::cin.rdbuf(file.rdbuf());
    }

    std::string line;

    std::vector<std::string> line_strings;

    while (std::getline(std::cin, line))
    {
        line_strings = split_str(line, ' ');

        for (auto str : line_strings) 
        { 
            strings.push_back(str); 
        }
    }

    if (file.is_open()) { file.close(); };

    return strings;
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

BST build_bst(std::vector<std::string> strings)
{
    BST bst;

    for (auto str : strings) { bst.insert(str); };

    return bst;
}