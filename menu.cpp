#include "menu.hpp"
#include "database.hpp"

void search_book( std::string database, std::string collection)
{

        std::cout<<"search book with"<<std::endl;
        int choice;
            std::cout << std::endl
            << " 1 - name\n"
            << " 2 - author\n"
            << " 3 - uuid\n"
            << " 4 - dept\n"
            << " 5 - delete book\n"
            << " Enter your choice : ";
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    std::string name;
                    std::cout<<"enter book name ";
                    std::cin>>name;
                    search_by_choice("name", name, database, collection);
                } 
                break;
                case 2:
                {
                    std::string author;
                    std::cout<<"enter author name ";
                    std::cin>>author;
                    search_by_choice("author",author, database, collection);
                }  
                break; 
                case 3:
                {
                    std::string uuid;
                    std::cout<<"enter uuid";
                    std::cin>>uuid;
                    search_by_choice("uuid",uuid, database, collection);
                } 
                break;
                case 4:
                {
                    std::string dept;
                    std::cout<<"enter dept";
                    std::cin>>dept;
                    search_by_choice("dept",dept, database, collection);
                }
                case 5:
                {
                    delete_book_choice();
                }
                break;
                default:
                {
                    std::cout<<"invalid choice"<<std::endl;
                    break;
                }
        }
}

void delete_book(std::string database, std::string collection)
{
     std::cout<<"delete book with"<<std::endl;
        int choice;
            std::cout << std::endl
            << " 1 - name\n"
            << " 2 - author\n"
            << " 3 - uuid\n"
            << " 4 - dept\n"
            << " Enter your choice : ";
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    std::string name;
                    std::cout<<"enter book name ";
                    std::cin>>name;
                    delete_by_choice("name", name, database, collection);
                } 
                break;
                case 2:
                {
                    std::string author;
                    std::cout<<"enter author name ";
                    std::cin>>author;
                    delete_by_choice("author",author, database, collection);
                }  
                break; 
                case 3:
                {
                    std::string uuid;
                    std::cout<<"enter uuid";
                    std::cin>>uuid;
                    delete_by_choice("uuid",uuid, database, collection);
                } 
                break;
                case 4:
                {
                    std::string dept;
                    std::cout<<"enter dept";
                    std::cin>>dept;
                   delete_by_choice("dept",dept, database, collection);
                }


}
   
    

    
   
 

 
