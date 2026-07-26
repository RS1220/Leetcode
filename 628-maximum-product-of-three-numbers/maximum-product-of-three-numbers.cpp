class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        if(n==3) return nums[0]*nums[1]*nums[2];
        sort(nums.begin() , nums.end());
      
        if(nums[0]>=0){
            return nums[n-1]*nums[n-2]*nums[n-3];
        }

        
            int p1=nums[0]*nums[1]*nums[2];
            int p2=nums[0]*nums[1]*nums[n-1];
            int p3=nums[0]*nums[n-1]*nums[n-2];
            int p4=nums[n-1]*nums[n-2]*nums[n-3];

            int x=max(p3,p4);
            int y=max(x,p2);

        
        return max(p1 , y);

        
        
    }
};