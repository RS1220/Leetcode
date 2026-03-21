class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k)
    {  
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
    ans=grid;
        int i=x;
       
        int i1=x+k-1;
        while(i<i1){
            for(int j=y;j<y+k;j++){
                swap(ans[i][j],ans[i1][j]);
            }

            i++;i1--;
        }
       return ans;
    }
};