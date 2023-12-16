#include "persons.hpp"
#include "menu.hpp"

void login()
{
    int designation;
    std::cout<<"login menu"<<std::endl
             <<"1.student"<<std::endl
             <<"2.librarian"<<std::endl
             <<"3.professor"<<std::endl
             <<"select your designation"<<std::endl;
    std::cin>>designation;
    if(designation==1)
    {
        student();
    }
    else if(designation==2)
    {
        librarian();
    }
    else if(designation==3)
    {
        professor();

    }

}

void student()
{
    std::cout<<"enter your details"<<std::endl;
    std::string dept;
    int id;
    std::string password;
    std::cout<<"dept: "<<std::endl;
    std::cin>>dept;
    std::cout<<"id: "<<std::endl;
    std::cin>>id;
    std::cout<<"password: "<<std::endl;
    std::cin>>password;
    std::cout<<"select your requirement"<<std::endl;
    int req;
    std::cout << std::endl
            << " 1 - issue the book/books\n"
            << " 2 - return the book/books\n"
            << " 3 - read \n"
    << " Enter your requirement : ";  
    std::cin>>req;      
    
    switch (req)
    {
        case 1:
        {
             issue_book();
        }
        break;
        case 2:
        {
             return_book();
        }
        break;
        case 3:
        {
             read();
        }
        break;
        default:
        {
            std::cout<<"invalid choice"<<std::endl;
            break;
        }
    }

}

void read()
{
    std::string database, collection;
   
    // search_book(database, collection);

}

void issue_book()
{
    std::string database; 
    std::string collection;
    // std::map<std::string,std::string> isuue_book_details = 
}

void return_book()
{

}

void librarian()
{
    std::string database;
    std::string collection;
    // mongocxx::database db = conn[database];
    // mongocxx::collection book_coll= db[collection];
    std::string password;
    std::cout<<"enter password"<<std::endl;
    std::cin>>password;
    std::cout<<"select your task"<<std::endl;
    int task;
    std::cout << std::endl
            << " 1 - delete\n"
            << " 2 - update\n"
            << " 3 - insert\n"
            << " 3 - delete student\n"


    << " Enter your task : ";  
    std::cin>>task; 

    switch (task)
    {
        case 1:
        {
            //  delete_book(database, collection);
        }
        break;
        case 2:
        {
            // update_book(database, collection);
        }
        break;
        case 3:
        {
            void insert_book_data(book* ptr, std::string db, std::string coll);
        }
        break;
        default:
        {
            std::cout<<"invalid choice"<<std::endl;
            break;
        }
    }     
}

void add_assignments()
{
    std::string database; std::string collection;
    // mongocxx::database db = conn[database];
    // mongocxx::collection assign_coll= db[collection];

}

void add_research_papers()
{
    std::string database; std::string collection;
    // mongocxx::database db = conn[database];
    // mongocxx::collection papers_coll= db[collection];

}

void professor()
{
    int id;
    std::string password;
    std::cout<<"enter id"<<std::endl;
    std::cin>>id;
    std::cout<<"enter password"<<std::endl;
    std::cin>>password;
    int task;
    std::cout << std::endl
            << " 1 - add assignments\n"
            << " 2 - add research papers\n"
            // << " 3 - \n"
            // << " 3 - delete student\n"


    << " Enter your task : ";  
    std::cin>>task; 
    switch (task)
    {
        case 1:
        {
            add_assignments();
        }
        break;
        case 2:
        {
            add_research_papers();
        }
        break;
        default:
        {
            std::cout<<"invalid choice"<<std::endl;
            break;
        }
    }        
}








