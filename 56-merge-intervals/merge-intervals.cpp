class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin() , intervals.end());
         vector<vector<int>> result;
        vector<int>ans(2);

        int v1=intervals[0][0];
        int v2=intervals[0][1];
        for(int i=1;i<n;i++)
        {
           int n1=intervals[i][0];
           int n2=intervals[i][1];

           if(n1<=v2){
            v1=min(n1,v1);
            v2=max(v2,n2);
           }

           else {

            ans[0]=v1;
            ans[1]=v2;
            result.push_back(ans);
            v1=n1;
            v2=n2;

           }
        }

        // vector<int>m=result.back();
        // if(m[0]==v1 && m[1]==v2) return result;
        ans[0]=v1;
        ans[1]=v2;
        result.push_back(ans);


        return result;

    }
};