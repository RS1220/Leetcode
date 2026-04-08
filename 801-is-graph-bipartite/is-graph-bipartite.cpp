class Solution {
public:
    //dfs
    bool BFS(vector<vector<int>>& graph , int u ,vector<int>& color , int currColor){
        color[u]=currColor;
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
          for(int & v:graph[curr]){
            if(color[v]==color[curr]) return false;
            else if(color[v]==-1){
                color[v]=1-color[curr];
                q.push(v);
            }
        }
        }
        
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) 
    {   int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
         if(color[i]==-1){
            if(!BFS(graph , i,color , 0 )) return false;
         }
        }

        return true;
    }
};