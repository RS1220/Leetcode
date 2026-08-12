class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int n=nums.size();
        int maxlen=0;
        int i=0;
        int j=0;
        while(j<n){
            mp[nums[j]]++;
             
            while(i<j && mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            maxlen=max(maxlen , j-i+1);
            j++;
            
            
        }
        return maxlen;
    }
};