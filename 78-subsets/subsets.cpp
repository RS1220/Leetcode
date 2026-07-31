class Solution {
public:
  int n;
    void helper(vector<int>& nums , vector<int>v ,  vector<vector<int>>& ans , int idx){

       
            ans.push_back(v);
           
        

      for(int i=idx;i<n;i++){
        v.push_back(nums[i]);
        helper(nums , v ,ans , i+1);
        v.pop_back();
      }
        

    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {   n=nums.size();
         vector<int>v;
          vector<vector<int>>ans;
          helper(nums , v ,ans , 0);

          return ans;
    }
};