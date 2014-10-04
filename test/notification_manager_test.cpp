#include <cstddef>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "notification_manager.hpp"


using namespace gmock_sample;
using namespace ::testing;


TEST(notification_manager_use, initialy_has_no_notifications)
{
	notification_manager nman;

	ASSERT_FALSE(nman.has_notifications());
}


TEST(notification_manager_use, has_notifications_after_add)
{
	// Given.
	notification_manager nman;

	// When.
	nman.add("Meeting at 10:00 am");

	// Then.
	ASSERT_TRUE(nman.has_notifications());
}


TEST(notification_manager_use, add_increases_notification_count)
{
	notification_manager nman;

	nman.add("Notification1");
	nman.add("Notification2");

	ASSERT_THAT(nman.notification_count(), Gt(static_cast<std::size_t>(1)));
}


TEST(notification_manager_use, dispatches_notifications_on_notify)
{
	notification_manager nman;

	ASSERT_NO_THROW(nman.notify());
	ASSERT_FALSE(nman.has_notifications());
}
