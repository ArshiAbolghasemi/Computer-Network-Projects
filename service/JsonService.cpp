#include "JsonService.hpp"

JsonService::JsonService() {}

nlohmann::json JsonService::readFile(std::string filePath)
{
    std::ifstream file(filePath);
    return nlohmann::json::parse(file);
}

void JsonService::writeToFile(nlohmann::json document, std::string filePath)
{
    std::ofstream file(filePath);
    file << std::setw(4) << document << std::endl;
}

