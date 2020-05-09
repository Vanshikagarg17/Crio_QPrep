#include<bits/stdc++.h>
using namespace std;

class Node {
	
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
    
    Node* MakeList(vector<int> lst, vector<int> random) {
    	if (lst.size() == 0)
            return NULL;

        map<int, Node*> Map;
        Node* head = NULL;
        Node* trav = NULL;
        for (int i = 0; i < int(lst.size()); ++i) {
            trav = new Node(lst[i], NULL, NULL);
            Map[i] = trav;
            if (i > 0) {
                Node* prev = Map[i-1];
                prev->next = trav;
            } else {
                head = trav;
            }
        }

        trav = head;
        for (int i = 0; i < int(random.size()); ++i) {
            if (!random[i] == 0) {
                trav->random = Map[int(random[i]) - 1];
            }
            trav = trav->next;
        }

        return head;
	}
    
    void print(Node* head) {
    	Node* trav = head;
    	
    	while (trav != NULL) {
    		if (trav->random != NULL) {
    			cout << trav->val << " " << trav->random->val <<"\n";
			} else {
				cout << trav->val <<" null\n";
			}
			trav = trav->next;
		}
	}
};
