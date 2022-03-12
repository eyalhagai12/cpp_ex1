/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: eyal hagai
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input")
{
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    /* 1
    @@@@@@@@@
    @-------@
    @-@@@@@-@
    @-@---@-@
    @-@@@@@-@
    @-------@
    @@@@@@@@@
    */

    CHECK(nospaces(mat(3, 7, '0', '.')) == nospaces("000\n0.0\n0.0\n0.0\n0.0\n0.0\n000"));
    /* 2
    000
    0.0
    0.0
    0.0
    0.0
    0.0
    000
    */

    CHECK(nospaces(mat(5, 5, '1', '2')) == nospaces("11111\n12221\n12121\n12221\n11111"));
    /* 3
    11111
    12221
    12121
    12221
    11111
    */

    CHECK(nospaces(mat(11, 11, 'P', '~')) == nospaces("PPPPPPPPPPP\nP~~~~~~~~~P\nP~PPPPPPP~P\nP~P~~~~~P~P\nP~P~PPP~P~P\nP~P~P~P~P~P\nP~P~PPP~P~P\nP~P~~~~~P~P\nP~PPPPPPP~P\nP~~~~~~~~~P\nPPPPPPPPPPP"));
    /* 4
    PPPPPPPPPPP
    P~~~~~~~~~P
    P~PPPPPPP~P
    P~P~~~~~P~P
    P~P~PPP~P~P
    P~P~P~P~P~P
    P~P~PPP~P~P
    P~P~~~~~P~P
    P~PPPPPPP~P
    P~~~~~~~~~P
    PPPPPPPPPPP
    */

    CHECK(nospaces(mat(1, 3, 'Y', 'N')) == nospaces("Y\nY\nY"));
    /* 5
    Y
    Y
    Y
    */

    CHECK(nospaces(mat(7, 1, 'R', '=')) == nospaces("RRRRRRR"));
    /* 6
    RRRRRRR
    */

    CHECK(nospaces(mat(3, 9, 'D', 'x')) == nospaces("DDD\nDxD\nDxD\nDxD\nDxD\nDxD\nDxD\nDxD\nDDD"));
    /* 7
     DDD
     DxD
     DxD
     DxD
     DxD
     DxD
     DxD
     DxD
     DDD
    */

    CHECK(nospaces(mat(25, 5, 'Z', '\'')) == nospaces("ZZZZZZZZZZZZZZZZZZZZZZZZZ\nZ'''''''''''''''''''''''Z\nZ'ZZZZZZZZZZZZZZZZZZZZZ'Z\nZ'''''''''''''''''''''''Z\nZZZZZZZZZZZZZZZZZZZZZZZZZ"));

    CHECK(nospaces(mat(25, 35, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@\n@-----------------------@\n@-@@@@@@@@@@@@@@@@@@@@@-@\n@-@-------------------@-@\n@-@-@@@@@@@@@@@@@@@@@-@-@\n@-@-@---------------@-@-@\n@-@-@-@@@@@@@@@@@@@-@-@-@\n@-@-@-@-----------@-@-@-@\n@-@-@-@-@@@@@@@@@-@-@-@-@\n@-@-@-@-@-------@-@-@-@-@\n@-@-@-@-@-@@@@@-@-@-@-@-@\n@-@-@-@-@-@---@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@-@-@-@-@-@-@-@\n@-@-@-@-@-@---@-@-@-@-@-@\n@-@-@-@-@-@@@@@-@-@-@-@-@\n@-@-@-@-@-------@-@-@-@-@\n@-@-@-@-@@@@@@@@@-@-@-@-@\n@-@-@-@-----------@-@-@-@\n@-@-@-@@@@@@@@@@@@@-@-@-@\n@-@-@---------------@-@-@\n@-@-@@@@@@@@@@@@@@@@@-@-@\n@-@-------------------@-@\n@-@@@@@@@@@@@@@@@@@@@@@-@\n@-----------------------@\n@@@@@@@@@@@@@@@@@@@@@@@@@"));

    CHECK(nospaces(mat(45, 17, '#', '^')) == nospaces("#############################################\n#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#\n#^#########################################^#\n#^#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#^#\n#^#^#####################################^#^#\n#^#^#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#^#^#\n#^#^#^#################################^#^#^#\n#^#^#^#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#^#^#^#\n#^#^#^#^#############################^#^#^#^#\n#^#^#^#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#^#^#^#\n#^#^#^#################################^#^#^#\n#^#^#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#^#^#\n#^#^#####################################^#^#\n#^#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#^#\n#^#########################################^#\n#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^#\n#############################################"));
}

TEST_CASE("Bad input")
{
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(3, 6, '@', '-'));
    CHECK_THROWS(mat(4, 6, '@', '-'));
    CHECK_THROWS(mat(-5, 7, '@', '-'));
    CHECK_THROWS(mat(3, -9, '@', '-'));
    CHECK_THROWS(mat(-11, -5, '@', '-'));
    CHECK_THROWS(mat(4, -3, '@', '-'));
    CHECK_THROWS(mat(-7, 8, '@', '-'));
    CHECK_THROWS(mat(-4, 5, '@', '-'));
    CHECK_THROWS(mat(7, -6, '@', '-'));
}

/* Add more test cases here */
