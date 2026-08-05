class Solution {
public:
    bool check(unordered_map<int , vector<int>>&adj,vector<bool>&visited ,int u){
        for(auto v:adj[u]){
            if(visited[v]==true) return true;
        }

        return false;
    }
    void dfs(  unordered_map<int , vector<int>>&adj,vector<bool>&visited ,int u ){
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(adj , visited , v);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int , vector<int>>adj;
        for(int i=0;i<invocations.size();i++){
           int u=invocations[i][0];
           int v=invocations[i][1];

           adj[u].push_back(v);

        }
        vector<bool>visited(n , false);
        dfs(adj , visited , k);

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false){
               if( check(adj , visited , i) ) return ans;
            }
        }

        vector<int>ans1;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans1.push_back(i);
            }
        }
        return ans1;
        
    }
};