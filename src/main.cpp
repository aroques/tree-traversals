#include <iostream>
#include <fstream>
#include <vector>

#include "BST.hpp"
#include "split_str.hpp"

// Prototypes
void validate_argc(int argc);
std::vector<std::string> get_strings(int argc, char* argv[]);
void open_file(std::ifstream& file, char* argv[]);
std::string get_output_filename(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    validate_argc(argc);

    std::vector<std::string> strings = get_strings(argc, argv);

    std::string output_filename = get_output_filename(argc, argv);

    std::ofstream preorder_file(output_filename + ".preorder");
    std::ofstream inorder_file(output_filename + ".inorder");
    std::ofstream postorder_file(output_filename + ".postorder");

    BST bst = BST(strings);

    bst.traversePreorder(preorder_file);
    bst.traverseInorder(inorder_file);
    bst.traversePostorder(postorder_file);

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
        open_file(file, argv);
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

void open_file(std::ifstream& file, char* argv[])
{
    std::string filename = argv[1];
    filename += ".fs182";
    file.open(filename);

    if (!file.is_open())
    {
        std::cout << "Failed to open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
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