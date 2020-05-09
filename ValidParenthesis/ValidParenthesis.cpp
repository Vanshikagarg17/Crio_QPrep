#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class ValidParenthesis {
public:
    // Implement your solution by completing the below function	
    bool isValid(string s) {
	stack<char> st;
        for(int i = 0; i < int(s.size()); i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')')
                if(!st.empty()&&st.top()=='(')st.pop();
                else return false;
            else if(s[i]=='}')
                if(!st.empty()&&st.top()=='{')st.pop();
                else return false;
            else if(s[i]==']')
                {if(!st.empty()&&st.top()=='[')st.pop();
                else return false;
				}
        }
        return st.empty();
    }
};

int main() {
	FastIO();
	string s;
	getline(cin, s);
	bool result = ValidParenthesis().isValid(s);
	cout << boolalpha << result;
	return 0;
}
