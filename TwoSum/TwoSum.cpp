#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class TwoSum {
public:
    // Implement your solution by completing the below function	
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> ans;
    
        
        for(int i=0;i<int (v.size());i++){
            ans.clear();
            int t =  target-v[i];
            ans.push_back(i);
            for(int j=i+1;j<int (v.size());j++){
                if(t==v[j]){
                    ans.push_back(j);
                    break;
                }
            }
            if(ans.size()==2){
                break;
            }
        }
        return ans;
    }
};

int main() {
	FastIO();
	int n, target;
	cin >> n;
	vector<int> nums;
	ReadMatrix<int>().OneDMatrix(n, nums);
	cin >> target;
	vector<int> result = TwoSum().twoSum(nums, target);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
