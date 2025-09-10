add_executable(test_creator test_creator.cpp)
target_link_libraries(test_creator PRIVATE creator_func GTest::gtest_main)
#add_executable(test_reporter test_reporter.cpp)
#target_link_libraries(test_reporter PRIVATE reporter GTest::gtest_main)

#add_executable(test_mainprog test_mainprog.cpp)
#target_link_libraries(test_mainprog PRIVATE main GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_creator)
#gtest_discover_tests(test_reporter)
#gtest_discover_tests(test_mainprog)
