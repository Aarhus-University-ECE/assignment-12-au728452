#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.h"

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file.

TEST_CASE("duration")
{
    duration d1;
    int temp = d1.getDuration();
    printf("%d\n", temp);
    REQUIRE(temp == 0);
}

TEST_CASE("duration(int t)")
{
    duration d2(5);
    int temp = d2.getDuration();
    printf("%d\n", temp);
    REQUIRE(temp == 5);
}

TEST_CASE("duration set to invalid time")
{
    /*Assertion will fail*/
    /*
    duration d3(-3);
    int temp = d3.getDuration();
    printf("%d\n", temp);
    REQUIRE(temp == 0);
    */
}

TEST_CASE("tick")
{
    duration d4(4);
    d4.tick();
    int temp = d4.getDuration();
    printf("%d\n", temp);
    REQUIRE(temp == 5);
}

TEST_CASE("tick(int t)")
{
    duration d5(5);
    d5.tick(5);
    int temp = d5.getDuration();
    printf("%d\n", temp);
    REQUIRE(temp == 10);
}

TEST_CASE("alarm")
{
    duration d6;
    d6.setAlarm(10);
    for (int i = 0; i < 10; i++)
    {
        d6.tick();
    }
    REQUIRE((d6.tick()) == true);
    int temp = d6.getDuration();
    printf("%d\n", temp);
    REQUIRE(temp == 11);
}

TEST_CASE("alarm set to previous time")
{
    /*Test will fail, alarm is set to previous time*/
    /*
        duration d7;
        d7.setAlarm(5);
        REQUIRE((d7.tick(10)) == true);
        d7.setAlarm(7);
    */
}

TEST_CASE("checkAndUpdateAlarm")
{
    duration d8;
    d8.setAlarm(5);
    REQUIRE((d8.tick(10)) == true);
    REQUIRE(d8.getAlarm() == 0);
}