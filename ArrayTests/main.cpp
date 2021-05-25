#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Array.h"

SCENARIO("Array creation", "[Creation]") {
	GIVEN("A default array") {
		Array<int> defaultArray{};

		WHEN("created") {
			THEN("is empty") {
				REQUIRE(defaultArray.elementCount() == 0);
			}
		}
	}

	GIVEN("A new array") {
		Array<int> a{ 3 };

		WHEN("created with an element count") {
			THEN("is sized to the number of elements") {
				REQUIRE(a.elementCount() == 3);
			}
		}

		WHEN("elements are assigned a value") {
			a[0] = 1;
			a[1] = 2;
			a[2] = 3;

			THEN("the value is set to the element at the specified index") {
				REQUIRE(a[1] == 2);
			}
		}

		WHEN("an index is out of range") {
			THEN("an IndexOutOfRangeException is thrown") {
				REQUIRE_THROWS_AS(a[4], IndexOutOfRangeException);
			}
		}
	}
}