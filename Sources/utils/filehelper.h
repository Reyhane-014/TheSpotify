#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class FileHelper
{
public:
    static bool writeStringToFile(const std::string& filename, const std::string& data);
    static std::string readStringFromFile(const std::string& filename);
    static bool fileExists(const std::string& filename);
    static bool deleteFile(const std::string& filename);
    static std::vector<std::string> splitString(const std::string& str, char delimiter);
    static std::string joinString(const std::vector<std::string>& parts, char delimiter);
    static std::string encodeSpecialChars(const std::string& str);
    static std::string decodeSpecialChars(const std::string& str);
};

#endif