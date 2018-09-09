#include <iostream>
#include <fstream>
#include <vector>

#include "BST.hpp"
#include "split_str.hpp"

// Prototypes
void validate_argc(int argc);
std::vector<std::string> get_strings(int argc, char* argv[]);
std::ifstream open_file(char* argv[]);
std::string get_output_filename(int argc, char* argv[]);
void traverse_BST(BST& bst);

int main(int argc, char* argv[])
{
    validate_argc(argc);

    std::vector<std::string> strings = get_strings(argc, argv);

    std::string output_filename = get_output_filename(argc, argv);

    BST bst = BST(strings, output_filename);

    traverse_BST(bst);

    return 0;
}

void validate_argc(int argc)
{
    if (argc > 2)
    {
        std::cout << "Too many arguments." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

std::vector<std::string> get_strings(int argc, char* argv[])
{
    // strings will be provided by a file or by stdin
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

std::string get_output_filename(int argc, char* argv[])
{
    std::string output_filename;

    if (argc == 2)
    {
        output_filename = argv[1];
    }
    else
    {
        output_filename = "out";
    }

    return output_filename;
}

void traverse_BST(BST& bst)
{
    bst.traversePreorder();
    bst.traverseInorder();
    bst.traversePostorder();
}