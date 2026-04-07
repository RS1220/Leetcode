class Solution {
public:
    bool isCycle(unordered_map<int ,vector<int>>& adj , int u ,  vector<bool>& visited,
        vector<bool>& inRecursion){
            visited[u]=true;
            inRecursion[u]=true;

            for(int &neigh: adj[u]){
                if(visited[neigh] && inRecursion[neigh]) return true;
                else if(!visited[neigh]){
                    if(isCycle(adj , neigh ,visited,inRecursion )) return true;
                }
            }
             inRecursion[u]=false;

        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int ,vector<int>>adj;
        for(auto & s:prerequisites){
            int u=s[0];
            int v=s[1];

            adj[v].push_back(u);

        }

        vector<bool>visited(numCourses , false);
        vector<bool>inRecursion(numCourses , false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(isCycle(adj , i , visited ,inRecursion )) return false;
            }
        }
        return true;
    }
};