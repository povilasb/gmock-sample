#ifndef NOTIFICATION_MANAGER_HPP
#define NOTIFICATION_MANAGER_HPP 1

#include <string>
#include <cstddef>


namespace gmock_sample
{

/**
 * Notification manager accepts various notification messages, caches them
 * and dispatches on demand.
 */
class notification_manager {
public:
	bool has_notifications() const;

	void add(const std::string& notification);

	std::size_t notification_count() const;

private:
	bool has_notifications_ = false;
	std::size_t notification_count_;
};

}

#endif /* NOTIFICATION_MANAGER_HPP */
