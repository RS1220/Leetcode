class Solution {
public:
    bool check(string a ,string b)
    {
       int count=0;
       for(int i=0;i<a.size();i++){
         if(a[i]!=b[i]) count++;
       }
        if(count<=2) return true;
    return false;
    }

   
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {   vector<string>ans;
        int n=queries.size();
        int m=dictionary.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(queries[i] , dictionary[j])) {
                    ans.push_back(queries[i]);
                    break;}
            }
        }
        return ans;
    }
};