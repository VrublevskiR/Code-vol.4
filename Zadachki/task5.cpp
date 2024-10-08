#include <iostream>
#include <vector>
#include <algorithm>

struct Book
{
    unsigned long int id;
    unsigned int pages;
    unsigned long int color;
    unsigned int hindex;
    float h, w;
};

bool first_bigger_for_scientist(Book a, Book b)
{
    if (a.hindex > b.hindex)
        return true;
    else if (a.hindex == b.hindex && a.pages > b.pages)
        return true;
    else
        return false;
}

bool first_bigger_for_designer(Book a, Book b)
{
    if (a.color > b.color)
        return true;
    else if (a.color == b.color && a.h > b.h - 0.01)
        return true;
    else
        return false;
}

int main()
{
    std::vector<Book> books;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        Book book;
        std::cin >> book.id >> book.pages >> book.color >> book.hindex >> book.h >> book.w;
        books.push_back(book);
    }

    std::sort(books.begin(), books.end(), first_bigger_for_scientist);

    int gray_hairs = 1;
    for (int i = 1; i < n; i++)
    {
        if (first_bigger_for_designer(books[i - 1], books[i]))
            gray_hairs++;
    }

    std::cout << gray_hairs << std::endl;

    return 0;
}