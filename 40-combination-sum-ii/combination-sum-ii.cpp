class Solution {
public:
     vector<vector<int>> result;

     void f(vector<int>& candidates, int target , int idx , vector<int>subset){
        if(target==0){
            result.push_back(subset);
            return ;
        }
        if(idx==candidates.size()) return;

        if(candidates[idx]<=target){

            subset.push_back(candidates[idx]);
            f(candidates , target-candidates[idx] , idx+1,subset);
            subset.pop_back();

        }
        int j=idx+1;
        while(j<candidates.size() && candidates[j]==candidates[j-1]) j++;//if we ship one repeating number then we have to skip all repeating
        f(candidates , target , j ,subset);//incase of skip ans candidates[idx]>target
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin() , candidates.end());
      vector<int>subset;
      f(candidates , target ,0,subset);
      return result;
        
    }
};