class Solution {
public:
    int n,m;

    int dp[501][501][3];

    long long helper(vector<vector<int>>& coins,int i ,int j, int k){
        if(i==n-1 && j==m-1 ) {
            if(coins[i][j]<0 && k>0) return 0;
            return coins[i][j]; }
         if(i>=n || j>=m) return INT_MIN;
          
          if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];

         //take
          long long right=coins[i][j]+helper(coins ,i,j+1,k );
          long long down=coins[i][j]+helper(coins ,i+1,j,k );
          long long ans1=max(right,down);
         //skip 
         long long ans2=INT_MIN;
         if(coins[i][j]<0 && k>0){
          long long rightSkip=helper(coins ,i,j+1,k-1 );
          long long downSkip=helper(coins ,i+1,j,k-1 );
           ans2=max(rightSkip,downSkip);
         }

        return dp[i][j][k]=max(ans1 , ans2);

    }
    long long maximumAmount(vector<vector<int>>& coins) 
    {
        n=coins.size();
        m=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=INT_MIN;
                }
            }
        }
        return helper(coins,0,0,2);
    }
};