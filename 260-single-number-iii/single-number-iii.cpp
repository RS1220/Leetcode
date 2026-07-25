class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        //take xor of all so we get xor of unique element
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        //to get rightost set bit
        long long mask=ans & -ans;
        int a,b;
        a=b=0;
        for(int num:nums){
          if(num&mask){
            a^=num;
          }
          else b^=num;
        }

        return {a,b};
        
    }
};