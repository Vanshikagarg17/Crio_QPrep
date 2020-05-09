#include<bits/stdc++.h>
using namespace std;

class ListNode {
	
public:
	int val;
	ListNode* next;
	
	ListNode() {}
	
	ListNode(int x) {
		val = x;
		next = NULL;
	}
	
	ListNode* createList(vector<int> numbers) {
		if(numbers.size() == 0)
			return NULL;
		
		ListNode* head = new ListNode(numbers[0]);
		ListNode* node = head;
		
		for(int i = 1; i < int(numbers.size()); ++i) {
			node->next = new ListNode(numbers[i]);
			node = node->next;
		}
		
		return head;
	}
	
	vector<int> extractList(ListNode* head) {
		vector<int> lst;
		
		while(head != NULL) {
			lst.push_back(head->val);
			head = head->next;
		}
		
		return lst;
	}

	ListNode* generateLinkedListWithCycle(vector<int> nums, int pos) {
		ListNode* list = createList(nums);
		if(pos == -1) {
			return list;
		}
		ListNode* head = list;
		ListNode* tail = list;
		while(pos > 0) {
			pos--;
			head = head->next;
		}
		while(tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = head;
		return list;
	}
};
