// William Glass
// CS 202x
// HW 2_1

#include <iostream>
#include <list>
#include <string>
#include <sstream>  // std::stringstream
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
	return (a.id != b.id) || (a.type != b.type) || (a.hp != b.hp) ||
		(a.sta != b.sta) || (a.att != b.att) || (a.def != b.def);
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
	Monster v1, v2, v3;
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
	Monster v1, v2, v3;
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
	std::list<Monster> test;
	Monster v1, v2, v3, v4;
	enterMonValue(v1, 1, 'W', 1, 1, 1, 1);
	enterMonValue(v2, 2, 'W', 2, 2, 2, 2);
	enterMonValue(v3, 3, 'W', 3, 3, 3, 3);
	enterMonValue(v4, 4, 'R', 4, 4, 4, 4);
	test.push_back(v1);
	test.push_back(v2);
	test.push_back(v4);
	
	// search for v2 
	auto position = test.begin(); // position iter of test
	for (size_t i = 0; i < test.size(); i++){
		if (v2.id == (position->id)){ // if position id and v2 match then break
			break;
		}
		std::advance(position, 1); // advances the iter
	}
	REQUIRE(v2 == *position); // verifies search position equals v2

	// insert v3 in correct location
	position = test.begin(); // position iter of test
	for (size_t i = 0; i < test.size(); i++) {
		if (v2.id == (position->id)) { // if position id and v2 match then break
			std::advance(position, 1); // advances the iter
			test.insert(position, v3);
			break;
		}
		std::advance(position, 1); // advances the iter
	}

	position = test.begin(); // position iter of test
	std::advance(position, v3.id - 1); // advances the iter to location of v3 id - 1
	REQUIRE(v3 == *position); //verifies v3 is in expected position

}
// Print the list out
void printTest(std::ostream& os = std::cout) {

}

TEST_CASE("Print the list out", "") {
	std::list<Monster> test;
	Monster v1, v2, v3, v4;
	enterMonValue(v1, 1, 'W', 1, 1, 1, 1);
	enterMonValue(v2, 2, 'W', 2, 2, 2, 2);
	enterMonValue(v3, 3, 'W', 3, 3, 3, 3);
	enterMonValue(v4, 4, 'R', 4, 4, 4, 4);
	test.push_back(v1);
	test.push_back(v2);
	test.push_back(v3);
	test.push_back(v4);

	// Print each struct
	std::cout << "Prints out Monster stuck (Value struct):\n";
	auto position = test.begin(); // position iter of test
	for (size_t i = 0; i < (test.size()); i++) {
		std::cout << " ID: " << position->id;
		std::cout << " Type: " << position->type;
		std::cout << " Hp: " << position->hp;
		std::cout << " Stamina: " << position->sta;
		std::cout << " Attack: " << position->att;
		std::cout << " Defence: " << position->def << "\n";
		std::advance(position, 1); // advances the iter
	}

	//could figure out checking buffer
	std::stringstream txt;
	position--; // position of v4
	txt << position->id;
	std::string text = txt.str(); // converts stringstream to string
	std::string expected = "4"; // expected id value 4
	REQUIRE(text == expected); // verifies search position equals v2

}
