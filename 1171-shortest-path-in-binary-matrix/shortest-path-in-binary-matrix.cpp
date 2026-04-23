class Solution {
public:
    typedef pair<int , pair<int ,int>>p;
    int n,m;
    bool safe(int i,int j ,vector<vector<int>>& grid){
        if(i>=0 && i<n&& j>=0 && j<m && grid[i][j]!=1) return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {     n=grid.size();
          m=grid[0].size();
         vector<vector<int>>result(n ,vector<int>(m,INT_MAX));

         priority_queue<p , vector<p> , greater<p>>pq;
         vector<vector<int>> directions = {
    {0, 1},   // right
    {1, 0},   // down
    {-1, 0},  // up
    {0, -1},  // left
    {1, 1},   // down-right
    {1, -1},  // down-left
    {-1, 1},  // up-right
    {-1, -1}  // up-left
};

         if(grid[0][0]==1) return -1;
         grid[0][0]=1;
         result[0][0]=1;
         pq.push({1,{0 , 0}});
         while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int d=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            for(auto &dir:directions){
                int x1=x+dir[0];
                int y1=y+dir[1];
                int dist=d+1;
                if(safe(x1, y1,grid)){
                    if(result[x1][y1]>dist){
                     result[x1][y1]=dist ; 
                     grid[x1][y1]=1;
                    pq.push({dist , {x1,y1}});
                    }
                    
                }
            }
         }
        return result[n-1][m-1] == INT_MAX ? -1 : result[n-1][m-1];
    }
};