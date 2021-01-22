#include <iostream>
#include <fstream>
#include <regex>

/* Get root home directory */
std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
/* Constant Path to the Template Directory and Template File */
std::string tempFile = HOME + "/bin/create-cp-template/templates/template.cpp";
/* Constant Path to the Template Directory and Makefile Template File */
std::string tempMakeFile = HOME + "/bin/create-cp-template/templates/Makefile";

bool verifyOutfilePath(std::string path);
bool getExtension(const std::string &str, const std::string &suffix);
std::string getFileNameFromPath(std::string path);

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

    // open template makefile
    std::ifstream makefile(tempMakeFile);
    if (!makefile)
    {
        std::cout << "Template Makefile cannot be found or accessed...";
        return 4;
    }

    // Regex pattern for replaceing the OUT var in the Makefile template
    std::regex pattern("\"FILENAME\"$");
    content = "";

    // Find the filename given a path
    std::string filename = getFileNameFromPath(outFilePath);
    // if the filename length is 0 then it is an invalid filename
    if (filename.length() == 0)
    {
        remove(argv[1]);
        std::cout << "Template File cannot be found or accessed...\n";
        return 3;
    }

    // Read in the template makefile
    while (getline(makefile, temp))
        content += std::regex_replace(temp, pattern, filename) + "\n";

    // close the file 
    makefile.close();

    std::string createdOn = outFilePath;

    // Remove the filename of the template cpp file from path
    outFilePath.erase(outFilePath.length() - 4 - filename.length(),  filename.length() + 4);

    // Create and Write to Makefile
    std::ofstream outmakefile(outFilePath + "Makefile");
    // Write content to Makefile
    outmakefile << content;

    std::cout << "Templates Created on " << createdOn << " :)" << std::endl;
}

bool getExtension(const std::string &filepath, const std::string &file_ext)
{
    return filepath.size() >= file_ext.size() &&
           filepath.compare(filepath.size() - file_ext.size(), file_ext.size(),file_ext) == 0;
}

bool verifyOutfilePath(std::string filepath)
{
    if (!getExtension(filepath, ".cpp"))
        return false;

    std::ofstream test(filepath);
    return test ? true : false;
}

std::string getFileNameFromPath(std::string path)
{
    std::string filename = "";
    for (int i = path.length() - 1; i >= 0 && path[i] != '/'; i--)
        filename = path[i] + filename;

    /* Remove '.cpp' from the filename */
    filename.erase(filename.length() - 4, 4);

    return filename;
}
