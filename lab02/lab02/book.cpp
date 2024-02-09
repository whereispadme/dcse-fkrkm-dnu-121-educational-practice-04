#include "book.h"

Book::Book()
{

	this->typeOfBooks = "";

}

Book::Book(std::string typeOfBooks)
{
	this->typeOfBooks = typeOfBooks;
}

Book::~Book()
{
}

void Book::setDataBook(std::string typeOfBooks)
{
	this->typeOfBooks = typeOfBooks;
}

std::string Book::getDataBook()
{
	return this->typeOfBooks;
}
