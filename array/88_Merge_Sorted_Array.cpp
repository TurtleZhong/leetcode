/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Example:
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * Output: [1,2,2,3,5,6]
 */

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int right = nums1.size() -1;
    m--;
    for (int i = n-1; i >=0; i--)
    {
        if(nums2[i] >= nums1[m])
        {
            nums1[right--] = nums2[i];
        } else
        {
            swap(nums1[right--],nums1[m]);
            m--;
        }
    }
}


int main()
{
    vector<int> nums1({1,2,3,0,0,0,0});
    vector<int> nums2({1,2,5,6});
    int m = 3;
    int n = 4;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); ++i)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
}