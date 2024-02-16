/**
 * @file FileHandler.h
 * @brief This file defines the FileHandler class for reading from and writing to files.
 *
 * The FileHandler class provides functionality to read the contents of a file as a string
 * and write integer values to a file. It is a useful utility class for file I/O operations.
 */
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

/**
 * @class FileHandler
 * @brief A class for reading from and writing to files.
 */
class FileHandler
{
public:
    /**
     * @brief Read the contents of a file.
     *
     * This function reads the contents of a file and returns them as a string.
     *
     * @param filename The name of the file to be read.
     * @return The contents of the file as a string.
     */
    std::string readFromFile(const std::string&);

    /**
     * @brief Write an integer to a file.
     *
     * This function writes an integer to a file with the specified filename.
     *
     * @param filename The name of the file to which the integer will be written.
     * @param value The integer value to be written to the file.
     */
    void writeToFile(const std::string&, int);
};

#endif // FILEHANDLER_H
