//23. Merge k Sorted Lists
//
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//

#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
	struct cmp {
		bool operator()(const ListNode * a, const ListNode * b) {
			if (a != NULL && b != NULL)
				return a->val > b->val;
			else if (a == NULL && b != NULL) {
				return true;
			}
			else {
				return false;
			}
		}
	};
public:
	
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return NULL;
		}
		ListNode * new_list = NULL, *p = NULL;
		cmp c;
		make_heap(lists.begin(), lists.end(), c);
		std::vector<ListNode *>::iterator minimum = lists.begin(), maximum= lists.end();
		
		 while ((*minimum) != NULL) {
			if ((*(maximum - 1)) == NULL) {
				maximum--;
			}
			if (p == NULL) {
				new_list = p = *minimum;
			}
			else {
				p->next = *minimum;
				p = p->next;
			}
			pop_heap(minimum, maximum, c);
			*(maximum - 1) = (*(maximum - 1))->next;
			push_heap(minimum, maximum, c);
		}
		return new_list;
    }
};


void generate_list(vector<ListNode *> & lists, int count, int max) {
	lists.resize(count);
	vector<ListNode **> lasts(count);
	transform(lists.begin(), lists.end(), lasts.begin(), [](ListNode *& l) {return &l; });
	int num = 0;
	while (num < max) {
		ListNode **& p = lasts[num % count];
		if (*p == NULL) {
			*p = new ListNode(num);
		}
		else {
			(*p)->next = new ListNode(num);
			p = &((*p)->next);
		}
		num++;
	}
}

int main() {
	vector<ListNode *> lists;
	generate_list(lists, 1, 0);
	Solution s;
	s.mergeKLists(lists);
	return 0;
}