#include <catch2/catch_test_macros.hpp>
#include <cstdint>

uint32_t factorial( uint32_t number ) {
    return number > 1 ? factorial(number-1) * number : 1;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    SECTION("It does not work with 0! ")
    {
        REQUIRE( factorial( 0) == 1 );
    }

    REQUIRE( factorial( 1) == 1 );
    REQUIRE( factorial( 2) == 2 );
    REQUIRE( factorial( 3) == 6 );
}
