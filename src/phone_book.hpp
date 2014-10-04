#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP 1

#include <string>
#include <unordered_map>


namespace gmock_sample
{

class phone_book {
public:
	/**
	 * Checks if phone book contains any entries.
	 */
	bool empty() const;

	void insert(const std::string& name, const std::string& phone_nr);

	/**
	 * @return phone book entry count.
	 */
	size_t size() const;

	/**
	 * @return phone number of the specified contact.
	 */
	std::string get_nr(const std::string& name);

private:
	std::unordered_map<std::string, std::string> numbers_;
};

} // gmock-sample

#endif /* PHONE_BOOK_HPP */
