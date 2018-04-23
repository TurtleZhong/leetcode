/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 * Example:
 * Input: [3,0,1]
 * Output: 2
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    vector<int> index(nums.size()+1, 0);
    for (int i = 0; i < nums.size(); ++i)
    {
        index[nums[i]] = 1;
    }
    for (int j = 0; j < index.size(); ++j)
    {
        if(!index[j])
            return j;
    }
}

int main()
{
    vector<int> nums({9,6,4,2,3,5,7,0,1});
    cout << "Missing num is: " << missingNumber(nums) << endl;
    return 0;
}