#include "JsonService.hpp"

using namespace std;

JsonService::JsonService() {}

JsonService* JsonService::getInstance()
{
    if(service == nullptr){
        JsonService::service = new JsonService();
    }

    return JsonService::service;
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
json JsonService::getDocByKeyValue(json docs, string key, T value)
{
    for(auto doc : docs){
        if(doc[key] == value){
            return doc;           
        }
    }

    return json({});
}