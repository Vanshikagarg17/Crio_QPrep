#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
using namespace std;

class TrappingRainWater {
public:
	// Implement your solution by completing the below function`	
	int trap(vector<int>& height) {
	    int total = 0;
        int iLeft = -1;
        int minimum = 1;
        int iRight = 0;
        while (iRight < int(height.size())) {
            while (iRight < int(height.size()) && height[iRight] < minimum) {
                ++iRight;
            }
            if (iRight == int(height.size())) {
                int maxIndex = -1;
                int maxHeight = 0;
                for (int i = iLeft + 1; i < int(height.size()); ++i) {
                    if (height[i] > maxHeight) {
                        maxHeight = height[i];
                        maxIndex = i;
                    }
                }
                if (maxIndex > -1)
                    iRight = maxIndex;
            }
            if (iRight == int(height.size()))
                break;
            if (iLeft > -1) {
                int small = min(height[iLeft], height[iRight]);
                for (int i = iLeft + 1; i < iRight; ++i) {
                    total += (small - height[i]);
                }
            }
            minimum = height[iRight];
            iLeft = iRight;
            ++iRight;
        }
        return total;
    
	}
};

int main() {
	FastIO();
	int n;
	cin >> n;
	vector<int> heights;
	ReadMatrix<int>().OneDMatrix(n, heights);
	int result = TrappingRainWater().trap(heights);
	cout << result;
	return 0;
}
