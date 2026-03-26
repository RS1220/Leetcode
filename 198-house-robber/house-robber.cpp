class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums , int idx)
    {
        if(idx==nums.size()-1) return nums[idx];
        else if(idx==nums.size()-2) return max(nums[idx],nums[idx+1]);
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(solve(nums,idx+1),(nums[idx]+solve(nums,idx+2)));


    }
    int rob(vector<int>& nums) 
    {   dp.resize(nums.size(),-1);
        return solve(nums,0);
    }
};