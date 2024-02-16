#include "FileHandler.h"

std::string FileHandler::readFromFile(const std::string& filename)
{
    auto fileContent = std::string{""};
    std::ifstream fin(filename);
    if (!fin) throw std::logic_error(filename + " could not be opened");
    else getline(fin,fileContent);
    fin.close();
    return fileContent;
}
void FileHandler::writeToFile(const std::string& filename,int data)
{
    std::ofstream fout(filename);
    if (!fout) throw std::logic_error(filename + " could not be opened");
    else fout << data << std::endl;
    fout.close();
}