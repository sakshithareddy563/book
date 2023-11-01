#include "menu.hpp"

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

// extern mongocxx::instance instance;
// extern mongocxx::client conn;


void login();
void student();
void read();
void issue_book();
void return_book();
void librarian();
void professor();
void add_assignments();
void add_research_papers();

