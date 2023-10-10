cmake_minimum_required(VERSION 3.20)

project(leetcode LANGUAGES C CXX)

# --------------------------------------------------------------------------------------------------
# ---- Testing -------------------------------------------------------------------------------------
# --------------------------------------------------------------------------------------------------

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB daily_SRC CONFIGURE_DEPENDS "daily/*.h" "daily/*.cpp")

message("daily sources: ${daily_SRC}")

add_executable(
    daily
    ${daily_SRC}
    )

target_link_libraries(
    daily
    GTest::gtest_main
    )

include(GoogleTest)
gtest_discover_tests(daily)
