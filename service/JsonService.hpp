#ifndef __JSON_SERVICE_HPP
#define __JSON_SERVICE_HPP

#include <fstream>
#include "../lib/json/json.hpp"

using namespace std;
using json = nlohmann::json;

class JsonService
{
private:
    static JsonService* service;

    JsonService();
public:
    static JsonService* getInstance();

    JsonService(JsonService &service) = delete;

    void operator=(const JsonService &) = delete;

    json readFile(string filePath);

    void writeToFile(json document, string filePath);

    template<typename T>
    json getDocByKeyValue(json* docs, string key, T value);
    
};

JsonService* JsonService::service = nullptr;

#endif