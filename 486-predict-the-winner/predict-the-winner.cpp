class Solution {
public:
    int solve(vector<int>& nums , int i, int j){

         if(i>j) return 0;
         if(i==j) return nums[i];
        int takei=nums[i]+min(solve(nums , i+2 , j) , solve(nums , i+1 , j-1));
        int takej=nums[j]+min(solve(nums , i+1 , j-1 ) , solve(nums , i , j-2));

        return max(takei , takej);


    }
    bool predictTheWinner(vector<int>& nums) {

        int n=nums.size();
        int total=0;
        for(int num:nums) total+=num;

        int score1=solve(nums , 0 , n-1);
        int score2=total-score1;

        return (score1>=score2)?true:false;
        
    }
};