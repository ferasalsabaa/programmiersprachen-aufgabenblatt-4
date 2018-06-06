#define CATCH_CONFIG_RUNNER
#include "List.hpp"
#include <catch.hpp>
#include <iostream>

#include <vector>

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
//4.3 pop_front ..
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

//4.4 
TEST_CASE ( "should be empty after clearing" , "[modifiers]" )
{
List <int> list ;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
list.clear();
REQUIRE(list.empty());
}
//4.6
TEST_CASE ("should be an empty range after default construction",
"[iterators]" )
{
List <int> list ;
auto b = list.begin ();
auto e = list.end ();
REQUIRE (b==e);
}
TEST_CASE ("provide access to the first element with begin" ,"[iterators]")
{
List <int> list ;
list.push_front(42);
REQUIRE (42 == *list.begin());
}
TEST_CASE ("gleich" ,"[gleich]")
{
List <int> list ;
list.push_front(1);
list.push_front(5);
list.push_front(3);
list.push_front(2);
List <int> list2 ;
list2.push_front(1);
list2.push_front(5);
list2.push_front(3);
list2.push_front(2);
REQUIRE (list==list2);
//REQUIRE (list!=list2);
}


TEST_CASE ("dereference_operator" ,"[dereference_operator]")
{
List <std::vector<int>> list ;
list.push_front(std::vector<int>());


auto list_begin = list.begin();

//REQUIRE (list==list2);
REQUIRE (0 == (*list_begin).size() );
REQUIRE (0 == list_begin->size() );
}

int main(int argc, char *argv[])
{ 
  return Catch::Session().run(argc, argv);
}