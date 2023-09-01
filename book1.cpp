#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class book
 { 
    private:
        static int books_cnt;
        string name = "default";
        string author = "default";
        int page_count = 0;
        int word_count = 0;

    void book_increment()
    {
        books_cnt++;
    }

   public:

    book()
    {
        cout<<"default constructor called"<<endl;

    }

    
    book(string n, string a, int p, int c)
    { 
        
        cout<<"param constr called"<<endl;
        this->name=n;
        this->author=a;
        this->page_count=p;
        this->word_count=c;
        book_increment();
    }
    


         
    book(const book& temp_book )
    {
        cout<<"copy constr called"<<endl;
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
    }

   

    public:

    book(book&& temp_book)
    {
        cout<<"move contructor called"<<endl;
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
        book_increment();
        
    }

    ~book()
    {
        books_cnt--;
    }

    int get_page_count()
    {
        return page_count;
    }

    friend book createbook(const std::string& n, const std::string& a, int p, int c);
    friend void  createdefaultbook();


   
    void book_replace_book(book& temp_book)
    {
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
    }

    void fetch_details() const
    {
        cout<<"Displaying the Book"<<endl
        <<"\tName: "<<name<<endl
        <<"\tAuthor Name: "<<author<<endl
        <<"\tHas "<<page_count<<" pages"<<endl
        <<"\tHas "<<word_count<<" words"<<endl;
    }

    void rename(string new_name)
    {
        this->name=new_name;
    }

    void edit_book(string new_name, string a, int p1, int w1)
    { 
        this->name=new_name;
        this->author=a;
        this->page_count=p1;
        this->word_count=w1;
    }

    void merge_book(const book& second_book)
    {
        this->name += (" "+second_book.name);
        this->author += (" "+second_book.author);
        this->page_count += second_book.page_count;
        this->word_count += second_book.word_count;
        second_book.~book();
    }

    void operator+=(const book& second_book)                  
    {
        this->merge_book(second_book);
    }

    bool operator==(const book& temp_book)
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

    bool operator!=(const book& temp_book)
    {
        return !((*this)==temp_book);
    }

    void operator=(const book& temp_book)
    {
        this->name=temp_book.name;
        this->author=temp_book.author;
        this->page_count=temp_book.page_count;
        this->word_count=temp_book.word_count;
    }
   

    void delete_book()
    {
        this->~book();
    }

    
    
    static int book_count()
    {
        return books_cnt;
    }
};

   book createbook(const std::string& n, const std::string& a, int p, int c)
   {
    book newbook(n, a, p, c);
    return newbook;
   }

   void createdefaultbook() 
   {
    book defaultBook;
   }



int book::books_cnt=0;

int main()
{
    book* b1 =new book("maths", "john",10,100);
    b1->fetch_details();
    book* b2 = new book(*b1);
    
    
    
    

}