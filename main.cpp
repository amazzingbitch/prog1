#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <cstdio>
#include "Data.h"
#include "catch.hpp"

using namespace std;

int main() {
    Catch::Session().run();
    return 0;
}

