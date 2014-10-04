#include "notification_manager.hpp"


namespace gmock_sample
{

bool
notification_manager::has_notifications() const
{
	return has_notifications_;
}


void
notification_manager::add(const std::string& notification)
{
	(void)notification;
	this->has_notifications_ = true;
	++this->notification_count_;
}


std::size_t
notification_manager::notification_count() const
{
	return this->notification_count_;
}

} // gmock_sample.
