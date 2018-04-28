/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */

#include <iostream>
#include <vector>

using namespace std;


int searchInsert(vector<int>& nums, int target)
{
    int lower = 0;
    int upper = nums.size()-1;
    while (lower <= upper)
    {
        int middle = lower + (upper - lower)/2;
        if(nums[middle] == target)
            return middle;
        if(nums[middle] > target)
        {
            upper = middle-1;
        } else
        {
            lower = middle+1;
        }
    }
    if(target < nums[lower])
        return lower;
    else if(target < nums[upper])
        return lower+1;
    else
        return upper+1;
}


int main()
{
    vector<int> nums({1,3,5,6});
    cout << "index = " << searchInsert(nums, 4) << endl;
}
