#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MatrixTraversal {
public:
    // Implement your solution by completing the below function	
    vector<int> traversalPath(vector<vector<int>>& matrix, int currPosX, int currPosY, int dirToMove, int stepsToMove,int n,int m,vector<int> &res) 
	{

		if(stepsToMove==0)
		return res;

		if(dirToMove==1)
		{
			if(currPosY!=m-1)
			{res.push_back(matrix[currPosX][currPosY+1]);
			traversalPath(matrix, currPosX, currPosY+1, dirToMove, stepsToMove-1,n,m,res);
			}
			else
			{	res.clear();
				res.push_back(-1);	
				traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove-1,n,m,res);
			}
		}

		if(dirToMove==2)
		{
			if(currPosX!=n-1)
			{res.push_back(matrix[currPosX+1][currPosY]);
			traversalPath(matrix, currPosX+1, currPosY, dirToMove, stepsToMove-1,n,m,res);
			}
			else
			{	res.clear();
				res.push_back(-1);	
				traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove-1,n,m,res);
			}
		}

		if(dirToMove==3)
		{
			if(currPosY!=0)
			{res.push_back(matrix[currPosX][currPosY-1]);
			traversalPath(matrix, currPosX, currPosY-1, dirToMove, stepsToMove-1,n,m,res);
			}
			else
			{	res.clear();
				res.push_back(-1);	
				traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove-1,n,m,res);
			}
		}

		if(dirToMove==4)
		{
			if(currPosX!=0)
			{res.push_back(matrix[currPosX-1][currPosY]);
			traversalPath(matrix, currPosX-1, currPosY, dirToMove, stepsToMove-1,n,m,res);
			}
			else
			{	res.clear();
				res.push_back(-1);	
				traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove-1,n,m,res);
			}
		}


       return res;
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix;
	ReadMatrix<int>().TwoDMatrix(n, m, matrix);
	vector<int> res;
	int currPosX, currPosY, dirToMove, stepsToMove;
	cin >> currPosX >> currPosY;
	cin >> dirToMove >> stepsToMove;

	vector<int> result = MatrixTraversal().traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove,n,m,res);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
