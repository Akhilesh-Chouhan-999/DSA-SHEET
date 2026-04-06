#include<bits/stdc++.h>
using namespace std ; 

class MyCalendarTwo {
public:

    map<int , int>events ; 

    MyCalendarTwo() {}
    
    bool book(int startTime, int endTime) {

        events[startTime] += 1 ;
        events[endTime]   -= 1 ;


        int cnt = 0 ; 

        for(auto it = events.begin() ; it != events.end() ; it ++){

            int type = it->second ; 

            cnt += type ; 

            if(cnt > 2){

                events[startTime] -= 1 ; 
                events[endTime] += 1 ; 

                if(events[startTime] == 0) events.erase(startTime) ; 
                if(events[endTime] == 0 ) events.erase(endTime) ; 
                return false ; 
            }
        }


        return true ;
    }
};

int main() {

    MyCalendarTwo myCalendarTwo;

    cout << boolalpha;

    vector<bool> expected = {true, true, true, false, true, true};

    vector<bool> actual;

    actual.push_back(myCalendarTwo.book(10, 20));
    actual.push_back(myCalendarTwo.book(50, 60));
    actual.push_back(myCalendarTwo.book(10, 40));
    actual.push_back(myCalendarTwo.book(5, 15));
    actual.push_back(myCalendarTwo.book(5, 10));
    actual.push_back(myCalendarTwo.book(25, 55));

    cout << "Actual vs Expected:\n";

    for(int i = 0; i < actual.size(); i++){
        cout << "Test " << i+1 << " -> "
             << "Actual: " << actual[i]
             << " | Expected: " << expected[i] << endl;
    }

    return 0;
}

// Time Complexity : O(Q*nlog(n))
// Space Complexity : O(2*Q)
