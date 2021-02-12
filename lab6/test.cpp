#include "catch.hpp"
#include "Vector3f.h"

//unsigned int Factorial(unsigned int number) {
//	return number <= 1 ? 1 : Factorial(number - 1) * number;
//}


bool operator==(const Vector3f& a, const Vector3f& b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z); }
bool operator!=(const Vector3f& a, const Vector3f& b) { return (a.x != b.x) || (a.y != b.y) || (a.z != b.z); }



TEST_CASE("Default Construct Values = 0", "[Vector3f]") {
	Vector3f a;
	REQUIRE(a.x == 0.0);
	REQUIRE(a.y == 0.0);
	REQUIRE(a.z == 0.0);
}

TEST_CASE("User constructor allows the values x, y, and z to be set to some number", "[Vector3f]") {
	Vector3f a(1.0,2.0,3.0);
	REQUIRE(a.x == Approx(1.0));
	REQUIRE(a.y == Approx(2.0));
	REQUIRE(a.z == Approx(3.0));
}

TEST_CASE("Copy constructor ", "[Vector3f]") {
	Vector3f a(1.0, 2.0, 3.0);
	Vector3f b;
	REQUIRE(b != a);
	b = a;
	REQUIRE(a == b);
}

TEST_CASE("Equality Check", "[Vector3f]") {
	Vector3f a(1.0f, 2.1f, 1.1f);
	Vector3f b(1.0f, 2.1f, 1.1f);
	REQUIRE(a == b);
}

TEST_CASE("Inequality Check", "[Vector3f]") {
	Vector3f a(1.0f, 2.1f, 1.1f);
	Vector3f b(1.0f, 2.2f, 1.2f);
	REQUIRE(a != b);
}