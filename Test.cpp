/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Shahar
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

    CHECK(nospaces(mat(9, 7, '-', '@')) != nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                     "@-----------@\n"
                                                     "@-@@@@@@@@@-@\n"
                                                     "@-----------@\n"
                                                     "@@@@@@@@@@@@@"));
   
    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$$$"));

    CHECK(nospaces(mat(5, 3, '$', '+')) == nospaces("$$$$$$\n"
                                                    "$++++$\n"
                                                    "$$$$$"));

    CHECK(nospaces(mat(1, 1, '#', '(')) == nospaces("#"));

    CHECK(nospaces(mat(1, 3, '#', '(')) == nospaces("#\n"
                                                    "#\n"
                                                    "#"));

    CHECK(nospaces(mat(3, 1, '#', '(')) == nospaces("###"));                                             
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(5, 10, '@', '-'));
    CHECK_THROWS(mat(-3, 3, '@', '-'));
    CHECK_THROWS(mat(3, -3, '@', '-'));
    CHECK_THROWS(mat(3, 7, '$', ' '));
    CHECK_THROWS(mat(3, 7, ' ', '$'));
    CHECK_THROWS(mat(3, 7, '$', '\n'));
    CHECK_THROWS(mat(3, 7, '\n', '$'));
    CHECK_THROWS(mat(3, 7, '$', '\t'));
    CHECK_THROWS(mat(3, 7, '\t', '$'));
    CHECK_THROWS(mat(0, 5, '$', '%'));
    CHECK_THROWS(mat(5, 0, '$', '%'));
}
