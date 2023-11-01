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
    // void user_details(std::string database, std::string collection)
    // {
    //     std::map<std::string,std::string>users_map;
    //     std::string user_name;
    //     std::string user_dept;
    //     int user_id;
    //     int entry_time;
    //     int exit_time;
    //     std::cout<<"enter details:"<<std::endl;
    //     std::cout<<"user_name"<<std::endl;
    //     std::cin>>user_name;
    //     std::cout<<"user_dept"<<std::endl;
    //     std::cin>>user_dept;
    //     std::cout<<"user_id"<<std::endl;
    //     std::cin>>user_id;
    //     std::cout<<"entry_time"<<std::endl;
    //     std::cin>>entry_time;
    //     std::cout<<"exit_time"<<std::endl;
    //     std::cin>>exit_time;
    //     std::cout<<"write";
    //     users_map["name"] = user_name;
    //     users_map["dept"] = user_dept;
    //     users_map["id"] = std::to_string(user_id);
    //     users_map["entry_time"] = entry_time;
    //     users_map["exit_time"] = exit_time;
    //     std::cout<<"write";
    //     insert_users(users_map, database, collection);
       
        
    // }

    // void insert_users(std::map<std::string,std::string>users,std::string database, std::string collection)
    // {
    //     std::cout<<"write";
    //     mongocxx::database db = conn[database];
    //     mongocxx::collection users_coll= db[collection];
    
    //     bsoncxx::builder::stream::document users_doc;
        
    //     for(auto it = users.begin(); it!=users.end(); it++)
    //     {
    //         users_doc <<it->first <<it->second;
    //     }
    //     users_coll.insert_one(users_doc.view());


    // }

    // void print_book_data(std::string database,std::string collection)
    // {
    //     mongocxx::database db = conn[database];
    //     mongocxx::collection book_coll= db[collection];
    //     cursor cursor_all = book_coll.find({});
    //     for(auto doc : cursor_all)
    //     {
    //         std::cout << bsoncxx::to_json(doc)<<std::endl;
    //     }
       
    // }
    
    // void search_by_name(std::string name, std::string database, std::string collection)
    // {
    //     std::cout<<"abc"<<std::endl;
    //     mongocxx::database db = conn[database];
    //     mongocxx::collection book_coll= db[collection];
    //     bsoncxx::builder::stream::document filter{};
    //     filter << "name" << name;
    //     cursor c = book_coll.find(filter.view());
    //     for(auto doc : c)
    //     {
    //         std::cout << bsoncxx::to_json(doc);
    //     }
    // }
  

    // void search_by_uuid(std::string uuid, std::string database, std::string collection)
    // {
    //     mongocxx::database db = conn[database];
    //     mongocxx::collection book_coll= db[collection];
    //     bsoncxx::builder::stream::document filter{};
    //     filter << "uuid" << uuid;
    //     cursor c = book_coll.find(filter.view());
    //     for(auto doc : c)
    //     {
    //         std::cout << bsoncxx::to_json(doc);

    //     }
    // }

    // void search_by_dept(std::string dept, std::string database, std::string collection)
    // {
    //     mongocxx::database db = conn[database];
    //     mongocxx::collection book_coll= db[collection];
    //     bsoncxx::builder::stream::document filter{};
    //     filter << "dept" << dept;
    //     cursor c = book_coll.find(filter.view());
    //     for(auto doc : c)
    //     {
    //         std::cout << bsoncxx::to_json(doc);

    //     }
    // }

    // void search_book( std::string database, std::string collection)
    // {

    //     std::cout<<"search book with"<<std::endl;
    //     int choice;
    //         std::cout << std::endl
    //         << " 1 - name\n"
    //         << " 2 - author\n"
    //         << " 3 - uuid\n"
    //         << " 4 - dept\n"
    //         << " Enter your choice : ";
    //         std::cin >> choice;

    //         switch (choice)
    //         {
    //             case 1:
    //             {
    //                 std::string name;
    //                 std::cout<<"enter book name ";
        //             std::cin>>name;
        //             search_by_name(name, database, collection);4
        //             serach("name",name,db, collect)
        //         } 
        //         break;
        //         case 2:
        //         {
        //             std::string author;
        //             std::cout<<"enter author name ";
        //             std::cin>>author;
        //             search_by_author(author, database, collection);
        //         }  
        //         break; 
        //         case 3:
        //         {
        //             std::string uuid;
        //             std::cout<<"enter uuid";
        //             std::cin>>uuid;
        //             search_by_uuid(uuid, database, collection);
        //         } 
        //         break;
        //         case 4:
        //         {
        //             std::string dept;
        //             std::cout<<"enter dept";
        //             std::cin>>dept;
        //             search_by_dept(dept, database, collection);
        //         }
        //         break;
        //         default:
        //         {
        //             std::cout<<"invalid choice"<<std::endl;
        //             break;
        //         }
        //     }
        // }
   
    

    
   
 

 