class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n=gain.size();
        vector<int>ans(n+1);
        ans[0]=0;
        ans[1]=gain[0];
        int result=max(ans[0] , ans[1]);
        for(int i=1;i<n;i++){
            ans[i+1]=ans[i]+gain[i];

            if(ans[i+1]>result) result=ans[i+1];
        }

       return result;
        
    }
};