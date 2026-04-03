class Solution {
public:
    int  n;
    vector<int>dp;
    int helper(vector<int>& nums ,int idx){
        if(idx>=n) return INT_MIN;
        if(idx==n-1) return nums[idx];
        if(idx==n-2) return max(nums[idx],nums[idx+1]);
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+helper(nums,idx+2);
        int skip=helper(nums,idx+1);

        return dp[idx]= max(take , skip);
    }
    int rob(vector<int>& nums) 
    {
       n=nums.size(); 
       dp.resize(n,-1);
       return helper(nums ,0);
    }
};
