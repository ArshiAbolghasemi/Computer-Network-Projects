#ifndef __SP_JSON_SERVICE
#define __SP_JSON_SERVICE

#include "../../../service/JsonService.hpp"
#include "../../../lib/json/json.hpp"

class SPJsonService
{
private:

public:

    const std::string CONFIGS_PATH_PREFIX = "/computer_network/socket-programming/config/";

    SPJsonService();

    nlohmann::json readfile(std::string filePath);

    void writeToFile(nlohmann::json document, std::string filePath);
};

#endif