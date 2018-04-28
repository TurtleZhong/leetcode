/**
 * In a given integer array nums, there is always exactly one largest element.
 * Find whether the largest element in the array is at least twice as much as every other number in the array.
 * If it is, return the index of the largest element, otherwise return -1.
 *
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 */

#include <iostream>
#include <vector>

using namespace std;

int dominantIndex(vector<int>& nums)
{
    int max1,max2;
    int index;
    max1 = max2 = INT32_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > max2)
        {
            index = i;
            max1 = max2;
            max2 = nums[i];
        } else if(nums[i] > max1)
        {
            max1 = nums[i];
        }
    }
//    cout << "Max is: " << max2 << " " << max1 << endl;
    if(max2 / 2 >= max1)
        return index;
    else
        return -1;
}

int main()
{
    vector<int> nums({0, 0, 0, 1});
    cout << "Index is: " << dominantIndex(nums) << endl;
    return 0;
}