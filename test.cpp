//
// Created by casde on 22.09.2021.
//

#include "Data.h"
#include "catch.hpp"
#include <cstring>

TEST_CASE("DateTime class tests", "[Square]") {
    Date a(28, 2, 2020, 23, 5, 14);
    REQUIRE(strcmp(a.GetStr(), "28/2/2020 23:5:14") == 0);
    Date b;
    REQUIRE(strcmp(b.GetStr(), "1/1/2007 0:0:0") == 0);
    Date c(b);
    REQUIRE(strcmp(b.GetStr(), c.GetStr()) == 0);

    c.Plus('y');
    REQUIRE(strcmp(c.GetStr(), "1/1/2008 0:0:0") == 0);
    c.Plus('M');
    REQUIRE(strcmp(c.GetStr(), "1/2/2008 0:0:0") == 0);
    c.Plus('d');
    REQUIRE(strcmp(c.GetStr(), "2/2/2008 0:0:0") == 0);
    c.Plus('h');
    REQUIRE(strcmp(c.GetStr(), "2/2/2008 1:0:0") == 0);
    c.Plus('m');
    REQUIRE(strcmp(c.GetStr(), "2/2/2008 1:1:0") == 0);
    c.Plus('s');
    REQUIRE(strcmp(c.GetStr(), "2/2/2008 1:1:1") == 0);

    a.Minus('y');
    REQUIRE(strcmp(a.GetStr(), "28/2/2019 23:5:14") == 0);
    a.Minus('M');
    REQUIRE(strcmp(a.GetStr(), "28/1/2019 23:5:14") == 0);
    a.Minus('d');
    REQUIRE(strcmp(a.GetStr(), "27/1/2019 23:5:14") == 0);
    a.Minus('h');
    REQUIRE(strcmp(a.GetStr(), "27/1/2019 22:5:14") == 0);
    a.Minus('m');
    REQUIRE(strcmp(a.GetStr(), "27/1/2019 22:4:14") == 0);
    a.Minus('s');
    REQUIRE(strcmp(a.GetStr(), "27/1/2019 22:4:13") == 0);

    a.SetY(1984);
    REQUIRE(strcmp(a.GetStr(), "27/1/1984 22:4:13") == 0);
    a.SetMonth(3);
    REQUIRE(strcmp(a.GetStr(), "27/3/1984 22:4:13") == 0);
    a.SetDay(15);
    REQUIRE(strcmp(a.GetStr(), "15/3/1984 22:4:13") == 0);
    a.SetH(12);
    REQUIRE(strcmp(a.GetStr(), "15/3/1984 12:4:13") == 0);
    a.SetMinute(30);
    REQUIRE(strcmp(a.GetStr(), "15/3/1984 12:30:13") == 0);
    a.SetSecond(49);
    REQUIRE(strcmp(a.GetStr(), "15/3/1984 12:30:49") == 0);
}