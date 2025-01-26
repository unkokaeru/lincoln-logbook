/**
 * @file l01-file_handling-overview.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Reading/writing to a file in C++
 * @version 0.1.0
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief Function to write a vector of strings to a file.
 *
 * @param filename Name of the file to write to.
 * @param data Vector of strings to write to the file.
 */
void write_to_file(const std::string &filename, const std::vector<std::string> &data)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (const std::string &line : data)
    {
        file << line << std::endl;
    }

    file.close();
}

/**
 * @brief Reads a file and returns the contents as a vector of strings.
 *
 * @param filename Name of the file to read.
 * @return std::vector<std::string> Contents of the file.
 */
std::vector<std::string> read_from_file(const std::string &filename)
{
    std::vector<std::string> data;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::string line;
    while (std::getline(file, line))
    {
        data.push_back(line);
    }

    file.close();
    return data;
}

/**
 * @brief Main function to write/read to a file.
 *
 * @return int
 */
int main()
{
    std::vector<std::string> data = {
        "Hello, World!",
        "This is a test file.",
        "Writing to a file in C++ is easy.",
        "This is the last line of the file."};

    std::string filename = "output.txt";
    write_to_file(filename, data);

    std::cout << "Data written to file: " << filename << std::endl;

    std::vector<std::string> read_data = read_from_file(filename);

    std::cout << "Data read from file: " << filename << std::endl;

    for (const std::string &line : read_data)
    {
        std::cout << line << std::endl;
    }

    return 0;
}