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
        search_book(database, collection);
    }

    // directly insert data in a mongodoc and insert into mongodoc
    void insert_book_data(book* ptr, std::string coll, std::string db)
    {
        std::map<std::string, std::string> data;
        data["name"] = ptr->get_name();
        data["author"] = ptr->get_author();
        data["words"] = std::to_string(ptr->get_word_count());
        data["uuid"] = ptr->get_uuid();
        data["dept"] = ptr->get_dept();
        data["page"] = std::to_string(ptr->get_page_count());
        insert_data(data, coll, db);
        // takes book data, converts to map
        // then calls insert_data and passes on the map
        // insert into db
    }


    void delete_by_choice(std::string key, std::string value,std::string database,std::string collection)
    {
        mongocxx::database db = conn[database];
        mongocxx::collection book_coll= db[collection];
        bsoncxx::builder::stream::document filter{};
        filter << key << value;
        book_coll.delete_one(filter.view());
    }

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
    std::map<std::string, std::string> search_by_choice(std::string key,std::string value, std::string database, std::string collection)
    {
        std::map<std::string, std::string> data_map;
        mongocxx::database db = conn[database];
        mongocxx::collection book_coll= db[collection];
        bsoncxx::builder::stream::document filter{};
        filter << key << value;
        cursor c = book_coll.find(filter.view());
        for(auto doc : c)
        {
            data_map["name"] = filter.view()["name"].get_utf8().value.to_string();
            data_map["author"] = filter.view()["author"].get_utf8().value.to_string();
            data_map["dept"] = filter.view()["dept"].get_utf8().value.to_string();
            data_map["uuid"] = filter.view()["uuid"].get_utf8().value.to_string();
        }
        std::cout<<data_map["name"];
        return data_map;

    }

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
   
    

    
   
 

 