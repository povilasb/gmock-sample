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
}

} // gmock_sample.
