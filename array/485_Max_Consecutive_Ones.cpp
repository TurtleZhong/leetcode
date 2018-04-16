/**
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * Example
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 * The maximum number of consecutive 1s is 3.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
    vector<int> counts;
    int prev_zero = -1;
    int curr_zero = 0;
    nums.push_back(0);
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0)
        {
            curr_zero = i;
            counts.push_back(curr_zero - prev_zero - 1);
            prev_zero = curr_zero;
        }

    }
    nums.pop_back();
    sort(counts.begin(), counts.end());
    return counts[counts.size() - 1];
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    cout << findMaxConsecutiveOnes(nums) << endl;
}
