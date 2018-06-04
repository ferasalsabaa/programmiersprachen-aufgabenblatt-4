#define CATCH_CONFIG_RUNNER
#include "List.hpp"
#include <catch.hpp>
#include <iostream>

//4.2
TEST_CASE("testing_list", "[list]")
{
 List<int> l1;
 REQUIRE(l1.empty() == true);
 REQUIRE(l1.size() == 0);

}
//4.3 push_front ..
TEST_CASE ( "add an element with push_front" , "[ modifiers ]" )
{
List <int> list ;
list.push_front(42);
REQUIRE(42 == list.front());
}
//4.3 push_back ..
TEST_CASE ( "add an element with push_back" , "[back]" )
{
List <int> list;
list.push_back(42);
REQUIRE(42 == list.back());
}
//4.3 pop_front
TEST_CASE ( "add an element with pop_front" , "[front]" )
{
List <int> list;
list.push_front(42);
list.push_front(4);
list.push_front(32);
list.push_front(12);
list.pop_front();
REQUIRE(3 == list.size());
REQUIRE(32 == list.front());
}
//4.3 pop_backe
TEST_CASE ( "add an element with pop_backe" , "[backe]" )
{
List <int> list;
list.push_front(42);
list.push_front(4);
list.push_front(32);
list.push_front(12);
list.pop_back();
REQUIRE(3 == list.size());
REQUIRE(4 == list.back());
}


int main(int argc, char *argv[])
{ 
  return Catch::Session().run(argc, argv);
}