class Solution {
public:
    void solve(vector<int>& nums, int i , int j){

        while(i<=j){
            swap(nums[i],nums[j]);
            i++;j--;
        }

    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==2 && k==1) {
            swap(nums[0] , nums[1]);
            return;
        }
        k=k%n;
        int m=n-k-1;
      
        solve(nums ,0, m);
        solve(nums ,m+1 , n-1);
        solve(nums , 0 , n-1);



        
    }
};