/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    int zero_num = 0;
    int length = nums.size();


    for (int i = length-1; i >= 0 ; i--)
    {
        if(nums[i] == 0)
        {
            zero_num++;
            for (int j = i; j < length - zero_num; ++j)
            {
                nums[j] = nums[j+1];
            }
        }
    }

    for (int k = 0; k < zero_num; ++k)
    {
        nums[length-1-k] = 0;
    }

}

int main()
{
    int nums[5] = {0, 1, 0, 3, 12};
    vector<int> array;
    array.reserve(5);
    for (int i = 0; i < 5; ++i)
    {
        array.push_back(nums[i]);
    }
    moveZeroes(array);
    for (int j = 0; j < array.size(); ++j)
    {
        cout << array[j] << " ";
    }
    cout << endl;

    return 0;
}