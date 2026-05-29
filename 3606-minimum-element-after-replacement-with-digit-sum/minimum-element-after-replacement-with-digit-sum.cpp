class Solution {
public:
    int check(int n){
        int sum=0;
        while(n>0){
            int last=n%10;
            n/=10;
            sum+=last;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
         int n=nums.size();
         int ans=INT_MAX;
         for(int i=0;i<n;i++){
             int sum=check(nums[i]);
             if(sum<ans) ans=sum;
         }
         return ans;
    }
};