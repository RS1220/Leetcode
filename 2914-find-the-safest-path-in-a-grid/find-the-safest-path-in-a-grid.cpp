class Solution {
public:
    vector<vector<int>> direction={{0,1},{1,0} ,{0,-1},{-1,0}  };
    bool check(vector<vector<int>>& distToThief , int mid){
        int n=distToThief.size();
        if(distToThief[0][0]<mid) return false;
         queue<pair<int , int>>q;
        vector<vector<bool>>visited(n , vector<bool>(n,false));
        q.push({0,0});
        visited[0][0]=true;
          
        while(!q.empty()){
             int curr_i=q.front().first;
                int curr_j=q.front().second;

                q.pop();
                
                if(curr_i==n-1 && curr_j==n-1) return true;

               
                for(auto &dir:direction){
                       int new_i=curr_i+dir[0];
                       int new_j=curr_j+dir[1];

                       if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && visited[new_i][new_j]==false  && distToThief[new_i][new_j] >= mid){
                        
                        q.push({new_i , new_j});
                        visited[new_i][new_j]=true;
                       }

                }

        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>distToThief(n , vector<int>(n,-1));
        queue<pair<int , int>>q;
        vector<vector<bool>>visited(n , vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                   if(grid[i][j]==1){
                        q.push({i,j});
                        visited[i][j]=true;
                   }
            }
        }

        int level=0;
        while(!q.empty()){

            int s=q.size();
            while(s--){
                int curr_i=q.front().first;
                int curr_j=q.front().second;
                q.pop();

                distToThief[curr_i][curr_j]=level;
                for(auto &dir:direction){
                       int new_i=curr_i+dir[0];
                       int new_j=curr_j+dir[1];

                       if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && visited[new_i][new_j]==false ){
                        q.push({new_i , new_j});
                        visited[new_i][new_j]=true;
                       }

                }

            }
            level++;
        }
        int result=0;
        int lo=0;int hi=2*(n-1);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(distToThief , mid)){
                result=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
      return result;
        
    }
};