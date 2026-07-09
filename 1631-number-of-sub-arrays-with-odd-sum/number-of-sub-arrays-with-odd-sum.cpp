class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {


        
        const long long mod=1000000007;
        int n=arr.size();
       

       
         for(int i=1;i<n;i++){
           arr[i]+=arr[i-1];
        }
        

        int ans=0;
        int cnt=1;
        

        for(int i=0;i<n;i++){
             if(arr[i]%2!=0){
                ans+=cnt;
              
               

             }
             else  cnt++;
        }

        cnt=0;
        ans=ans%mod;

        for(int i=0;i<n;i++){
             if(arr[i]%2==0){
                ans+=cnt;
              
               

             }
             else  cnt++;
        }


        return ans%mod;
    }
};