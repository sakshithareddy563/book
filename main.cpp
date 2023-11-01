#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <string>
#include <map>
#include "book.hpp"
#include "database.hpp"
#include "menu.hpp"
#include "persons.hpp"

#include<boost/uuid/uuid.hpp>
#include<boost/uuid/uuid_generators.hpp>
#include<boost/uuid/uuid_io.hpp>

// #include <boost/log/core.hpp>
// #include <boost/log/trivial.hpp>
// #include <boost/log/expressions.hpp>
// #include <boost/log/sinks/text_file_backend.hpp>
// #include <boost/log/utility/setup/file.hpp>
// #include <boost/log/utility/setup/common_attributes.hpp>
// #include <boost/log/sources/severity_logger.hpp>
// #include <boost/log/sources/record_ostream.hpp>

// #include <bsoncxx/builder/basic/document.hpp>
// #include <bsoncxx/json.hpp>
// #include <mongocxx/client.hpp>
// #include <mongocxx/instance.hpp>
// #include <mongocxx/stdx.hpp>
// #include <mongocxx/uri.hpp>

// using bsoncxx::builder::basic::kvp;
// using bsoncxx::builder::basic::make_array;
// using bsoncxx::builder::basic::make_document;
// using namespace mongocxx;
// using namespace std;

// namespace logging = boost::log;
// namespace src = boost::log::sources;
// namespace sinks = boost::log::sinks;
// namespace keywords = boost::log::keywords;
using json = nlohmann::json;

int main(int, char*[])
{
    
    // std::ifstream config_file("config.json");
    // json data = json::parse(config_file);

    // if(!config_file.is_open())
    // {
    //     std::cout<<"failed to open"<<std::endl;
    //     return 1;
    // }

    // // nlohmann::json config;
    // config_file >> data;
    

    // std::string database = config["database"];
    // std::string collection = config["collection"];
    // int port = config["port"];

    // std::cout << "database" << database << std::endl;
    // std::cout << "collection" << collection << std::endl;
    // std::cout << "port" << port << std::endl;

    // config_file.close();


    // void init();
    // logging::add_common_attributes();

    // BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    // BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    // BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    // BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    // BOOST_LOG_TRIVIAL(error) << "An error severity message";
    // BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";


    // book* b1 = book::createBook("maths", "john",10,100,"dep1");
    // book obj;
    // std::shared_ptr<book> ptr = obj.createBook("maths", "john",10,100,"dep1");

    
    // book* b4 = book::createBook("english", "mark", 20, 200, "dep2");
    // b1->fetch_details();
    // book* b2 = book::CreateDefaultBook();
    // b2->fetch_details();
    // book* b3 = book::CreateCopyBook(b1);
    // b3->fetch_details();
    // b3->delete_book();
    // b3->edit_book("chem", "c", 10, 100,"dep3");
    login();
     
    
}