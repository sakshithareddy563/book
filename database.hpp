#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "book.hpp"
#include <cstdint>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <map>


// class Database
// {

    void insert_data(std::map<std::string , std::string >&data,std::string database,std::string collection);
    void insert_book_data(book* ptr, std::string db, std::string coll);
    void search_book( std::string database, std::string collection);
    // void print_book_data(std::string database,std::string collection);
    // void search_by_uuid(std::string uuid, std::string database, std::string collection);
    // void search_by_dept(std::string dept, std::string database, std::string collection);
    std::map<std::string, std::string> search_by_choice(std::string key, std::string value, std::string database, std::string collection);
    // void search_by_name(std::string name, std::string database, std::string collection);
    // void delete_book_data(std::string database,std::string collection,std::string key, std::string value);
    void update_by_choice(std::string key, std::string value,std::string database,std::string collection);
    void delete_by_choice(std::string key, std::string value,std::string database,std::string collection);
    // void user_details(std::string database, std::string collection);
    // void insert_users(std::map<std::string,std::string>users,std::string database, std::string collection);
// };

#endif