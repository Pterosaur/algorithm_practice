// 71. Simplify Path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//71. Simplify Path
//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//click to show corner cases.
//
//Corner Cases:
//Did you consider the case where path = "/../"?
//In this case, you should return "/".
//Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string simple_path;
        simple_path.reserve(path.size());
        for (int i = 0; i < path.length(); i++) {
            char cur = path[i];
            if (simple_path.empty()) {
                simple_path.push_back(cur);
                continue;
            }
            char last = simple_path.back();
            if (cur == '/') {
                if (last == '.') {
                    //cur ***/./
                    if (simple_path.size() >= 1 && *(simple_path.end() - 2) == '/') {
                        simple_path.pop_back();
                        continue;
                    }
                    //parent ***/../
                    if (simple_path.size() >= 2 && *(simple_path.end() - 2) == '.' && *(simple_path.end() - 3) == '/') {
                        simple_path.pop_back();
                        simple_path.pop_back();
                        if (simple_path.size() > 1) {
                            simple_path.pop_back();
                        }
                        while (simple_path.size() > 1 && simple_path.back() != '/') {
                            simple_path.pop_back();
                        }
                        continue;
                    }
                }
                else if (last == '/') {
                    continue;
                }
                simple_path.push_back(cur);
                continue;
            }
            else {
                simple_path.push_back(cur);
                continue;
            }
        }

        if (simple_path.size() > 1) {
            if (simple_path.back() == '/') {
                simple_path.pop_back();
            }

            if (simple_path.back() == '.') {
                //cur ***/./
                if (simple_path.size() >= 1 && *(simple_path.end() - 2) == '/') {
                    simple_path.pop_back();
                    if (!simple_path.empty()) {
                        simple_path.pop_back();
                    }
                }
                //parent ***/../
                else if (simple_path.size() >= 2 && *(simple_path.end() - 2) == '.' && *(simple_path.end() - 3) == '/') {
                    simple_path.pop_back();
                    simple_path.pop_back();
                    simple_path.pop_back();
                    while (! simple_path.empty() && simple_path.back() != '/') {
                        simple_path.pop_back();
                    }
                    if (!simple_path.empty()) {
                        simple_path.pop_back();
                    }
                }
            }

        }
        if (simple_path.empty()) {
            simple_path.push_back('/');
        }
        return simple_path;
    }
};


int main()
{
    Solution s1;
    s1.simplifyPath("/home/../../../");
    return 0;
}

