/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 * Output:
 * [5,6]
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> results;
    if(nums.empty())
        return results;
    int nums_length = nums.size();
    vector<int> flag(nums_length, -1);

    for (int i = 0; i < nums_length; ++i)
    {
        flag[nums[i] - 1] = 1;
    }
    for (int j = 0; j < nums_length; ++j)
    {
        if(flag[j] < 0)
            results.push_back(j+1);
    }
    return results;
}

int main()
{
    int array[] = {4,3,2,7,8,2,3,1};
    vector<int> nums(array, array+8);
    vector<int> results = findDisappearedNumbers(nums);
    for (int i = 0; i < results.size(); ++i)
    {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}
