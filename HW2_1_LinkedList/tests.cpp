#include <iostream>
#include <list>
#include "catch.hpp"


struct Monster { // Value Struct
	int id; // used for order
	char type; //Letter to indicate W-water R-rock G-grass
	int hp;
	int sta;
	int att;
	int def;
};

bool operator==(const Monster& a, const Monster& b) { 
	return (a.id == b.id) && (a.type == b.type) && (a.hp == b.hp) && 
		(a.sta == b.sta) && (a.att == b.att) && (a.def == b.def);
}
bool operator!=(const Monster& a, const Monster& b) {
	return (a.id != b.id) && (a.type != b.type) && (a.hp != b.hp) &&
		(a.sta != b.sta) && (a.att != b.att) && (a.def != b.def);
}

void enterMonValue(Monster& name, int id, char type, int hp, int sta, int att, int def) {
	name.id = id;
	name.type = type;
	name.hp = hp;
	name.sta = sta;
	name.att = att;
	name.def = def;
}


// Queue
TEST_CASE("Push and Pop Test Queue", "[Queue]") {
	std::list<Monster> test;
	Monster v1,v2,v3,temp;
	enterMonValue(v1, 1, 'W', 1, 1, 1, 1);
	enterMonValue(v2, 2, 'W', 2, 2, 2, 2);
	enterMonValue(v3, 3, 'W', 3, 3, 3, 3);
	test.push_back(v1);
	test.push_back(v2);
	test.push_back(v3);
	REQUIRE(v1 == test.front()); //check if v1 in front
	REQUIRE(v3 == test.back()); //check if v3 in back
	
	test.pop_front();
	REQUIRE(v2 == test.front()); //check if v2 in front after pop
	test.pop_front();
	REQUIRE(v3 == test.front()); //check if v3 in front after pop

}

// Stack
TEST_CASE("Push and Pop Test Stack", "[Stack]") {
	std::list<Monster> test;
	Monster v1, v2, v3, temp;
	enterMonValue(v1, 1, 'W', 1, 1, 1, 1);
	enterMonValue(v2, 2, 'W', 2, 2, 2, 2);
	enterMonValue(v3, 3, 'W', 3, 3, 3, 3);
	test.push_back(v1);
	test.push_back(v2);
	test.push_back(v3);
	REQUIRE(v1 == test.front()); //check if v1 in front
	REQUIRE(v3 == test.back()); //check if v3 in back

	test.pop_back();
	REQUIRE(v2 == test.back()); //check if v2 in back after pop
	test.pop_back();
	REQUIRE(v1 == test.back()); //check if v3 in back after pop

}
// Insert and Find
TEST_CASE("Insert and Find", "") {


}
// Print the list out
TEST_CASE("Print the list out", "") {


}
