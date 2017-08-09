// Googlements.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Problem
//
//Chemists work with periodic table elements, but here at Code Jam, we have been using our advanced number smasher to study googlements. A googlement is a substance that can be represented by a string of at most nine digits. A googlement of length L must contain only decimal digits in the range 0 through L, inclusive, and it must contain at least one digit greater than 0. Leading zeroes are allowed. For example, 103 and 001 are valid googlements of length 3. 400 (which contains a digit, 4, greater than the length of the googlement, 3) and 000 (which contains no digit greater than 0) are not.
//
//Any valid googlement can appear in the world at any time, but it will eventually decay into another googlement in a deterministic way, as follows. For a googlement of length L, count the number of 1s in the googlement (which could be 0) and write down that value, then count the number of 2s in the googlement (which could be 0) and write down that value to the right of the previous value, and so on, until you finally count and write down the number of Ls. The new string generated in this way represents the new googlement, and it will also have length L. It is even possible for a googlement to decay into itself!
//
//For example, suppose that the googlement 0414 has just appeared. This has one 1, zero 2s, zero 3s, and two 4s, so it will decay into the googlement 1002. This has one 1, one 2, zero 3s, and zero 4s, so it will decay into 1100, which will decay into 2000, which will decay into 0100, which will decay into 1000, which will continuously decay into itself.
//
//You have just observed a googlement G. This googlement might have just appeared in the world, or it might be the result of one or more decay steps. What is the total number of possible googlements it could have been when it originally appeared in the world?
//
//Input
//
//The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with a string G, representing a googlement.
//
//Output
//
//For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of different googlements that the observed googlement could have been when it first appeared in the world.
//
//Limits
//
//1 ¡Ü T ¡Ü 100.
//Each digit in G is a decimal digit between 0 and the length of G, inclusive.
//G contains at least one non-zero digit.
//Small dataset
//
//1 ¡Ü the length of G ¡Ü 5.
//Large dataset
//
//1 ¡Ü the length of G ¡Ü 9.
//Sample
//
//
//Input 
// 
//3
//20
//1
//123
// 	
//Output 
//
//Case #1: 4
//Case #2: 1
//Case #3: 1
//
//In sample case #1, the googlement could have originally been 20, or it could have decayed from 11, which could have itself decayed from 12 or 21. Neither of the latter two could have been a product of decay. So there are four possibilities in total.
//
//In sample case #2, the googlement must have originally been 1, which is the only possible googlement of length 1.
//
//In sample case #3, the googlement must have been 123; no other googlement could have decayed into it.

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

bool all_zeros(const string & g) {
    for (auto c : g) {
        if (c != '0') {
            return false;
        }
    }
    return true;
}

bool invalid_object(const string & g) {
    for (auto c : g) {
        if ((c - '0') > g.length()) {
            return true;
        }
    }
    return false;
}

bool exist_object(const string & g, unordered_set<string> & record) {
    auto insert_result = record.insert(g);
    return !insert_result.second;
}

bool length_limit(const string & g, int length) {
    return g.length() != length;
}

string previous_object(const string & g) {
    string previous;
    previous.reserve(g.length());
    for (int i = g.length() - 1; i >= 0; i--) {
        for (int j = 0; j < (g[i] - '0'); j++) {
            previous.push_back(i + '1');
        }
    }
    while (previous.length() < g.length()) {
        previous.push_back('0');
    }
    return previous;
}

int _googlements_possible(const string & g,const int length, unordered_set<string> & record) {
    if (length_limit(g, length) || all_zeros(g) || invalid_object(g)  || exist_object(g, record)) {
        return 0;
    }
    int count = 1;
    string previous = previous_object(g);
    if (length_limit(previous, length) || all_zeros(previous) || invalid_object(previous)) {
        return count;
    }
    int sub_count = 0;
    do {
        if (sub_count != 1) {
            sub_count = _googlements_possible(previous, length, record);
        }
        count += sub_count;
    } while (prev_permutation(previous.begin(), previous.end()));
    
    return count;
}

int googlements_possible(const string & g) {
    int count = 0;
    unordered_set<string> record;

    count += _googlements_possible(g, g.length(), record);

    return count;
}

void wrap(int index, const string & input) {
    cout << "Case #" << (index+1) << ": " << googlements_possible(input) << endl;;
}

void codejam() {
    int number = 0;
    int i = 0;
    cin >> number;
    string input;
    for (; i < number; i++) {
        cin >> input;
        wrap(i, input);
    }
}

int main()
{
    codejam();
    return 0;
}

