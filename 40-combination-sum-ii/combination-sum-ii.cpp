class Solution {
public:
    vector<vector<int>> ans;
    int n;
  
    void helper(vector<int>& candidates, vector<int>&v,int target,int idx){

        if(target==0){
            ans.push_back(v);
            return ;
        }
        if(target<0) return ;

        for(int i=idx ;i<n;i++){

            if( i>idx && candidates[i]==candidates[i-1]) continue;
            int a=candidates[i];
            v.push_back(a);
            helper(candidates , v , target-a , i+1);
             v.pop_back();

        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin() , candidates.end());
        n=candidates.size();
        vector<int>v;
        helper(candidates , v , target , 0);


        return ans;
    }
};