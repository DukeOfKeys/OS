#include <catch2/catch_test_macros.hpp>
#include "../common.h"
#include <iostream>

TEST_CASE("min_max: ordinary")
{
    int arr[] = {1, 5, -3, 7, 2, 10};
    long long result = min_max(arr, 6);

    int min = *((int *)&result);
    int max = *((int *)&result + 1);

    REQUIRE(min == -3);
    REQUIRE(max == 10);
}

TEST_CASE("min_max: one element")
{
    int arr[] = {42};
    long long result = min_max(arr, 1);

    int min = *((int *)&result);
    int max = *((int *)&result + 1);

    REQUIRE(min == 42);
    REQUIRE(max == 42);
}

TEST_CASE("min_max: negative")
{
    int arr[] = {-10, -5, -20, -1};
    long long result = min_max(arr, 4);

    int min = *((int *)&result);
    int max = *((int *)&result + 1);

    REQUIRE(min == -20);
    REQUIRE(max == -1);
}

TEST_CASE("min_max: empty")
{
    int *arr = nullptr;
    long long result = min_max(arr, 0);
    REQUIRE(result == -1);
}

TEST_CASE("min_max: odd number of answers")
{
    int arr[] = {7, 3, 5};
    long long result = min_max(arr, 3);

    int min = *((int *)&result);
    int max = *((int *)&result + 1);

    REQUIRE(min == 3);
    REQUIRE(max == 7);
}

TEST_CASE("min_max: random arrays")
{
    srand((unsigned)time(nullptr));
    for (int test = 0; test < 2; ++test)
    {
        int size = 1 + rand() % 1000;
        vector<int> arr(size);

        for (int i = 0; i < size; ++i)
        {
            arr[i] = -10000 + std::rand() % 20001;
        }

        long long result = min_max(arr.data(), size);

        int min_result = *((int *)&result);
        int max_result = *((int *)&result + 1);

        auto [stl_min_it, stl_max_it] = minmax_element(arr.begin(), arr.end());
        REQUIRE(min_result == *stl_min_it);
        REQUIRE(max_result == *stl_max_it);
    }
}

TEST_CASE("avarage calculates correct average for small arrays")
{
    int arr[] = {1, 2, 3, 4, 5};
    arrayData data{arr, 5, 0};

    avarage(&data);

    REQUIRE(data.result == 3); // (1+2+3+4+5)/5 = 3
}

TEST_CASE("avarage works with single element array")
{
    int arr[] = {42};
    arrayData data{arr, 1, 0};

    avarage(&data);

    REQUIRE(data.result == 42);
}

TEST_CASE("avarage handles even number of elements")
{
    int arr[] = {10, 20, 30, 40};
    arrayData data{arr, 4, 0};

    avarage(&data);

    REQUIRE(data.result == 25); // (10+20+30+40)/4 = 25
}

TEST_CASE("avarage works with negative numbers")
{
    int arr[] = {-5, -15, -10, -20};
    arrayData data{arr, 4, 0};

    avarage(&data);

    REQUIRE(data.result == -12); // (-5-15-10-20)/4 = -12
}

TEST_CASE("avarage rounds down for integer division")
{
    int arr[] = {1, 2};
    arrayData data{arr, 2, 0};

    avarage(&data);

    REQUIRE(data.result == 1); // (1+2)/2 = 1.5 -> int = 1
}