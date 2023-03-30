#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "css.hpp"


cpp_css::Root * simple_test ;
std::map<std::string, std::map<std::string, std::string>> first_add{
  {"html",{{"background", "#555"}}}
};

TEST_SUITE("simple test") {
    TEST_CASE("init" * doctest::timeout(0.00004)) {
        simple_test = new cpp_css::Root();
    };
    TEST_CASE("add" * doctest::timeout(0.00004)){
        simple_test->add(first_add);
    };
    TEST_CASE("checkExistName"){
        bool result = simple_test->checkExistName("html");
        CHECK(result == true);
    };
    TEST_CASE("checkExist" * doctest::timeout(0.00004)){
        bool result = simple_test->checkExist("html","background");
        CHECK(result == true);
    };
    TEST_CASE("get" * doctest::timeout(0.00004)){
        std::string result = simple_test->get("html","background");
        CHECK(result == "#555");
    };
    TEST_CASE("toString" * doctest::timeout(0.00004)){
        std::string result = simple_test->toString();
        CHECK(result == "html{background:#555;}");
    };

};
