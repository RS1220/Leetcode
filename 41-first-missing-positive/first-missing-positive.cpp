class Solution {
public:
    //tc O(n) SC O(n)
    int firstMissingPositive(vector<int>& nums) {
         unordered_map<int ,int>mp;
         int n=nums.size();
         for(int i=0;i<n;i++){
            mp[nums[i]]=1;
         }

         for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()) return i;
         }
         return n+1;
    }
};