class Solution {
public:
    int minOperations(string s) {
        if(s.size()<=1) return 0;
        char first=s[0];
        int count=0;
        if(first=='0'){
          for(int i=1;i<s.size();i++){
            if(i%2==0){
                if(s[i]!='0') count++;
            }
            else {
                if(s[i]=='0') count++;
            }
          }
        }
        else{

             for(int i=1;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='0') count++;
            }
            else {
                if(s[i]!='0') count++;
            }
          }

        }

        int countb=1;
        if(s[0]=='1') s[0]='0';
        else s[0]='1';
        first=s[0];

         if(first=='0'){
          for(int i=1;i<s.size();i++){
            if(i%2==0){
                if(s[i]!='0') countb++;
            }
            else {
                if(s[i]=='0') countb++;
            }
          }
        }
        else{

             for(int i=1;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='0') countb++;
            }
            else {
                if(s[i]!='0') countb++;
            }
          }

        }

      return min(countb,count);

        
    }
};