#include<bits/stdc++.h>
using namespace std;

class TreeNode {
	
public:
	long val;
	TreeNode* left;
	TreeNode* right;
    TreeNode* next;
	
	TreeNode() {}
	
	TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
	
	TreeNode* makeTreeFromArray(int idx, vector<string> tree, TreeNode* root) {
        if(idx >= int(tree.size()))
            return NULL;

        if(tree[idx] == "null")
            return NULL;

        long x = stoi(tree[idx]);
        root = new TreeNode(x);
        root->left = makeTreeFromArray(2*idx + 1 , tree, root->left);
        root->right = makeTreeFromArray(2*idx + 2, tree, root->right);
        return root;
    }

    vector<vector<string>> makeLevelOrderFromTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<string>> answer;
        if(root == NULL) {
            return answer;
        }
        q.push(root);
        while(!q.empty()) {
            vector<string> atThisLevel;
            int size = q.size();
            while(size > 0) {
                size--;
                TreeNode* temp = q.front();
                q.pop();
                if(temp == NULL) {
                    atThisLevel.push_back("null");
                    continue;
                } else {
                    q.push(temp->left);
                    q.push(temp->right);
                    atThisLevel.push_back(to_string(temp->val));
                }
            }
            answer.push_back(atThisLevel);
        }
        return answer;
    }

    void makePreOrderFromTree(TreeNode* root, vector<int>& preOrder) {
        if(root == NULL) {
            return ;
        }
        preOrder.push_back(root->val);
        makePreOrderFromTree(root->left, preOrder);
        makePreOrderFromTree(root->right, preOrder);
    }

    void makeInOrderFromTree(TreeNode* root, vector<int>& inOrder) {
        if(root == NULL) {
            return ;
        }
        makeInOrderFromTree(root->left, inOrder);
        inOrder.push_back(root->val);
        makeInOrderFromTree(root->right, inOrder);
    }

    vector<string> makeNextPointersFromTree(TreeNode* root, vector<string>& nextArray) {
        queue<TreeNode*> q;
        if(root == NULL)
            return nextArray;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
                if(temp->next == NULL) {
                    nextArray.push_back("null");
                }
                else {
                nextArray.push_back(to_string(temp->next->val));
                }
            }
        }
        return nextArray;
    }

    string treeNodeToString(TreeNode* root) {
        vector<vector<string>> arr = makeLevelOrderFromTree(root);
        string str = "";
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < int(arr[i].size()); j++) {
                str += arr[i][j];
                str += " ";
            }
        }
        return str;
    }
};
