#ifndef BDD_HPP
#define BDD_HPP

#include <functional>

#define describe(name) TEST_CASE(name)
#define context(name) SECTION(name)
#define it(name) SECTION(name)

#define before_each(...) auto __setup = [&]() { __VA_ARGS__ }; __setup();
#define after_each(...) \
auto __cleanup = [&]() { __VA_ARGS__ }; \
struct __Cleanup { \
std::function<void()> f; \
~__Cleanup() { f(); } \
} __cleanup_obj{__cleanup};

#define should(expr) REQUIRE(expr)
#define should_not(expr) REQUIRE_FALSE(expr)
#define should_eq(actual, expected) REQUIRE((actual) == (expected))
#define should_ne(actual, expected) REQUIRE((actual) != (expected))
#define should_throw(expr) REQUIRE_THROWS(expr)
#define should_nothrow(expr) REQUIRE_NOTHROW(expr)

#endif
