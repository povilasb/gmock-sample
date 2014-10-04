#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "notification_manager.hpp"


using namespace gmock_sample;


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
