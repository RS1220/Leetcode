class Solution {
public:
    bool check(vector<int>& nums) {

        int n=nums.size();
        int pivot=-1;
        for(int i=0;i<n-1;i++){

          if(nums[i]>nums[i+1]) {
                pivot=i;
                break;
          }
          
          
        }

        if(pivot==-1)  return  is_sorted(nums.begin() , nums.end())?true:false;


        reverse(nums.begin() , nums.begin()+pivot+1);
        reverse(nums.begin()+pivot+1 , nums.end());

        reverse(nums.begin()  , nums.end());

      return  is_sorted(nums.begin() , nums.end())?true:false;
        
        

        
    }
};