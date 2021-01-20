#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

/* Constant Path to the Template Directory and Template File */
std::string tempFile = "./templates/template.cpp";

bool verifyOutfilePath(char *path);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./ccpt [outfile.cpp]" << std::endl;
        return 1;
    }

    std::ifstream infile(tempFile); // opens the template file for reading
    std::string content = "", temp;

    while (getline(infile, temp)) // reads in the whole template file
        content += temp + "\n";

    infile.close(); // close the file

    std::ofstream outfile(argv[1]); // opens the new file
    outfile << content; // write the content of template file to the new file

    outfile.close(); // close the file
}

bool verifyOutfilePath(char *path)
{
    return true;
}
