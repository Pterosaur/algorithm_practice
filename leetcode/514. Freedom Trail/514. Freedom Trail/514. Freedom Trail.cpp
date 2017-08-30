// 514. Freedom Trail.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//514. Freedom Trail
//In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.
//
//Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
//
//Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
//At the stage of rotating the ring to spell the key character key[i]:
//You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
//If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:
    int min_step(int x, int y, int size) {
        if (x >= y) {
            return min(x - y, y + size - x);
        }
        return min_step(y, x, size);
    }
public:
    int findRotateSteps(string ring, string key) {
        if (key.empty()) {
            return 0;
        }
        //create map
        vector<int> pos_map[26];
        for (int i = 0; i < ring.length(); i++) {
            pos_map[ring[i] - 'a'].push_back(i);
        }
        vector<int> minimum_step[2];

        vector<int> * cur_minimum = &minimum_step[0];
        vector<int> * pre_minimum = &minimum_step[1];
        
        cur_minimum->reserve(ring.length());
        pre_minimum->reserve(ring.length());

        //init
        for (int pos : pos_map[key[0] - 'a']) {
            cur_minimum->push_back(1 + min_step(0, pos, ring.size()));
        }
        for (int i = 1; i < key.length(); i++) {
            vector<int> * pre_pos = &pos_map[key[i - 1] - 'a'];
            vector<int> * cur_pos = &pos_map[key[i] - 'a'];
            swap(cur_minimum, pre_minimum);
            cur_minimum->clear();
            cur_minimum->resize(cur_pos->size(), numeric_limits<int>::max());
            for (int j = 0; j < cur_pos->size(); j++) {
                for (int k = 0; k < pre_pos->size(); k++) {
                    (*cur_minimum)[j] = min((*cur_minimum)[j], (*pre_minimum)[k] + 1 + min_step((*pre_pos)[k], (*cur_pos)[j], ring.size()));
                }
            }
        }

        return *min_element(cur_minimum->begin(), cur_minimum->end());
    }
};

int main()
{
    Solution s;
    s.findRotateSteps("godding", "gd");
    return 0;
}

