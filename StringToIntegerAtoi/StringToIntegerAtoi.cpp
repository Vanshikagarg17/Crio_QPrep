#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
    int myAtoi(string &str) {
    	long long ans = 0;
		// pos is positive counter, neg is negative counter, dig means found digital?
        int pos = 0; int neg = 0; bool dig = false;
        for (const char& c:str) {
		   // according to the introduction, any character from a to z will cause return
            if (isalpha(c)) break;
			// if not character then deal with space,  any other char show will case return
            if (c == ' ') {
                if (dig || neg > 0 || pos > 0) break;
                continue;
            }
			// deal with +-.
            if (c == '+' || c == '-' || c == '.') {
			// any other character shows will cause return
                if (dig || neg > 0 || pos > 0) break;
                if (c == '+') {
                    pos++;
                } else if (c == '-') {
                    neg++;
                } else { break;} // .
                continue; // if found then next round
            }
            if (isdigit(c)) {
                dig = true;
                ans = ans * 10 + (c - '0');
            }
			// added by test case, to prevent overflow
            if (ans / 10 > INT_MAX) break;
        }
        if (ans > INT_MAX) {
            return neg ? INT_MIN : INT_MAX;
        }
        return neg ? -ans : ans;
    }
};

int main() {
	FastIO();
	string str;
	cin >> str;
	int result = StringToIntegerAtoi().myAtoi(str);
	cout << result;
	return 0;
}
