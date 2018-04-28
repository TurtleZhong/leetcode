/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Method 0
 * @param nums
 * @return
 */
int maxSubArray(vector<int>& nums)
{
    int res = INT32_MIN, curSum = 0;
    for (int num : nums) {
        curSum = max(curSum + num, num);
        res = max(res, curSum);
    }
    return res;
}

/**
 * Method 1
 * @param nums
 * @return
 */
int maxSubArra_1(vector<int>& nums)
{
    int res = INT32_MIN, curSum = 0;
    for (int num : nums) {
        curSum = max(curSum + num, num);
        res = max(res, curSum);
    }
    return res;
}

int main()
{
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    cout << "max sum is: " << maxSubArray(nums) << endl;
}