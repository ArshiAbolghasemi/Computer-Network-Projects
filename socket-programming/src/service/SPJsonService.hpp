#ifndef __SP_JSON_SERVICE
#define __SP_JSON_SERVICE

#include "../../../service/JsonService.hpp"
#include "../../../lib/json/json.hpp"

class SPJsonService
{
private:

public:

    const string CONFIGS_PATH_PREFIX = "../socket-programming/config/";

    SPJsonService();

    nlohmann::json readfile(string filePath);

    void writeToFile(nlohmann::json document, string filePath);
};

#endif