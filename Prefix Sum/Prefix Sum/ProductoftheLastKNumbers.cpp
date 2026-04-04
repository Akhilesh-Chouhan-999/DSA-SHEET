#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:

    vector<int>prefix ; 
    int lastZero = -1 ; 

    ProductOfNumbers() {}
    
    void add(int num) {

        if(prefix.empty() || (!prefix.empty() && prefix.back() == 0)){

            if(!prefix.empty()) lastZero = prefix.size() - 1 ; 
            prefix.push_back(num) ; 

        } else{
            prefix.push_back(prefix.back() * num) ; 
        }
    }
    
    int getProduct(int k) {

        int n = prefix.size() ; 
        int lastElements = n - k - 1 ;
        
        if(lastZero > lastElements){
            return 0 ; 
        }
        else if(lastZero == lastElements){
            return prefix.back() ; 
        }
        else{
            return prefix.back() / prefix[lastElements] ;
        }
         
    }
};


int main() {
    ProductOfNumbers* obj = new ProductOfNumbers();

    obj->add(3);
    obj->add(0);
    obj->add(2);
    obj->add(5);
    obj->add(4);

    cout << "getProduct(2): " << obj->getProduct(2) << " | Expected: 20" << endl;
    cout << "getProduct(3): " << obj->getProduct(3) << " | Expected: 40" << endl;
    cout << "getProduct(4): " << obj->getProduct(4) << " | Expected: 0" << endl;

    obj->add(8);

    cout << "getProduct(2): " << obj->getProduct(2) << " | Expected: 32" << endl;

    return 0;
}

// Time Complexity : O(1)
// Space Complexity : O(n)