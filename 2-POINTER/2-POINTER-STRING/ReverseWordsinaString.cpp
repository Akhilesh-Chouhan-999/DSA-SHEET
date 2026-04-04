#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    string reverseWords(string s) {

        int n = s.length() ;

        int j = n - 1 ; 
        string result = "" ; 

        while(j >= 0){

            while( j >= 0 && s[j] == ' ') j -- ; 

            if( j < 0) break;

            int i = j ; 

            while( i >= 0 && s[i] != ' ') i -- ; 

            string word = s.substr( i + 1 , j - i ) ; 

            if(!result.empty()) result += " " ;
            result += word ; 

            j = i ;

        }


        return result ; 

    }
};

int main() {

    Solution obj;

    vector<string> testCases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "  Bob    Loves  Alice   ",
        "Alice does not even like bob"
    };

    for(string s : testCases) {
        cout << "Input  : \"" << s << "\"" << endl;
        cout << "Output : \"" << obj.reverseWords(s) << "\"" << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)