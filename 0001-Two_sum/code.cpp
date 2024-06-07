#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++)
        {
            int compliment = target-nums[i];
            if(mp.find(compliment)!=mp.end())
            return {i, mp[compliment]};

            else
            mp[nums[i]] = i;
        }
        return {-1};
    }
};