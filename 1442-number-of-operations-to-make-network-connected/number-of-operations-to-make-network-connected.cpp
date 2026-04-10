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

    int makeConnected(int n, vector<vector<int>>& connections) 
    {    parent.resize(n);
         for(int i=0;i<n;i++){
            parent[i]=i;
         }
         rank.resize(n,0);
        int ne=connections.size();
        int component=n;
        if(ne<n-1) return -1;
        for(int i=0;i<ne;i++){
            int parent_x=find(connections[i][0]);
            int parent_y=find(connections[i][1]);

            if(parent_x!=parent_y) { 

           
                Union(connections[i][0], connections[i][1]);
                component--;
            }
        }
        return component-1;
    }
};