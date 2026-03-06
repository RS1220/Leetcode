class Solution {
public:
    int kthGrammar(int n, int k) {//Tc O(n)
        
        if(n==1) return 0;
        if(k%2==0){//even , flip , k/2
         int ans=kthGrammar(n-1,k/2);
         if(ans==1) return 0;
         else return 1;
        }
        else{//odd , same , (k/2)+1
           return kthGrammar(n-1 , (k/2)+1);
        }

    }
};