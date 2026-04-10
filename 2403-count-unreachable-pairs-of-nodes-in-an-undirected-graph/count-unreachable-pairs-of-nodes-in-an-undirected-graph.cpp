class Solution {
public:
   vector<int>parent;
     vector<int>rank;

    int find(int i){
        if(i==parent[i]) return i;

        return parent[i]=find(parent[i]);
    }

    void Union(int x , int y)
    {
        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x== parent_y) return;
        if(rank[ parent_x]>rank[ parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[ parent_x]<rank[ parent_y]){
            parent[parent_x]=parent_y;
        }
        else{
           
            parent[parent_x]=parent_y;
            rank[parent_y]++;
            
        }
       return ;
    }
    long long countPairs(long long n, vector<vector<int>>& edges)
    {   parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<edges.size();i++){
            Union(edges[i][0] ,edges[i][1] );
        }
         

    unordered_map<int , int>mp;

    for(int i=0;i<n;i++){
        int p=find(i);
        mp[p]++;
    }
    long long ans=0;
    for(auto &p:mp){
          
          ans+=(p.second*(n-p.second));
          n=n-p.second;
          
    }
    return ans;
    }
};