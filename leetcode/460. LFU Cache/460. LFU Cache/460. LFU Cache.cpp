// 460. LFU Cache.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//460. LFU Cache
//Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//
//Follow up:
//Could you do both operations in O(1) time complexity?
//
//Example:
//
//LFUCache cache = new LFUCache( 2 /* capacity */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.get(3);       // returns 3.
//cache.put(4, 4);    // evicts key 1.
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4

#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

class LFUCache {
private:
    using type_key = int;
    using type_value = int;
    using type_frequence = int;
    struct node{
        type_key m_key;
        type_value m_value;
        type_frequence m_frequence;
    };
    struct frequence_queue{
        type_frequence m_frequence;
        list<node> m_nodes;
    };
    unordered_map<type_key, list<node>::iterator> m_node_map;
    list<frequence_queue > m_frequence_list;
    unordered_map<type_frequence,  list<frequence_queue>::iterator > m_frequence_map;
    int m_rest_capacity;

    void add_frequence(list<node>::iterator itr) {
        node n = *itr;
        
        auto old_fq = m_frequence_map[n.m_frequence];
        old_fq->m_nodes.erase(itr);
       
        n.m_frequence++;
        auto new_fq_itr = m_frequence_map.find(n.m_frequence);
        list<frequence_queue>::iterator new_fq;
        if (new_fq_itr == m_frequence_map.end()) {
             new_fq = m_frequence_list.insert(old_fq, frequence_queue{n.m_frequence, list<node>()});
             m_frequence_map[n.m_frequence] = new_fq;
        }
        else {
            new_fq = new_fq_itr->second;
        }

        new_fq->m_nodes.push_back(n);
        m_node_map[n.m_key] = --new_fq->m_nodes.end();

        if (old_fq->m_frequence != 0 && old_fq->m_nodes.empty()) {
            m_frequence_map.erase(n.m_frequence - 1);
            m_frequence_list.erase(old_fq);
        }
    }

    void add_new_node(int key, int value) {
        node n{ key, value, 1 };
        auto first_fq_itr = m_frequence_map.find(n.m_frequence);
        list<frequence_queue>::iterator first_fq;
        if (first_fq_itr == m_frequence_map.end()) {
            m_frequence_list.push_back(frequence_queue{ n.m_frequence, list<node>() });
            first_fq = --m_frequence_list.end();
            m_frequence_map[n.m_frequence] = first_fq;
        }
        else {
            first_fq = first_fq_itr->second;
        }
        first_fq->m_nodes.push_back(n);
        m_node_map[key] = --first_fq->m_nodes.end();
    }
    bool remove_lfu() {
        if (m_node_map.empty()) {
            return false;
        }
        auto last_itr = --m_frequence_list.end();
        auto last_node = last_itr->m_nodes.front();

        m_node_map.erase(last_node.m_key);
        last_itr->m_nodes.pop_front();

        if (last_itr->m_nodes.empty()) {
            m_frequence_list.pop_back();
            m_frequence_map.erase(last_node.m_frequence);
        }

        return true;
    }
public:
    LFUCache(int capacity) {
        m_rest_capacity = capacity;
    }
    
    int get(int key) {
        auto itr = m_node_map.find(key);
        if (m_node_map.end() == itr) {
            return -1;
        }
        type_value v = itr->second->m_value;
        add_frequence(itr->second);
        return v;
    }
    
    void put(int key, int value) {

        auto itr = m_node_map.find(key);
        if (itr != m_node_map.end()) {
            itr->second->m_value = value;
            add_frequence(itr->second);
            return;
        }
        if (m_rest_capacity) {
            m_rest_capacity--;
            add_new_node(key, value);
            return;
        }
        if (remove_lfu()) {
            add_new_node(key, value);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
    LFUCache c(3);
    c.put(1, 1);
    c.put(2, 2);
    c.put(3, 3);
    c.put(4, 4);
    c.get(4);
    c.get(3);
    c.get(2);
    c.get(1);
    c.put(5, 5);
    c.get(1);
    c.get(2);
    c.get(3);
    c.get(4);
    c.get(5);
    return 0;
}

