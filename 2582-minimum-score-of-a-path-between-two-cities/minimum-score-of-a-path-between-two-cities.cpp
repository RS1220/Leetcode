class Solution {
public:
    void dfs(int u ,  unordered_map<int , vector<pair<int,int>>>&adj ,vector<bool>&visited  , int & ans){


        visited[u]=true;
        for(auto neigh:adj[u]){
            int v=neigh.first;
            int w=neigh.second;
             ans=min(ans , w);
            if(!visited[v]){
                
                dfs(v,adj,visited , ans);
            }
        }

       
    }
    int minScore(int n, vector<vector<int>>& roads) {
      
        unordered_map<int , vector<pair<int,int>>>adj;
       
        for(auto &road:roads){
            int u=road[0];
             int v=road[1];
              int w=road[2];

              adj[u].push_back({v,w});
              adj[v].push_back({u,w});
        }

        vector<bool>visited(n,false);
        int ans=INT_MAX;
         dfs(1,adj , visited , ans);

       return ans;
        
    }
};