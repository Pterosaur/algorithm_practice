// 146. LRU Cache.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//146. LRU Cache
//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//Follow up:
//Could you do both operations in O(1) time complexity?
//
//Example:
//
//LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4

#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int m_free;
    std::list<pair<int, int> > m_queue;
    std::unordered_map<int, std::list<pair<int, int> >::iterator> m_map;
public:
    LRUCache(int capacity) {
        m_free = capacity;
    }
    
    int get(int key) {
        auto itr = m_map.find(key);
        if (itr != m_map.end()) {
            m_queue.push_back(*itr->second);
            m_queue.erase(itr->second);
            m_map[key] = --m_queue.end();
            return m_queue.back().second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto itr = m_map.find(key);
        if (itr != m_map.end()) {
            itr->second->second = value;
            get(key);
            return;
        }
        if (m_free > 0) {
            m_free--;
            m_queue.push_back({ key, value });
            m_map[key] = --m_queue.end();
            return;
        }
        m_map.erase(m_queue.front().first);
        m_queue.pop_front();
        m_queue.push_back({key, value});
        m_map[key] = --m_queue.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


int main()
{
    return 0;
}

