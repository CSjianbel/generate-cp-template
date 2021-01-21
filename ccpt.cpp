#include <iostream>
#include <fstream>
#include <sstream>

/* Get root home directory */
std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
/* Constant Path to the Template Directory and Template File */
std::string tempFile = HOME + "/bin/create-cp-template/templates/template.cpp";

bool verifyOutfilePath(std::string path);
bool has_suffix(const std::string &str, const std::string &suffix);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./ccpt [outfile.cpp]" << std::endl;
        return 1;
    }

    std::string outFilePath(argv[1]);

    if (!verifyOutfilePath(outFilePath))
    {
        std::cout << "Invalid Outfile Path: " << argv[1] << std::endl;
        return 2;
    }

    // opens the template file for reading
    std::ifstream infile(tempFile);
    if (!infile)
    {
        // Delete the outfile created when verifying...
        remove(argv[1]);
        std::cout << "Template File cannot be found or accessed...\n";
        return 3;
    } 
    std::string content = "", temp;

    // reads in the whole template file
    while (getline(infile, temp)) 
        content += temp + "\n";

    // close the file
    infile.close(); 

    // opens the new file
    std::ofstream outfile(outFilePath); 
    // write the content of template file to the new file
    outfile << content;

    // close the file
    outfile.close();

    std::cout << "Template Created on " << outFilePath << " :)" << std::endl;
}

bool has_suffix(const std::string &filepath, const std::string &file_ext)
{
    return filepath.size() >= file_ext.size() &&
           filepath.compare(filepath.size() - file_ext.size(), file_ext.size(),file_ext) == 0;
}

bool verifyOutfilePath(std::string filepath)
{
    if (!has_suffix(filepath, ".cpp"))
        return false;

    std::ofstream test(filepath);
    return test ? true : false;
}
