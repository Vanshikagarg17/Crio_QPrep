#include<bits/stdc++.h>
using namespace std;

template <typename T>

class ReadMatrix {

public:
	ReadMatrix() {}
	
	void OneDMatrix(int n, vector<T>& arr) {
		arr.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
	}
	
	void SquareMatrix(int n, vector<vector<T>>& arr) {
		arr.resize(n);
		for(int i = 0; i < n; i++) {
			vector<T> brr(n);
			for(int j = 0; j < n; j++) {
				cin >> brr[j];
			}
			arr[i] = brr;
		}
	}
	
	void TwoDMatrix(int n, int m, vector<vector<T>>& arr) {
		arr.resize(n);
		for(int i = 0; i < n; i++) {
			vector<T> brr(m);
			for(int j = 0; j < m; j++) {
				cin >> brr[j];
			}
			arr[i] = brr;
		}
	}
};
