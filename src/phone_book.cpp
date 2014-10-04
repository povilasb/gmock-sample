#include "phone_book.hpp"

namespace gmock_sample
{

bool
phone_book::empty() const
{
	return this->empty_;
}


void
phone_book::insert(const std::string& name, const std::string& phone_nr)
{
	(void)name;
	(void)phone_nr;

	this->empty_ = false;
	++this->size_;
}


size_t
phone_book::size() const
{
	return this->size_;
}

}
