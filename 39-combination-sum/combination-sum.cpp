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
            f(candidates , target-candidates[idx] , idx,subset);//can take one ele many time
            subset.pop_back();

        }
      
        f(candidates , target , idx+1 ,subset);//incase of skip ans candidates[idx]>target
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         sort(candidates.begin() , candidates.end());
      vector<int>subset;
      f(candidates , target ,0,subset);
      return result;
         
        
    }
};