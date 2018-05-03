/**
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value.
 * And you need to output the maximum average value.
 *
 * Example 1:
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 */

#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k)
{
    double sums = 0;
    for (int i = 0; i < k; ++i)
    {
        sums+=nums[i];
    }

    double average = sums / k;
    cout << "average = " << average << endl;
    for (int l = 0, r = k; r < nums.size(); ++r, ++l)
    {
        sums += nums[r] - nums[l];
        if(sums  / k > average)
            average = sums / k;
    }
    return average;
}

int main()
{
    vector<int> nums({1,12,-5,-6,50,3});
    cout << findMaxAverage(nums, 4) << endl;
    
}