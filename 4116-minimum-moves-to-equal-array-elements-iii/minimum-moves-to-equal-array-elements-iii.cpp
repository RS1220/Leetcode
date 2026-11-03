class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int result=0;
        int n=nums[nums.size()-1];
        for(int i=0;i<nums.size()-1;i++){
            result+=abs(nums[i]-n);
        }
        return result;
        
    }
};