#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
public:

    unordered_map<int , int> freqVotes ; 
    vector<pair<int ,int>>mostVotedCandidate ; 

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {

        int person = persons[0] ; 
        int time = times[0] ; 
        int leader = persons[0] ; 

        mostVotedCandidate.push_back({time , leader}) ; 
        freqVotes[leader] = 1 ; 


        for(int i = 1 ; i < persons.size() ; i ++){

            int person = persons[i] ; 
            int time = times[i] ; 
            freqVotes[person] ++ ; 


            int prevFreq = freqVotes[leader] ; 
            int currFreq = freqVotes[person] ; 

            if(currFreq >= prevFreq){
                leader = person ; 
            }

            mostVotedCandidate.push_back({time , leader }) ; 

        }
       

    }
    
    int q(int t) {

        int low = 0 ; 
        int high = mostVotedCandidate.size() - 1 ; 
        int result = mostVotedCandidate[0].second ; 

        while(low <= high){

            int mid = low + ( high - low ) / 2 ; 

            int time = mostVotedCandidate[mid].first ; 
            int candidate = mostVotedCandidate[mid].second ; 


            if(time == t)
            return candidate ; 

            else if(time > t){
                high = mid - 1 ; 
            }

            else{
                result = candidate ; 
                low = mid + 1 ; 
            }
        }

        return result ; 

    }
};

int main() {
    vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
    vector<int> times = {0, 5, 10, 15, 20, 25, 30};

    TopVotedCandidate* obj = new TopVotedCandidate(persons, times);

    cout << obj->q(3) << endl;   // expected 0
    cout << obj->q(12) << endl;  // expected 1
    cout << obj->q(25) << endl;  // expected 1
    cout << obj->q(15) << endl;  // expected 0
    cout << obj->q(24) << endl;  // expected 0
    cout << obj->q(8) << endl;   // expected 1

    return 0;
}
// Time Complexity : o(Q*(log(n) + N))
// Space Commplexity : O(n)