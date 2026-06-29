class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int m=word.size();
        int count=0;
 

        for(int i=0;i<n;i++){
            string s=patterns[i];
          
             int len=s.size();
            for(int j=0;j<m;j++){
               if(j + len <= m &&  s==word.substr(j,len)) {
                count++;
                break;}
            

        }
        
       
        }
        return count;
        
    }
};