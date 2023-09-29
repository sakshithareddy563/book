
#include "book.hpp"
#include "database.hpp"


// void init()
// {
//     logging::add_file_log
//     (
//         keywords::file_name = "sample_%N.log",                                        /*< file name pattern >*/
//         keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
//         keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
//         keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
//     );

//     logging::core::get()->set_filter
//     (
//         logging::trivial::severity >= logging::trivial::info
//     );
// }


book::book()
{
   
}

book::~book()
{

}

int book:: get_word_count()
{
    return word_count;
}

int book:: get_page_count()
{
    return page_count;
}

std::string book:: get_name()
{
    return name;
}

std::string book:: get_author()
{
    return author;
}

std::string book:: get_uuid()
{
    return uuid;
}

std::string book:: get_dept()
{
    return book_dept;
}

book::book(std::string n, std::string a, int p, int c, std::string dept, std::string code)
{ 
    std::cout<<"param constr called"<<std::endl;
    this->name=n;
    this->author=a;
    this->page_count=p;
    this->word_count=c;
    this->book_dept=dept;
    boost::uuids::random_generator gen;
    boost::uuids::uuid id = gen();
    code = boost::uuids::to_string(id);
    this->uuid = code;       // convert generator() to std::string
   
}

book::book(book&& temp_book)
{
    std::cout<<"move contructor called"<<std::endl;
    this->name=temp_book.name;
    this->author=temp_book.author;
    this->page_count=temp_book.page_count;
    this->word_count=temp_book.word_count;
}

book* book::createBook(const std::string& name, const std::string& author, int pages , int words, const std::string& book_dept)
{
    boost::uuids::random_generator gen;
    boost::uuids::uuid id = gen();
    std::string code = boost::uuids::to_string(id);
    book* ptr = new book(name,author,pages,words, book_dept, code);

    // Database db;
    insert_book_data(ptr,"library","books");
    // delete ptr;
    return ptr;
}

// database function
// #niclude 'book.hpp'
// void insert_data_2(book b, std::string collection,std::string database)
// {
// mongocxx::instance inst{};
//     mongocxx::client client{mongocxx::uri{"mongodb://localhost:27017"}};
//     auto db = client["mydb"];
//     auto collection = db["my_coll"];

//     auto doc= collection.insert_one(make_document(
//     kvp("title",b.name),
//     kvp("author",b.author),
//     kvp("page_count",b.pages+1),
//     kvp("word_count",b.words),
//     kvp("dept",b.book_dept)
//     ));

// }

// // database function
// void insert_data(std::map<std::string , std::string >&m,std::string collection,std::string database)
// {
//     for(auto it = mp.begin() )
//         // take each kvp from map, add to the document
//     // at last insert the doc
// }

book* book::CreateDefaultBook()
{

}
book* book::CreateCopyBook(const book *temp)
{ 
    // boost::uuids::random_generator generator;
    // uuid = generator();
    return new book(*temp);

}
book* book::CreateMoveBook(book **temp)
{ 
    // boost::uuids::random_generator generator;
    // uuid = generator();
    return new book(**temp);

}

void book::replace_book(book& temp_book)
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

void book::edit_book(std::string new_name, std::string a, int p1, int w1, std::string dept)
{ 
    
    this->name=new_name;
    this->author=a;
    this->page_count=p1;
    this->word_count=w1;
    this->book_dept=dept;
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


// book* book::search_book()
// {
//     // std::map<int, std::string> mp;
//     std::string choice;
//     std::cout<<"search book with: "
//              <<"1.name "
//              <<"2.uuid "
//              <<"3.author "
//              <<"4.dept_name "<<std::endl;
//     std::cin>>choice;
//     if(choice==this->name || choice==this->author || choice==this->book_dept)
//     {
//         std::cout<<"book found"<<std::endl;
//     } 
//     return this;
// }

// void users_data(std::map<std::string,std::string>users,std::string name, std::string dept, int roll)
// {
//     users["name"] = name;
//     users["dept"] = dept;
//     users["roll"] = roll;

// }

