#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "css.hpp"


cpp_css::Root * simple_test ;
std::map<std::string, std::map<std::string, std::string>> first_add{
  {"html",{{"background", "#555"}}}
};

TEST_CASE("simple test") {
    SUBCASE("init") {
        simple_test = new cpp_css::Root();
    };
    SUBCASE("add"){
        simple_test->add(first_add);
    };
    SUBCASE("toString"){
        std::string result = simple_test->toString();
        CHECK(result == "html{background:#555;}");
    };

};
