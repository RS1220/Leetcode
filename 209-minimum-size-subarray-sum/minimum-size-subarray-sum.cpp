class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int i=0;
        int j=0;
        int sum=0;
        int minLen=INT_MAX;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                int len=j-i+1;
                minLen=min(minLen , len);
                sum-=nums[i];
                i++;
            }
            j++;
        }

        return minLen==INT_MAX?0:minLen;
    }
};