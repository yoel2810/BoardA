#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
#include <string>
#include <algorithm>

using namespace ariel;
using namespace std;

Board* bo = new Board();

TEST_CASE("wrong input - post")
{
    CHECK_THROWS(bo->post(505, 600, ariel::Direction::Vertical,"123"));
    CHECK_THROWS(bo->post(505, 600, ariel::Direction::Horizontal,"123"));
    CHECK_THROWS(bo->post(2, 600, ariel::Direction::Horizontal,"123"));
    CHECK_THROWS(bo->post(600, 2, ariel::Direction::Horizontal,"123"));
    CHECK_THROWS(bo->post(5, 499, ariel::Direction::Horizontal,"123"));
    CHECK_THROWS(bo->post(495, 5, ariel::Direction::Vertical,"0126456789564321"));
    
}

TEST_CASE("wrong input - read")
{
    CHECK_THROWS(bo->read(501, 654, ariel::Direction::Horizontal, 1));
    CHECK_THROWS(bo->read(501, 654, ariel::Direction::Vertical, 1));
    CHECK_THROWS(bo->read(2, 600, ariel::Direction::Horizontal,1));
    CHECK_THROWS(bo->read(600, 2, ariel::Direction::Horizontal,1));
    CHECK_THROWS(bo->read(497, 2, ariel::Direction::Vertical,8));
    CHECK_THROWS(bo->read(5, 499, ariel::Direction::Horizontal,11));
}

TEST_CASE("checking board")
{
    bo->post(5,5,ariel::Direction::Horizontal, "hello");
    CHECK(bo->read(5,5, ariel::Direction::Horizontal, 2) == "he");
    CHECK(bo->read(5,5, ariel::Direction::Horizontal, 5) == "hello");
    bo->post(5,6,ariel::Direction::Vertical, "hi");
    CHECK(bo->read(5,6,ariel::Direction::Vertical, 3) == "hi_");
    CHECK(bo->read(5,5,ariel::Direction::Horizontal, 5) == "hhllo");
    CHECK(bo->read(200,201,ariel::Direction::Vertical,10) == "__________");
    bo->post(200,201,ariel::Direction::Vertical,"0123456789");
    CHECK(bo->read(200,201,ariel::Direction::Vertical, 10) == "0123456789");
    bo->post(5,5,ariel::Direction::Horizontal, "hello my name is yoel");
    CHECK(bo->read(5,5, ariel::Direction::Horizontal, 21) == "hello my name is yoel");
    bo->post(5,22,ariel::Direction::Horizontal, "yael");
    CHECK(bo->read(5,5, ariel::Direction::Horizontal, 21) == "hello my name is yael");


}