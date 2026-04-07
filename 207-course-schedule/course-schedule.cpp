class Solution {
public:
    //Solved by BFS
    //if topological order is there return true
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
     {  unordered_map<int, vector<int>>adj;
         vector<int>inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            inDegree[u]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) q.push(i);
        }
       vector<int>ans;
        while(!q.empty()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(int & neigh:adj[curr]){
                inDegree[neigh]--;
                if(inDegree[neigh]==0){
                    q.push(neigh);
                }

            }
        }

      if(ans.size()==numCourses) return true;
      return false;
    }
};