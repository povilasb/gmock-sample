#include "phone_book.hpp"

namespace gmock_sample
{

bool
phone_book::empty() const
{
	return this->size_ == 0;
}


void
phone_book::insert(const std::string& name, const std::string& phone_nr)
{
	(void)name;
	(void)phone_nr;

	++this->size_;
}


size_t
phone_book::size() const
{
	return this->size_;
}


std::string
phone_book::get_nr(const std::string& name)
{
	(void)name;
	return "37065316001";
}

}
