cmake_minimum_required(VERSION 3.23)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(runAllTests runAllTests.cpp ../ShoppingList.cpp ../ShoppingList.h ../Item.cpp ../Item.h ../User.cpp ../User.h UserTest.cpp ShoppingListTest.cpp ItemTest.cpp)
target_link_libraries(runAllTests gtest gtest_main)

