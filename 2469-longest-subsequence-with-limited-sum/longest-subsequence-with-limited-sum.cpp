class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin() ,  nums.end());
      
        int m=queries.size();
             
          vector<int>prefixSum(n);
         vector<int>ans;
         prefixSum[0]=nums[0];
         for(int i=1;i<n;i++){
            prefixSum[i]=nums[i]+prefixSum[i-1];
         }
          int len=0;
         for(int i=0;i<m;i++)//for queries
         {  int len=0;
            for(int j=0;j<n;j++){
                if(prefixSum[j]>queries[i]) break;
                else len++;
            }
            ans.push_back(len);
         }
           
      return ans;

        
    }
};