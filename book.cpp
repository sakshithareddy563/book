#include "book.hpp"
#include <iostream>
#include <string>

    int book::books_cnt = 0;;
    void book::book_increment()
    {
        books_cnt++;
    }

    book::book()
    {
        std::cout<<"default constr called"<<std::endl;
        book_increment();
    }
    
    book::~book()
    {
        books_cnt--;
    }
    
    int book:: get_page_count()
    {
        return page_count;
    }

    book::book(std::string n, std::string a, int p, int c)
    { 
        
        std::cout<<"param constr called"<<std::endl;
        this->name=n;
        this->author=a;
        this->page_count=p;
        this->word_count=c;
        book_increment();
    }

    book::book(book&& temp_book)
    {
        std::cout<<"move contructor called"<<std::endl;
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
        book_increment();
    }


    void book::book_replace_book(book& temp_book)
    {
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
    }

    void book::fetch_details() const
    {
        std::cout<<"Displaying the Book"<<std::endl
        <<"\tName: "<<name<<std::endl
        <<"\tAuthor Name: "<<author<<std::endl
        <<"\tHas "<<page_count<<" pages"<<std::endl
        <<"\tHas "<<word_count<<" words"<<std::endl;
    }

    void book::rename(std::string new_name)
    {
        this->name=new_name;
    }

    void book::edit_book(std::string new_name, std::string a, int p1, int w1)
    { 
        this->name=new_name;
        this->author=a;
        this->page_count=p1;
        this->word_count=w1;
    }

    void book::merge_book(const book& second_book)
    {
        this->name += (" "+second_book.name);
        this->author += (" "+second_book.author);
        this->page_count += second_book.page_count;
        this->word_count += second_book.word_count;
        second_book.~book();
    }

    void book::operator+=(const book& second_book)                  
    {
        this->merge_book(second_book);
    }

    bool book::operator==(const book& temp_book)
    {
        if(this->page_count == temp_book.page_count)
        {
            if(this->word_count == temp_book.word_count)
            {
                if(this->author == temp_book.author)
                {
                    if(this->name == temp_book.name)
                        return true;
                }
            }
        }
        return false;
    }

    bool book::operator!=(const book& temp_book)
    {
        return !((*this)==temp_book);
    }

    void book::operator=(const book& temp_book)
    {
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
    }
       
    book::book(const book& temp_book )
    {
        std::cout<<"copy constr called"<<std::endl;
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
    }

    void book::delete_book()
    {
        this->~book();
    }

    int book::book_count()
    {
        return books_cnt;
    }

  


    


   



