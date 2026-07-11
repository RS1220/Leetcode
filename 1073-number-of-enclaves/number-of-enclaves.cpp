class Solution {
public:
    int n ,m;

    void dfs(vector<vector<int>>& grid, int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;

    if(grid[i][j] == 0)
        return;

    grid[i][j] = 0;

    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
}
    int numEnclaves(vector<vector<int>>& grid) {
       n=grid.size();
       m=grid[0].size();

      for(int i=0;i<m;i++){

        if(grid[0][i]==1){
            dfs(grid , 0 ,i);
        }

      }

      for(int i=0;i<m;i++){

        if(grid[n-1][i]==1){
            dfs(grid , n-1 ,i);
        }

      }

      for(int i=1;i<n-1;i++){

        if(grid[i][0]==1){
            dfs(grid ,i, 0 );
        }

      }
      for(int i=1;i<n-1;i++){

        if(grid[i][m-1]==1){
            dfs(grid , i ,m-1);
        }

      }

      int ans=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)ans++;
        }
      }
    return ans;
        
    }
};