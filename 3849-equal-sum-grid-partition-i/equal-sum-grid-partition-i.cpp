class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {   int n=grid.size();
        int m=grid[0].size();
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }

        //row
       long long prevSum=0;
       long long nextSum=sum;
        for(int i=0;i<n-1;i++){
            long long rowSum=0;
            for(int j=0;j<m;j++){
               rowSum+=grid[i][j];
            }
            prevSum+=rowSum;
            nextSum-=rowSum;
            if(prevSum==nextSum) return true;

        }

          prevSum=0;
          nextSum=sum;
        for(int j=0;j<m-1;j++){
            long long colSum=0;
            for(int i=0;i<n;i++){
               colSum+=grid[i][j];
            }
            prevSum+=colSum;
            nextSum-=colSum;
            if(prevSum==nextSum) return true;

        }
        return false;
    }
};