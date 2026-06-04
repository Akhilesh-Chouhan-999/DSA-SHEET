/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length();

        stack<int> st;
        st.push(-1);

        int maxLength = INT_MIN;

        for(int i = 0; i < n; i ++) {

            char currChar = s[i];

            if(currChar == '(') {

                st.push(i);
            }

            else {

                st.pop();

                if(st.empty()) {

                    st.push(i);
                }
                else {

                    int length = i - st.top();
                    maxLength = max(maxLength, length);
                }
            }
        }

        if(maxLength == INT_MIN) {

            return 0;
        }

        return maxLength;
   }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "(()";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s1) << endl; // Expected: 2
    cout << "--------------------------------" << endl;

    // Test Case 2
    string s2 = ")()())";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s2) << endl; // Expected: 4
    cout << "--------------------------------" << endl;

    // Test Case 3
    string s3 = "";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s3) << endl; // Expected: 0
    cout << "--------------------------------" << endl;


    return 0;

}

    Time Complexity : O(n)
    Space Complexity : O(n)
*/
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length();

        stack<int> st;
        st.push(-1);

        int maxLength = INT_MIN;

        for(int i = 0; i < n; i ++) {

            char currChar = s[i];

            if(currChar == '(') {

                st.push(i);
            }

            else {

                st.pop();

                if(st.empty()) {

                    st.push(i);
                }
                else {

                    int length = i - st.top();
                    maxLength = max(maxLength, length);
                }
            }
        }

        if(maxLength == INT_MIN) {

            return 0;
        }

        return maxLength;
   }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "(()";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s1) << endl; // Expected: 2
    cout << "--------------------------------" << endl;

    // Test Case 2
    string s2 = ")()())";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s2) << endl; // Expected: 4
    cout << "--------------------------------" << endl;

    // Test Case 3
    string s3 = "";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s3) << endl; // Expected: 0
    cout << "--------------------------------" << endl;


    return 0;

}

    Time Complexity : O(n)
    Space Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {

        int n = s.length();

        int open = 0;
        int close = 0;

        int maxLength = INT_MIN;

        for(char &ch : s) {

            ch == '(' ? open ++ : close ++;

            if(close > open) {

                close = open = 0;
            }
            else if(close == open) {

                int length = open + close;
                maxLength = max(maxLength, length);
            }
        }


        reverse(begin(s), end(s));
        open = 0;
        close = 0;

        for(char &ch : s) {

            ch == '(' ? open ++ : close ++;

            if(close > open) {

                close = open = 0;
            }
            else if(close == open) {

                int length = open + close;
                maxLength = max(maxLength, length);
            }
        }


        if(maxLength == INT_MIN) {

            return 0;
        }

        return maxLength;
   }
};


int main() {
    Solution sol;

    // Test Case 1
    string s1 = "(()";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s1) << endl; // Expected: 2
    cout << "--------------------------------" << endl;

    // Test Case 2
    string s2 = ")()())";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s2) << endl; // Expected: 4
    cout << "--------------------------------" << endl;

    // Test Case 3
    string s3 = "";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: " << sol.longestValidParentheses(s3) << endl; // Expected: 0
    cout << "--------------------------------" << endl;


    return 0;

}