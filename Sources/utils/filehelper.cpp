#include "filehelper.h"

bool FileHelper::writeStringToFile(const std::string& filename, const std::string& data)
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << data;
    file.close();
    return true;
}

std::string FileHelper::readStringFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

bool FileHelper::fileExists(const std::string& filename)
{
    std::ifstream file(filename);
    return file.good();
}

bool FileHelper::deleteFile(const std::string& filename)
{
    if (!fileExists(filename)) {
        return false;
    }
    return std::remove(filename.c_str()) == 0;
}

std::vector<std::string> FileHelper::splitString(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    if (str.empty()) {
        return result;
    }
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    if (!str.empty() && str.back() == delimiter) {
        result.push_back("");
    }
    return result;
}

std::string FileHelper::joinString(const std::vector<std::string>& parts, char delimiter)
{
    std::string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) {
            result += delimiter;
        }
        result += parts[i];
    }
    return result;
}

std::string FileHelper::encodeSpecialChars(const std::string& str)
{
    std::string result;
    for (char c : str) {
        if (c == '|') {
            result += "\\P";
        } else if (c == '\\') {
            result += "\\B";
        } else if (c == '\n') {
            result += "\\N";
        } else if (c == '\r') {
            result += "\\R";
        } else if (c == '\t') {
            result += "\\T";
        } else {
            result += c;
        }
    }
    return result;
}

std::string FileHelper::decodeSpecialChars(const std::string& str)
{
    std::string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\\' && i + 1 < str.length()) {
            if (str[i + 1] == 'P') {
                result += '|';
                ++i;
            } else if (str[i + 1] == 'B') {
                result += '\\';
                ++i;
            } else if (str[i + 1] == 'N') {
                result += '\n';
                ++i;
            } else if (str[i + 1] == 'R') {
                result += '\r';
                ++i;
            } else if (str[i + 1] == 'T') {
                result += '\t';
                ++i;
            } else {
                result += str[i];
            }
        } else {
            result += str[i];
        }
    }
    return result;
}