class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<string>sorted;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin() , s.end());
            sorted.push_back(s);
        }

        vector<vector<string>> ans;
       
        for(int i=0;i<n;i++){
             if( sorted[i]==".") continue;
             vector<string>v;
            v.push_back(strs[i]);
            for(int j=i+1;j<n;j++){
              if( sorted[j]==".") continue;
              if(sorted[i]==sorted[j]){
                
                v.push_back(strs[j]);
                
                sorted[j]=".";

              }
            }
            ans.push_back(v);
        }
        return ans;


    }
};