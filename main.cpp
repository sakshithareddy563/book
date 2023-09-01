#include <iostream>
#include<string>
#include "book.hpp"
using namespace std;


int main()
{
    // book b = createBook("maths", "lisa", 10, 100);
    // createDefaultBook();
    book* b1 =new book("maths", "john",10,100);
    book* b2;
    b1->fetch_details();
    
}
