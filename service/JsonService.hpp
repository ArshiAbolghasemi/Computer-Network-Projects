#ifndef __JSON_SERVICE_HPP
#define __JSON_SERVICE_HPP

#include <fstream>
#include "../lib/json/json.hpp"

using namespace std;
class JsonService
{
private:

public:
    JsonService();

    nlohmann::json readFile(string filePath);

    void writeToFile(nlohmann::json document, string filePath);

    template<typename T>
    nlohmann::json getDocByKeyValue(nlohmann::json docs, string key, T value);
};

#endif