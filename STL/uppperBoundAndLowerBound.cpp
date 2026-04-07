#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ; 

int main(){

    vector<int> vec = {1,2,4,4,5}; 

    /*
    lower_bound:
    → returns iterator to FIRST element >= target
    → if target not found, gives position where it can be inserted
    → check: if(it == end OR *it != target) → NOT FOUND
    */

    auto lb = lower_bound(vec.begin(), vec.end(), 4);
    cout << "LB Index: " << lb - vec.begin() << endl;

    /*
    upper_bound:
    → returns iterator to FIRST element > target
    → last occurrence index = (upper_bound - 1)
    → if target not found → lb == ub
    */

    auto ub = upper_bound(vec.begin(), vec.end(), 4);
    cout << "UB Index: " << ub - vec.begin() << endl;

   
    return 0 ; 
}