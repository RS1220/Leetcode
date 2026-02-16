class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            string helper=strs[i];
            int a=ans.size();
            int b=strs[i].size();
            int n=min(a,b);
            string newString="";
            for(int j=0;j<n;j++){
                if(ans[j]==helper[j]) newString+=ans[j];
                else break;
                
            }
            ans=newString;
        }
        return ans;
        
    }
};