class Solution {
public:
    long long maxSubarraySum(vector<int >& nums, int k) {
          long long n=nums.size();

          vector<long long> prefix(n);

          prefix[0]=nums[0];
          
          for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
          }

            long long ans=LLONG_MIN;
        for(int m=0;m<k;m++){
               int i=m;
              long long currSum=0;
              long long subSum=0;

              long long j=i+k-1;
            while(j<n){
                 if(i==0){
                    subSum=prefix[j];

                 }
                 else subSum=prefix[j]-prefix[i-1];
                 currSum=max(currSum+subSum , subSum);

                 ans=max(ans ,currSum );
                 i=j+1;
                 j=i+k-1;


              
             
            }

        }
        return ans;
        
    }
};