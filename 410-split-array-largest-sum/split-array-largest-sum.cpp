class Solution {
public:
    bool check(vector<int>& nums, int k,int mid){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i] <=mid) sum+=nums[i];
            else{
                count++;
                sum=nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) 
    {   int ans=0;
        int n=nums.size();
        int l=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]>l) l=nums[i];
        }
        int r=sum;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};