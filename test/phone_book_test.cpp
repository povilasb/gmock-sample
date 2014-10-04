#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "phone_book.hpp"

using namespace gmock_sample;
using namespace ::testing;


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


TEST(phone_book, has_several_elements_after_multiple_inserts)
{
	phone_book pb;

	pb.insert("povilas", "37065316000");
	pb.insert("andrius", "37065316001");

	ASSERT_THAT(pb.size(), Gt(static_cast<size_t>(1)));
}
