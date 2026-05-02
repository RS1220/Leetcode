class Solution {
public:


bool good(int num){
    bool changed=false;
   while(num>0){
            int last=num%10;
           

           
            if(last==3||last==7||last==4) return false;
             if(last==2||last==5||last==6||last==9) changed=true;
             num/=10;
        }

        return changed;
}
int rotatedDigits(int n) 
{
    
    int count=0;
    for(int i=1;i<=n;i++){
       if(good(i)) count++;
       
    }
    return count;
}
};