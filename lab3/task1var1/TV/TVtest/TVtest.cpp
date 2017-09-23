#include "stdafx.h"
#include "../TV/TVSet.h"

struct TVSetFixture
{
	CTVSet tv;
};

BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)

BOOST_AUTO_TEST_CASE(is_turned_off)
{
	BOOST_CHECK(!tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(cant_select_channel_if_tv_is_turned_off)
{
	BOOST_CHECK(!tv.SelectChannel(87));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 0);
}

BOOST_AUTO_TEST_CASE(user_turn_on_tv)
{
	tv.TurnOn();
	BOOST_CHECK(tv.IsTurnedOn());
}

struct TVSetTurnOnFixture
{
	CTVSet tv;
	turn_on{
		tv.TurnOn();
	}
};

BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetTurnOnFixture)

BOOST_AUTO_TEST_CASE(displays_channel_one)
{
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);
}

BOOST_AUTO_TEST_CASE(can_be_turned_off)
{
	tv.TurnOff();
	BOOST_CHECK(!tv.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(can_select_channel_from_1_to_99)
{
	BOOST_CHECK(tv.SelectChannel(1));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 1);

	BOOST_CHECK(tv.SelectChannel(99));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 99);

	BOOST_CHECK(tv.SelectChannel(66));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 66);

	BOOST_CHECK(!tv.SelectChannel(0));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 77);

	BOOST_CHECK(!tv.SelectChannel(777));
	BOOST_CHECK_EQUAL(tv.GetChannel(), 77);
}
BOOST_AUTO_TEST_SUITE_END()
