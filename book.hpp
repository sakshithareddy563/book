#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <iostream>
#include <map>

#include<boost/uuid/uuid.hpp>
#include<boost/uuid/uuid_generators.hpp>
#include<boost/uuid/uuid_io.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

// class Database;

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

using namespace mongocxx;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

class book
{
    private:
        std::string name = "default";
        std::string author = "default";
        std::string book_dept = "default";
        std::string uuid = "default";
        int page_count = 0;
        int word_count = 0;
        // boost::uuids::random_generator gen;
        // boost::uuids::uuid id = gen();
        book(const book& temp_book );
        book(std::string n, std::string a, int p, int c, std::string dept, std::string code);
        book(book&& temp_book);

    public:
         book();
        ~book();
        int get_page_count();
        std::shared_ptr<book> createBook(const std::string& name, const std::string& author, int pages , int words, const std::string& book_dept);
        static book* CreateDefaultBook();
        static book* CreateCopyBook(const book *temp);
        static book* CreateMoveBook(book **temp);
        book* search_book();
        void replace_book(book& temp_book);
        void fetch_details() const;
        void rename(std::string new_name);
        void edit_book(std::string new_name, std::string a, int p1, int w1, std::string dept);
        void merge_book(const book& second_book);
        void operator+=(const book& second_book);
        bool operator==(const book& temp_book);
        bool operator!=(const book& temp_book);
        void operator=(const book& temp_book);
        static int book_count();
        void delete_book();
        std::string  get_name();
        std::string get_author();
        std::string  get_uuid();
        std::string  get_dept();
        int  get_word_count();
        

};

#endif