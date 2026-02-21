class Solution {
public:
    int FindSetBit(int n){
        bitset<32> b(n);
        return b.count(); 
    }
    bool isPrime(int n){
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2;i<n;i++){
        if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int a=FindSetBit(i);
            if(isPrime(a)) count++;

        }
        return count;
        
    }
};