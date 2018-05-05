/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Given nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the returned length.
 */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int count = 0;
    int i = 0;
    while (i < nums.size())
    {
        int j = i;
        for ( ; j < nums.size() && nums[j] == nums[i]; ++j);

        nums[count++] = nums[j-1];
        i = j;
    }
    nums.resize(count);
    return count;
}

int main()
{
    vector<int> nums({1,1,2});
    cout << removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}