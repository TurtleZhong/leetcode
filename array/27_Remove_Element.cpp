/**
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int length = nums.size();
    auto iter = nums.begin();
    for (int i = nums.size()-1; i >=0; i--)
    {
        if(nums[i] == val)
        {
            length--;
            nums.erase(iter + i);
        }

    }
    return length;
}

int main()
{
    vector<int> nums({3, 2, 2, 1, 3, 4});
    cout << "length = " << removeElement(nums, 2) << endl;
    cout << "[ ";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}