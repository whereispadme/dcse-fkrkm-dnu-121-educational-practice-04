#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
	Book();
	Book(std::string);
	~Book();

	void setDataBook(std::string);
	std::string getDataBook();

private:
	std::string typeOfBooks;

};

#endif // BOOK_H
