class Solution {
public:
  bool hasCycle;
    void DFS(unordered_map<int ,vector<int>>& adj , int u ,  vector<bool>& visited,
        vector<bool>& inRecursion , stack<int>& st){
            visited[u]=true;
            inRecursion[u]=true;
            
            for(int &neigh: adj[u]){
                 if( inRecursion[neigh]) {
                    hasCycle=true;
                    return;
                 }
                 else if(!visited[neigh]){
                    (DFS(adj , neigh ,visited,inRecursion,st ));
                }
            }
             st.push(u);
             inRecursion[u]=false;

     

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int ,vector<int>>adj;
        for(auto & s:prerequisites){
            int u=s[0];
            int v=s[1];

            adj[v].push_back(u);

        }
      hasCycle=false;

       stack<int>st;
       vector<bool>visited(numCourses , false);
       vector<bool>inRecursion(numCourses , false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                DFS(adj , i , visited,inRecursion , st);
            }
        }    
        if(hasCycle==true) return {};
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    return ans;
    }
};