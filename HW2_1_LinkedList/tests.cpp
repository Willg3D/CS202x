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
	std::list<Monster> test1;
	Monster v1,v2,v3,v4;
	enterMonValue(v1, 1, 'W', 1, 1, 1, 1);
	enterMonValue(v2, 2, 'W', 2, 2, 2, 2);
	enterMonValue(v3, 3, 'W', 3, 3, 3, 3);
	test1.push_back(v1);
	test1.push_back(v2);
	test1.push_back(v3);
	REQUIRE(v1 == test1.front()); //check if v1 in front
	REQUIRE(v3 == test1.back()); //check if v3 in back


}
// Stack
TEST_CASE("Push and Pop Test Stack", "[Stack]") {


}
// Insert and Find
TEST_CASE("Insert and Find", "") {


}
// Print the list out
TEST_CASE("Print the list out", "") {


}
