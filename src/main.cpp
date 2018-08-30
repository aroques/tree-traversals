#include <iostream>
#include <fstream>

// Prototypes
std::ifstream open_file(char* argv[]);

int main(int argc, char* argv[])
{
    std::ifstream file;

    if (argc > 2)
    {
        perror("Too many arguments");
    }
    if (argc == 2) 
    {
        // Filename provided in argv[1]
        file = open_file(argv);
        std::cin.rdbuf(file.rdbuf());
    }

    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
    }    

    if (file.is_open())
    {
        file.close();
    }

    return 0;
}

std::ifstream open_file(char* argv[])
{
    std::string filename = argv[1];
    filename += ".fs182";
    std::ifstream file(filename);
    return file;
}