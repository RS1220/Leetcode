class Solution {
public:
     int n;
     vector<int>dp;
    int helper(vector<int>& nums , int idx){
        if(idx>=n) return 0;
         if(idx==n-1) return nums[n-1];
         if(idx==n-2) return max(nums[n-2] , nums[n-1]);
        if(dp[idx]!=-1) return dp[idx] ;

        int rob=nums[idx]+helper(nums , idx+2);
        int skip=helper(nums , idx+1);

        return dp[idx]=max(rob , skip);
        

    }
    int rob(vector<int>& nums) {
 
         n=nums.size();
         dp.resize(n,-1);
        return helper(nums , 0);
        
    }
};