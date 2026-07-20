class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int len=n*m;
        k=k%len;
        vector<int>nums(len);
        int x=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums[x++]=grid[i][j];
            }
        }

       

        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());

         int r=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=nums[r];
                r++;
            }
        }
        return grid;
    

    }
};