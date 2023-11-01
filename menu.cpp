#include "menu.hpp"
#include "database.hpp"

void search_book(std::string database, std::string collection)
{

        std::map<std::string, std::string> book_data;
        std::cout<<"search book with or "<<std::endl<<"delete book or " <<std::endl<<"update book"<<std::endl;
        int choice;
            std::cout << std::endl
            << " 1 - name\n"
            << " 2 - author\n"
            << " 3 - uuid\n"
            << " 4 - dept\n"
            << " 5 - delete book\n"
            << " 6 - update book\n"

            << " Enter your choice : ";
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    std::string name;
                    std::cout<<"enter book name ";
                    std::cin>>name;
                    book_data = search_by_choice("name", name, database, collection);
                } 
                break;
                case 2:
                {
                    std::string author;
                    std::cout<<"enter author name ";
                    std::cin>>author;
                    book_data = search_by_choice("author",author, database, collection);
                }  
                break; 
                case 3:
                {
                    std::string uuid;
                    std::cout<<"enter uuid";
                    std::cin>>uuid;
                    book_data = search_by_choice("uuid",uuid, database, collection);
                } 
                break;
                case 4:
                {
                    std::string dept;
                    std::cout<<"enter dept";
                    std::cin>>dept;
                     book_data = search_by_choice("dept",dept, database, collection);
                }
                break;
                case 5:
                {
                    // std::string key;
                    // std::string value;
                    // std::cin>>value;
                    delete_book(database,collection);
                }
                break;
                case 6:
                {
                    // std::string key;
                    // std::string value;
                    // std::cin>>value;
                    //  book_data = update_book(database,collection);
                }
                break;
                default:
                {
                    std::cout<<"invalid choice"<<std::endl;
                    break;
                }
            }
            // return book_data;


}

std::map<std::string, std::string> delete_book(std::string database, std::string collection)
{
    std::map<std::string, std::string> book_data;
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
                break;
                default:
                {
                    std::cout<<"invalid choice"<<std::endl;
                    break;
                }
            
            }
            return book_data;
}

std::map<std::string, std::string> update_book(std::string database, std::string collection)
{
     std::map<std::string, std::string> book_data;
     std::cout<<"update book with"<<std::endl;
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
                    update_by_choice("name", name, database, collection);
                } 
                break;
                case 2:
                {
                    std::string author;
                    std::cout<<"enter author name ";
                    std::cin>>author;
                    update_by_choice("author",author, database, collection);
                }  
                break; 
                case 3:
                {
                    std::string uuid;
                    std::cout<<"enter uuid";
                    std::cin>>uuid;
                    update_by_choice("uuid",uuid, database, collection);
                } 
                break;
                case 4:
                {
                    std::string dept;
                    std::cout<<"enter dept";
                    std::cin>>dept;
                   update_by_choice("dept",dept, database, collection);
                }
                default:
                {
                    std::cout<<"invalid choice"<<std::endl;
                    break;
                }
            }
            return book_data;


}
   
    

    
   
 

 
