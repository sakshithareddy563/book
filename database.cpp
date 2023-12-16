#include "database.hpp"
#include "book.hpp"

    mongocxx::instance instance{}; 
    mongocxx::client conn{mongocxx::uri{"mongodb://localhost:27017"}};

    void insert_data(std::map<std::string,std::string>&mp, std::string database, std::string collection)
    {
        mongocxx::database db = conn[database];
        mongocxx::collection book_coll= db[collection];
    
        bsoncxx::builder::stream::document book_doc;
        
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            book_doc <<it->first <<it->second;
        }
        book_coll.insert_one(book_doc.view());

        // print_book_data(database,collection);  
        // search_book(database, collection);
    }

    // directly insert data in a mongodoc and insert into mongodoc
    void insert_book_data(book* ptr, std::string db, std::string coll)
    {
        std::map<std::string, std::string> data;
        data["name"] = ptr->get_name();
        data["author"] = ptr->get_author();
        data["words"] = std::to_string(ptr->get_word_count());
        data["uuid"] = ptr->get_uuid();
        data["dept"] = ptr->get_dept();
        data["page"] = std::to_string(ptr->get_page_count());
        insert_data(data, db, coll);
        // takes book data, converts to map
        // then calls insert_data and passes on the map
        // insert into db
    }

    std::map<std::string, std::string> search_by_choice(std::string key,std::string value, std::string database, std::string collection)
    {
        std::cout<<"check"<<std::endl;
        std::map<std::string, std::string> data_map;
        mongocxx::database db = conn[database];
        mongocxx::collection book_coll= db[collection];
        bsoncxx::builder::stream::document filter{};
        filter << key << value;
        cursor c = book_coll.find(filter.view());
        for(auto doc : c)
        {
            data_map["name"] = doc["name"].get_utf8().value.to_string();
            data_map["author"] = doc["author"].get_utf8().value.to_string();
            data_map["dept"] = doc["dept"].get_utf8().value.to_string();
            data_map["uuid"] = doc["uuid"].get_utf8().value.to_string();
            // data_map["pages"] = doc["pages"].get_int32();
            // data_map["words"] = doc["words"].get_int32();
        }
        return data_map;

    }


    void delete_by_choice(std::string key, std::string value,std::string database,std::string collection)
    {
        // std::cout<<"abc";
        mongocxx::database db = conn[database];
        mongocxx::collection book_coll= db[collection];
        std::map<std::string, std::string> de_data = search_by_choice(key,value,database,collection);
        de_data.clear();
    
        // bsoncxx::builder::stream::document filter{};
        // filter << key << value;
        // book_coll.delete_one(filter.view());
    }

    void update_by_choice(std::string key, std::string value,std::string database,std::string collection)
    {
        mongocxx::database db = conn[database];
        mongocxx::collection book_coll= db[collection];
        std::map<std::string, std::string> up_data = search_by_choice(key,value,database,collection);
        std::string update_key; 
        std::string update_value;
        std::cin>>update_key;
        std::cin>>update_value;
        up_data[update_key] = up_data[update_value];

    }

    // void add_assignments(std::string database, std::string collection)
    // {
    //     mongocxx::database db = conn[database];
    //     mongocxx::collection assign_coll= db[collection];
    //     std::ifstream fileStream(filePath, std::ios::binary); 
    //     std::vector<char> buffer((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>()); 
    //     auto builder = bsoncxx::builder::stream::document{}; 
    //     bsoncxx::document::value doc = builder 
    //     << "title" << title 
    //     << "description" << description 
    //     << "upload_date" << bsoncxx::types::b_date{std::chrono::system_clock::now()} 
    //     << finalize; 
    //     assign_coll.insert_one(doc.view()); 


    // }
   
    

    
   
 

 