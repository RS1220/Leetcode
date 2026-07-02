class Solution {
public:
    vector<vector<int>>direction={{0,1},{1,0},{0,-1},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>>q;
        vector<vector<int>>best(n , vector<int>(m,-1));
        int initialHealth=health-grid[0][0];
        if(initialHealth<1) return false;
       
        q.push({0,0,initialHealth});
        best[0][0]=initialHealth;
        while(!q.empty()){
            auto curr=q.front();
            int curri=curr[0];
            int currj=curr[1];
            int currk=curr[2];
             q.pop();

             if(curri==n-1 && currj==m-1) return true;
             for(auto &dir:direction){
                int newi=curri+dir[0];
                int newj=currj+dir[1];

                if(newi>=0 && newi<n && newj>=0 && newj<m){
                    int newhealth=currk-grid[newi][newj];
                   if(newhealth>=1 && newhealth>best[newi][newj]){
                       best[newi][newj]=newhealth;
                       q.push({newi, newj,newhealth});
                   }

                  
                  
                }

             }


        }
        return false;
    }
};