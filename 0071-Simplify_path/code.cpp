#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            unordered_map<int, int> m;
            for(int i = 0; i<nums.size(); i++)
            {
                int complement = target - nums[i];
                if(m.find(complement) != m.end())
                {
                    return {m[complement], i};
                }
                else
                {
                    m[nums[i]] = i;
                }
            }
            return {};
        }
};