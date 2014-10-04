#include "phone_book.hpp"

namespace gmock_sample
{

bool
phone_book::empty() const
{
	return this->size() == 0;
}


void
phone_book::insert(const std::string& name, const std::string& phone_nr)
{
	this->numbers_[name] = phone_nr;
}


size_t
phone_book::size() const
{
	return this->numbers_.size();
}


std::string
phone_book::get_nr(const std::string& name)
{
	return this->numbers_[name];
}

}
