#include "SPJsonService.hpp"

SPJsonService::SPJsonService() {}


nlohmann::json SPJsonService::readfile(std::string filePath)
{
    return (new JsonService())->readFile(CONFIGS_PATH_PREFIX + filePath);
}

void SPJsonService::writeToFile(nlohmann::json document, std::string filePath)
{
    (new JsonService())->writeToFile(document, CONFIGS_PATH_PREFIX + filePath);
}