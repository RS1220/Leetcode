class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int result=0;
        for(int i=0;i<=31;i++){
            int temp=1<<i;
            int countO=0;
            int countZ=0;

            for(auto &num:nums){
                if((num&temp)==0) countZ++;
                else countO++;
               
            }

            if(countO%3==1){
                result=result|temp;
            }


        }
        return result;
        
    }
};