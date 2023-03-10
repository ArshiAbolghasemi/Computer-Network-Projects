#include "../../include/service/SPJsonService.hpp"

SPJsonService::SPJsonService() {}


nlohmann::json SPJsonService::readfile(std::string filePath)
{
    std::ifstream file(CONFIGS_PATH_PREFIX + filePath);
    return nlohmann::json::parse(file);
}

void SPJsonService::writeToFile(nlohmann::json document, std::string filePath)
{
    std::ofstream file(CONFIGS_PATH_PREFIX + filePath);
    file << std::setw(4) << document << std::endl;
}

template<typename T>
nlohmann::json SPJsonService::getDocByKeyValue(nlohmann::json docs, std::string key, T value)
{
    for(auto doc : docs){
        if(doc[key] == value){
            return doc;           
        }
    }

    return nlohmann::json({});
}