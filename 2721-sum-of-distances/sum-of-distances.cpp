class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        long long n=nums.size();
        vector<long long>arr(n);
        unordered_map<long long,long long>idxsum;
        unordered_map<long long,long long>countidx;
        //left

        for(long long i=0;i<n;i++){
        long long freq=countidx[nums[i]];
        long long sum=idxsum[nums[i]];

        arr[i]=freq*i-sum;

        countidx[nums[i]]+=1;
        idxsum[nums[i]]+=i;

           
        }
       

        //right
        idxsum.clear();
        countidx.clear();

         for(int i=n-1;i>=0;i--){
         long long freq=countidx[nums[i]];
         long long sum=idxsum[nums[i]];

        arr[i]+=sum-freq*i;

        countidx[nums[i]]+=1;
        idxsum[nums[i]]+=i;

           
        }
        return arr;

    }
};