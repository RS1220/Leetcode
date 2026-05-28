class Solution {
public:
   //m2 bottom up
      bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(10001 , false);
        dp[0]=true;
        for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                if(dp[j]==true && (j+nums[j]>= i)){
                    dp[i]=true;
                    break;
                }
             }
        }

        return dp[n-1];
        
    }
};