class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& grid,int i, int j)
    {    if(i>n || j>m) return 0;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1){
            //call only right
            return dp[i][j]=grid[i][j]+helper(grid,i,j+1);
        }
        else if(j==m-1){
            //go only down
            return dp[i][j]=grid[i][j]+helper(grid,i+1,j);
        }
       
        else return dp[i][j]=grid[i][j]+min(helper(grid,i,j+1),helper(grid,i+1,j));
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
          n=grid.size();
          m=grid[0].size();
          dp.resize(n,(vector<int>(m,-1)));
         return helper(grid,0,0);
    }
};