#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MergeIntervals {
public:
	// Implement your solution by completing the below function
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
	map<int,int> mergeint;
	vector<int> value;
	
	if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1; i<int(intervals.size()); ++i){
            if(res.back()[1] >= intervals[i][0]) {
                res[res.size()-1][1] = max(res[res.size()-1][1],intervals[i][1]);
            }
            else {
                res.push_back({intervals[i]});
            }
        }
		
			
        return res;
    }
};

int main() {
    FastIO();
	int n;
	cin >> n;
	vector<vector<int>> nums;
	ReadMatrix<int>().TwoDMatrix(n, 2, nums);
	vector<vector<int>> result = MergeIntervals().merge(nums);
	PrintMatrix<int>().TwoDMatrix(result);
	return 0;
}
