class Solution {
public:
  vector<int>dp;
   int solve(vector<int>& nums , int n ,int idx ){
        if(idx>=n-1) return 0;
         int ans=1e9;

         if(nums[idx]==0) return 1e9;
         if(dp[idx]!=-1) return dp[idx];

        for(int i=1;i<=nums[idx];i++){
             ans=min(ans , 1+solve(nums , n , i+idx));
        }

       return  dp[idx]=ans;


   }
    int jump(vector<int>& nums) {
         int n=nums.size();
          dp.resize(n , -1);

        return solve(nums , n,0);
          
    }
};