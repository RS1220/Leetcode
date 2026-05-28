class Solution {
public:
    //M1 recursion+memo
    vector<int>dp;
    bool solve(vector<int>& nums , int n, int idx){
      if(idx==n-1) return true;
      if(dp[idx]!=-1) return dp[idx];
      for(int i=1;i<=nums[idx];i++){
         if(solve(nums , n, idx+i)==true) return true;
      }
      return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
      
        int n=nums.size();
          dp.resize(n , -1);
        return solve(nums , n , 0);
    }
};