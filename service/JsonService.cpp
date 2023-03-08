#include "JsonService.hpp"

using namespace std;

JsonService* JsonService::getInstance()
{
    if(service == nullptr){
        service = new JsonService();
    }

    return service;
}

json JsonService::readFile(string filePath)
{
    ifstream file(filePath);
    return json::parse(file);
}

void JsonService::writeToFile(json document, string filePath)
{
    ofstream file(filePath);
    file << setw(4) << document << endl;
}

template<typename T>
json JsonService::getDocByKeyValue(json* docs, string key, T value)
{
    for(auto it = docs->begin(); it != docs->end(); ++it){
        if((*it)[key] == value){
            return *it;
        }
    }
}