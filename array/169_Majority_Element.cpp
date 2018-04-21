/**
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;
/**
 * time:O(n),space:O(n)
 * @param nums
 * @return
 */
int majorityElement(vector<int>& nums)
{
    map<int,int> hash_table;
    if(nums.size()==1)
        return nums[0];
    for (int i = 0; i < nums.size(); ++i)
    {
        if(hash_table.count(nums[i]))
        {
            hash_table[nums[i]]++;
            if(hash_table[nums[i]] > nums.size() / 2)
                return nums[i];
        } else
        {
            hash_table[nums[i]] = 1;
        }
    }
}

/**
 * time:O(n),space:O(1)
 * @param nums
 * @return
 */
int majorityElementOptimal(vector<int>& nums)
{
    int count=0;
    int result=nums[0];
    for(int i=0;i<nums.size();i++)
    {
        if(count==0||nums[i]==result)
        {
            count++;
            result=nums[i];
        }
        else
            count--;
    }
    return result;
}

int main()
{
    int array[] = {2,2,4,2,5,2};
    int array_size = sizeof(array)/ sizeof(array[0]);
    cout << "array.size = " << array_size << endl;
    vector<int>nums(array, array+array_size);

    cout << majorityElementOptimal(nums) << endl;
}