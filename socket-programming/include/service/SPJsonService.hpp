#ifndef __SP_JSON_SERVICE
#define __SP_JSON_SERVICE

#include <fstream>
#include "../lib/json.hpp"

class SPJsonService
{
private:

public:

    const std::string CONFIGS_PATH_PREFIX = "/computer_network/socket-programming/config/";

    SPJsonService();

    nlohmann::json readfile(std::string filePath);

    void writeToFile(nlohmann::json document, std::string filePath);

    template<typename T>
    nlohmann::json getDocByKeyValue(nlohmann::json docs, std::string key, T value);
};

#endif