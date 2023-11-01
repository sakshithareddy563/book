#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    std::ifstream config_file("config.json");
    json data = json::parse(config_file);

    if(!config_file.is_open())
    {
        std::cout<<"failed to open"<<std::endl;
        return 1;
    }

    nlohmann::json config;
    config_file >> data;
    config_file.close();
    return 0;
}