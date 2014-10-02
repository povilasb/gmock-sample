#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "phone_book.hpp"

using namespace gmock_sample;


TEST(phone_book, is_initialy_empty)
{
	phone_book pb;

	ASSERT_TRUE(pb.empty());
}
