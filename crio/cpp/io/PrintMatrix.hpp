#include<bits/stdc++.h>
using namespace std;

template <typename T>

class PrintMatrix {

public:
	PrintMatrix() {}
	
	void OneDMatrix(vector<T> arr, string str) {
		int n = arr.size();
		for(int i = 0; i < n; i++) {
			cout << arr[i] << str;
		}
	}
	
	void SquareMatrix(vector<vector<T>> arr) {
		int n = arr.size();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	void TwoDMatrix(vector<vector<T>> arr) {
		int n = arr.size();
		for(int i = 0; i < n; i++) {
			int x = int(arr[i].size());
			if(x == 0) {
				cout << "null";
			} else {
				for(int j = 0; j < x; j++) {
					cout << arr[i][j] << " ";
				}
			}
			cout << "\n";
		}
	}
};
