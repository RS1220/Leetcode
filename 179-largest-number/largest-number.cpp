 bool cmp(string a , string b) {return a+b>b+a;}
class Solution {
public:
  
    string largestNumber(vector<int>& nums) 
    {   vector<string>ans;
        for(int i=0;i<nums.size();i++){
             int num=nums[i];
             string s=to_string(num);
             ans.push_back(s);

        }
        
        sort(ans.begin() , ans.end() , cmp);
         if (ans[0] == "0") return "0";
        string result="";
        for(int i=0;i<ans.size();i++)
        {
          result+=ans[i];
        }

        return result;

    }
};