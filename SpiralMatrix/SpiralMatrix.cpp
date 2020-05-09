#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class SpiralMatrix {
public:
    // Implement your solution by completing the below function	
    vector<int> spiralOrder(vector<vector<int>>& matrix,int n,int m) {
    
	if(matrix.empty())return {};
        vector<int> result;
        int row=matrix.size(),col=matrix[0].size(),r=0,c=0;
        while(r<row && c<col){
            int i;
            for(i=c;i<col;i++){
                result.push_back(matrix[r][i]);
            }
            r++;
            for(i=r;i<row;i++){
                result.push_back(matrix[i][col-1]);
            }
            col--;
            if(row>r){
                for(i=col-1;i>=c;i--){
                    result.push_back(matrix[row-1][i]);
                }
                row--;
            }
            if(col>c){
                for(i=row-1;i>=r;i--){
                    result.push_back(matrix[i][c]);
                }
                c++;
            }
        }


        return result;
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix;
	ReadMatrix<int>().TwoDMatrix(n, m, matrix);
	vector<int> result = SpiralMatrix().spiralOrder(matrix,n,m);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
