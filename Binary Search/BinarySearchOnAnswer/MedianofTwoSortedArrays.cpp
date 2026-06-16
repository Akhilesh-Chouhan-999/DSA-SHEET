#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {

            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0;
        int right = m;

        while (left <= right) {

            int partitionX = left + (right - left) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int x1 = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int x2 = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int y1 = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int y2 = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (x1 <= y2 && y1 <= x2) {

                if ((m + n) % 2 == 0) {

                    return (max(x1, y1) + min(x2, y2)) / 2.0;
                }

                return max(x1, y1);
            }

            else if (x1 > y2) {

                right = partitionX - 1;
            }

            else {

                left = partitionX + 1;
            }

        }

        return -1;
    }
};


int main() {

    Solution obj;

    vector<pair<vector<int>, vector<int>>> testCases = {
        {{1, 3}, {2}},
        {{1, 2}, {3, 4}},
        {{0, 0}, {0, 0}},
        {{}, {1}},
        {{2}, {}},
        {{1, 5, 8}, {2, 3, 7}}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        double ans = obj.findMedianSortedArrays(
            testCases[i].first,
            testCases[i].second
        );

        cout << ans << '\n';
    }

    return 0;
}

/*
    Time Complexity: O(log(min(m, n)))
    Space Complexity: O(1)
*/