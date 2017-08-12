// permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template<typename Itr>
bool next_permutation(Itr begin, Itr end) {
    if (begin == end) {
        return false;
    }
    auto last = --end;
    if (begin == last ) {
        return false;
    }
    auto previous = end;
    --previous;
    ++end;
    for (;;) {
        if (last== begin) {
            std::reverse(begin, end);
            return false;
        }
        //find descending
        if (*previous >= *last) {
            if (previous == begin) {
                std::reverse(begin, end);
                return false;
            }
            last = previous--;
            continue;
        }
        auto min_large = last;
        while (min_large < end && *(min_large) > *previous) { min_large++; };
        std::swap(*(--min_large), *previous);
        std::reverse(last, end);
        return true;
    }

}

bool test() {
    std::string test_cases[] = {
        "",
        "a",
        "abc",
        "abcdef",
        "aaaaaaafjk",
        "aaaaaaaa"
    };
    for (auto str : test_cases) {
        bool my_result = true;
        bool std_result = true;
        std::string my_str = str;
        std::string std_str = str;

        while (true) {

            my_result = ::next_permutation(my_str.begin(), my_str.end());
            std_result = std::next_permutation(std_str.begin(), std_str.end());
            if (my_result != std_result || my_str != std_str) {
                std::cout << "error : " << str << std::endl;
                return false;
            }
            if (std_result == false) {
                std::cout << "corrected : " << str << std::endl;
                break;
            }
        }
    }
    return true;
}

#include <time.h>

void benchmark() {
    std::string test_cases[] = {"123456" , "1234567", "12345678"};

    for (auto input : test_cases) {

        clock_t start, end;
        start = clock();
        while (::next_permutation(input.begin(), input.end()));
        end = clock();
        std::cout << "my consume : " << (end - start) << "ms" << std::endl;

        start = clock();
        while (std::next_permutation(input.begin(), input.end()));
        end = clock();
        std::cout << "std consume : " << (end - start) << "ms" << std::endl;
    }
}

int main()
{
    test();
    benchmark();
    return 0;
}

