#ifndef MENU_HPP
#define MENU_HPP
#include "database.hpp"


void search_book(std::string database, std::string collection);
std::map<std::string, std::string> update_book(std::string database, std::string collection);
std::map<std::string, std::string> delete_book(std::string database, std::string collection);

#endif