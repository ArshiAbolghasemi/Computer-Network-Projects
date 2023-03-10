#include "JsonService.hpp"

using namespace std;

JsonService::JsonService() {}

nlohmann::json JsonService::readFile(string filePath)
{
    ifstream file(filePath);
    return nlohmann::json::parse(file);
}

void JsonService::writeToFile(nlohmann::json document, string filePath)
{
    ofstream file(filePath);
    file << setw(4) << document << endl;
}

template<typename T>
nlohmann::json JsonService::getDocByKeyValue(nlohmann::json docs, string key, T value)
{
    for(auto doc : docs){
        if(doc[key] == value){
            return doc;           
        }
    }

    return nlohmann::json({});
}