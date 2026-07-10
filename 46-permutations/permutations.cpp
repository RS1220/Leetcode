class Solution {
public:
     //Backtracking
      vector<vector<int>> result;
      int n;
      unordered_set<int>st;

      void permutation(vector<int>& temp,vector<int>& nums){

        if(temp.size()==n) {
            result.push_back(temp);
            return ;
        }

         for(int i=0;i<n;i++){


            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);


                permutation(temp , nums);

                 temp.pop_back();
                 st.erase(nums[i]);


                
            }

            

         }

      }


    vector<vector<int>> permute(vector<int>& nums) {
         n=nums.size();

         vector<int>v;
         permutation(v,nums);

         return result;
        
    }
};