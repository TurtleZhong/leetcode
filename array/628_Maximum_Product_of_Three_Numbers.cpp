/**
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.
 * Example:
 * Input: [1,2,3]
 * Output: 6
 *
 * Input: [1,2,3,4]
 * Output: 24
 *
 * Note:
 * The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 */

#include <iostream>
#include <vector>

using namespace std;

int maximumProduct(vector<int>& nums)
{
    int min1,min2,max1,max2,max3;
    min1 = min2 = INT32_MAX;
    max1 = max2 = max3 = INT32_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] < min2)
        {
            min1 = min2;
            min2 = nums[i];

        }
        else if(nums[i] < min1)
            min1 = nums[i];
        if(nums[i] > max3)
        {
            max1 = max2;
            max2 = max3;
            max3 = nums[i];
        } else if(nums[i] > max2)
        {
            max1 = max2;
            max2 = nums[i];
            cout << "max2 = " << max2 << endl;
        } else if(nums[i] > max1)
            max1 = nums[i];
    }
//    cout << min1 << " " << min2 << " "
//                                << max1 << " " << max2 << " " << max3 << endl;
    return max(max1*max2*max3, min1*min2*max3);
}

int main()
{
    vector<int> nums({-9,6,4,2,3,5,7,0,1});
    cout << "Max product = " << maximumProduct(nums) << endl;
    return 0;
}