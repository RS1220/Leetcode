class Solution {
public:
    typedef pair<int , pair<int , int>>p;
    int n,m;
    bool safe(int i , int j,vector<vector<int>>& heights){
      if(i>=0 && i<n && j>=0 && j<m ) return true;
      return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) 

    {  n=heights.size();
       m=heights[0].size();
        vector<vector<int>> directions={{0,1},{1,0} ,{0,-1},{-1,0}};
         vector<vector<int>>result(n , vector<int>(m,INT_MAX));
        priority_queue<p , vector<p> , greater<p>>pq;
        pq.push({0,{0,0}});
        result[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int diff=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            for(auto & dir:directions){
                 int x1=x+dir[0];
                 int y1=y+dir[1];
                 if(safe(x1,y1,heights)){
                    int newdiff=abs(heights[x1][y1]-heights[x][y]);
                    int maxdiff=max(newdiff , diff);
                    if(result[x1][y1] > maxdiff){
                       result[x1][y1] = maxdiff;
                       pq.push({maxdiff , {x1,y1}});
                    }
                 }
            }
        }
        return result[n-1][m-1]==INT_MAX?-1:result[n-1][m-1];
    }
};