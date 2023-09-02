#include <iostream>
#include<string>
#include "book.hpp"
using namespace std;


int main()
{
    
    book* b1 = book::createBook("maths", "john",10,100);
    b1->fetch_details();
    book* b2 = book::CreateDefaultBook();
    b2->fetch_details();
    book* b3 = book::CreateCopyBook(b1);
    b3->fetch_details();
   
}
