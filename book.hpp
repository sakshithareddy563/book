#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>

class book
{
    private:
        static int books_cnt;
        std::string name = "default";
        std::string author = "default";
        int page_count = 0;
        int word_count = 0;
        void book_increment();

    public:
        book();
        book(const book& temp_book );
        book(std::string n, std::string a, int p, int c);
        ~book();
        int get_page_count();
        book(book&& temp_book);
        void book_replace_book(book& temp_book);
        void fetch_details() const;
        void rename(std::string new_name);
        void edit_book(std::string new_name, std::string a, int p1, int w1);
        void merge_book(const book& second_book);
        void operator+=(const book& second_book);
        bool operator==(const book& temp_book);
        bool operator!=(const book& temp_book);
        void operator=(const book& temp_book);
        static int book_count();
        void delete_book();
};



        





#endif
