class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,int m,int n){
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1){
            return solve(i , j+1 ,m ,n);
        }
        else if(j==n-1){
            return solve(i+1 , j ,m ,n);
        }
       
          int right=solve(i , j+1 ,m ,n);
          int down=solve(i+1  , j,m ,n);
        
        return dp[i][j]=right+down;

    }
    int uniquePaths(int m, int n)
    {   dp.resize(m,vector<int>(n,-1));
        return solve(0,0,m,n);
    }
};