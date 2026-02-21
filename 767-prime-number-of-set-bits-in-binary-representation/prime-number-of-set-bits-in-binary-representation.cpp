class Solution {
public:
    int FindSetBit(int n){
        bitset<32> b(n);
        return b.count(); 
    }
   
    int countPrimeSetBits(int left, int right) {
        int count=0;
        unordered_set<int>s={2,3,5,7,11,13,17,19};
        for(int i=left;i<=right;i++){
            int a=FindSetBit(i);
            if(s.find(a)!=s.end()) count++;

        }
        return count;
        
    }
};