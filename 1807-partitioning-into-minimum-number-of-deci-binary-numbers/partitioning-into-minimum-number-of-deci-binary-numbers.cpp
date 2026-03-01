class Solution {
public:
    int minPartitions(string n) {
        vector<int>v(10,-1);
        for(int i=0;i<n.size();i++){
               int num=n[i]-'0';
               if(v[num]==-1) v[num]=0;
               else continue;

        }
        for(int i=9;i>=0;i--){
            if(v[i]==0) return i;
        }
        return 0;
    }
};