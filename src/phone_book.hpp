#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP 1

#include <string>


namespace gmock_sample
{

class phone_book {
public:
	/**
	 * Checks if phone book contains any entries.
	 */
	bool empty() const;

	void insert(const std::string& name, const std::string& phone_nr);

private:
	bool empty_{true};
};

} // gmock-sample

#endif /* PHONE_BOOK_HPP */
