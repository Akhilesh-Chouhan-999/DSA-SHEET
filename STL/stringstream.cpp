#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize(const string &line, char delimiter) {
    
   vector<string>tokens ; 

   stringstream ss(line) ; 

   string temp ; 

   while(getline(ss , temp , delimiter)){
    tokens.push_back(temp) ; 
   }
   
   return tokens ; 
}

int main() {
    
    string line = "GeeksForGeeks is a must try";

    vector<string> result = tokenize(line, ' ');

    for(string word : result) {
        cout << word << "\n";
    }
}