/**
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 * Example 1:
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * Example 2:
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findShortestSubArray(vector<int>& nums)
{
    unordered_map<int,int> count;
    unordered_map<int, pair<int,int> > index;
    int degree = 0;
    int res = INT32_MAX;
    for (int i = 0; i < nums.size(); ++i)
    {
        if(!count.count(nums[i]))
        {
            count[nums[i]] = 1;
            index[nums[i]] = make_pair(i,i);
        } else
        {
            count[nums[i]]++;
            index[nums[i]].second = i;
            degree = max(degree, count[nums[i]]);
        }
    }
    for (int j = 0; j < count.size(); ++j)
    {
        if(count[j] == degree)
            res = min(res,index[j].second - index[j].first + 1);
    }

    cout << "degree = " << res << endl;
    return 0;
}

int main()
{
    int array[] = {1,2,2,3,1,4,2};
    vector<int> nums(array, array+ sizeof(array)/ sizeof(array[0]));
    findShortestSubArray(nums);
    return 0;
}

