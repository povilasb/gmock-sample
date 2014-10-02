#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "phone_book.hpp"

using namespace gmock_sample;


TEST(phone_book, is_initialy_empty)
{
	phone_book pb;

	ASSERT_TRUE(pb.empty());
}


TEST(phone_book, is_not_empty_after_item_inserted)
{
	phone_book pb;

	pb.insert("povilas", "37065316000");
	ASSERT_FALSE(pb.empty());
}
