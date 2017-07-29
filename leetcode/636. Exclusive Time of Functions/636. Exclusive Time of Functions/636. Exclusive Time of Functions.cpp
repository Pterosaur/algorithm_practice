// 636. Exclusive Time of Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//636. Exclusive Time of Functions
//Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions.
//
//Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.
//
//A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts from the very beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0.
//
//Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.
//
//Example 1:
//Input:
//n = 2
//logs = 
//["0:start:0",
// "1:start:2",
// "1:end:5",
// "0:end:6"]
//Output:[3, 4]
//Explanation:
//Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1. 
//Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
//Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time. 
//So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.
//Note:
//Input logs will be sorted by timestamp, NOT log id.
//Your output should be sorted by function id, which means the 0th element of your output corresponds to the exclusive time of function 0.
//Two functions won't start or end at the same time.
//Functions could be called recursively, and will always end.
//1 <= n <= 100

#include <vector>
#include <string>
#include <stack>
using namespace std;

struct log_format {
    int m_id;
    bool m_is_start;
    int m_time;
};

log_format parse(const std::string & log) {
    log_format data;
    char * next = NULL;
    data.m_id = std::strtol(log.c_str(), &next, 10);
    if (next[1] == 's') {
        next += 7;
        data.m_is_start = true;
    }
    else {
        next += 5;
        data.m_is_start = false;
    }
    data.m_time = std::strtol(next, &next, 10);
    return data;
}

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> executive_times;
        stack<int> track;
        executive_times.resize(n);
        log_format data = parse(logs.front());
        int cur_time = data.m_time;
        track.push(data.m_id);
        for (int i = 1; i < logs.size(); i++) {
            data = parse(logs[i]);
            if (data.m_is_start) {
                executive_times[track.top()] += data.m_time - cur_time;
                track.push(data.m_id);
                cur_time = data.m_time;
            }
            else {
                executive_times[track.top()] += data.m_time - cur_time + 1;
                track.pop();
                cur_time = data.m_time + 1;
            }
        }

        return executive_times;

    }
};

int main()
{
    char *next = NULL;
    string log = "1:end:2";
    auto format = parse(log);
    return 0;
}

