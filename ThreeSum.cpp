#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        map<vector<int>, int> mp;
        vector<vector<int>> results;
        
        sort(nums.begin(), nums.end());
        int i,ipre, jpre;
        
        for(i=0;i < nums.size() - 2; i++)
        {
            if(nums[i] >= 0)
                break;
            
            for(int j=i+1;j<nums.size() - 1; j++)
            {
                int target = (nums[i] + nums[j]) * -1;
                int low = j + 1, high = nums.size() - 1, mid = 0;

                if(target > nums[nums.size() - 1] || (jpre == nums[j] && ipre == nums[i]))
                    continue;

                while(low <= high){
                            
                    mid = (low+high)/2;

                    if(nums[mid] == target && mp[{nums[i], nums[j], nums[mid]}] < 1){
                        results.push_back({nums[i], nums[j], nums[mid]});
                        mp[{nums[i], nums[j], nums[mid]}] += 1;
                        break;
                    }

                    if(nums[mid] > target)
                        high = mid - 1;
                    else
                        low = mid + 1;

                    }

                    ipre = nums[i];
                    jpre = nums[j];
            }
        }

        int streak = 0;
        for(i=i; i < nums.size(); i++)
        {
            if(streak >= 3)
                break;

            if(nums[i] == 0)
                streak += 1;

            else if(nums[i] > 0)
                break;
        }

        if(streak >= 3)
            results.push_back({0, 0, 0});

        return results;
    }
};