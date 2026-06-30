class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n=customers.size();
        int profit=0;
        for(int i=0;i<minutes;i++){
           if(grumpy[i]==1){
            profit+=customers[i];
           }
        }
        int maxIdx=0;
        int maxSum=profit;
        int i=1;
        int j=minutes;
        while(j<n){
            
            if(grumpy[j]==1)  profit+=customers[j];
            if(grumpy[i-1]==1)  profit-=customers[i-1];

            if(profit>maxSum){
                maxSum=profit;
                maxIdx=i;
            }

            i++;
            j++;

        }

        for(int i=maxIdx;i<maxIdx+minutes;i++){
            if(grumpy[i]==1) grumpy[i]=0;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) ans+=customers[i];
        }
        return ans;
        
    }
};