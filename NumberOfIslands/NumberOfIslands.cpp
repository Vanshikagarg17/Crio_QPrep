 #include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class NumberOfIslands {
public:
	int m,n;
    // Implement your solution by completing the below function
   void BFS(int i,int j,vector<string>& grid) {
        
        if (i<0 || j<0 || i>=m || j>=n) return;
        if (grid[i][j]=='0' || grid[i][j]=='2') return;
        grid[i][j] = '2';
        BFS(i-1,j,grid);
        BFS(i+1,j,grid);
        BFS(i,j-1,grid);
        BFS(i,j+1,grid);
        
    }
    int numIslands(vector<string>& grid) {
              int cnt = 0;
         m = grid.size();
         if (m==0) return 0;
         n = grid[0].size();
         if (n==0) return 0;
         for (int i = 0;i<m;i++) {
            for (int j = 0;j<n;j++) {
                if (grid[i][j]=='1') {
                    cnt++;
                    grid[i][j] = '2';
                    BFS(i-1,j,grid);
                    BFS(i+1,j,grid);
                    BFS(i,j-1,grid);
                    BFS(i,j+1,grid);
                }
            }
        }
        
         return cnt;
    
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<string> grid;
	ReadMatrix<string>().OneDMatrix(n, grid);
	int result = NumberOfIslands().numIslands(grid);
	cout << result;
	return 0;
}
