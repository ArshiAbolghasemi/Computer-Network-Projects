#ifndef __JSON_SERVICE_HPP
#define __JSON_SERVICE_HPP

#include <fstream>
#include "../lib/json/json.hpp"
class JsonService
{
private:

public:
    JsonService();

    nlohmann::json readFile(std::string filePath);

    void writeToFile(nlohmann::json document, std::string filePath);

    template<typename T>
    nlohmann::json getDocByKeyValue(nlohmann::json docs, std::string key, T value);
};

#endif