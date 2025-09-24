add_executable(my_tests
    test_main.cpp
    ../min_max.cpp       # реализация функции min_max
    ../avarage.cpp       # если тесты используют другие функции
)

target_link_libraries(my_tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(my_tests PRIVATE ${CMAKE_SOURCE_DIR})

include(Catch)
catch_discover_tests(my_tests)
