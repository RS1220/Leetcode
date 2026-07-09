class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {


        
        const long long mod=1000000007;
        int n=arr.size();
       

       
         for(int i=1;i<n;i++){
           arr[i]+=arr[i-1];
        }
        

        int ans=0;
        int even=1;
        int odd=0;
        

        for(int i=0;i<n;i++){
             if(arr[i]%2!=0){
                ans=(ans+even)%mod;
                
               odd++;
               

             }
             else {
                ans=(ans+odd)%mod;;
                even++;
             }
        }

        


        return ans%mod;
    }
};