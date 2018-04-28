/**
 * Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
 * Input: [1,3,5,4,7]
 * Output: 3
 * Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
 * Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
 */

#include <iostream>
#include <vector>

using namespace std;


int findLengthOfLCIS(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    int max_length = 1;
    int length = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] > nums[i-1])
        {
            length++;
            if(length > max_length)
            {
                max_length  = length;
            }
        } else
        {
            length = 1;
        }
    }
    return max_length;
}

int main()
{
    vector<int> nums({1,3,5,4,7,8,9});
    cout << "Longest continuous increasing subsequence is: " << findLengthOfLCIS(nums) << endl;
}
