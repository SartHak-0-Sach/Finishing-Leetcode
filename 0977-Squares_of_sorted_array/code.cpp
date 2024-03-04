#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(std::vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int index = right;

        while (left <= right)
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right]; // mentioned code is of 2 pointer approach, can also be solved using radix sort and the brute force method of sorting

            if (leftSquare > rightSquare)
            {
                ans[index--] = leftSquare;
                left++;
            }
            else
            {
                ans[index--] = rightSquare;
                right--;
            }
        }
        return ans;
    }
};