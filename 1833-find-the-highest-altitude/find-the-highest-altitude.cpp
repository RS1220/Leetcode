class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        for(int i=1;i<gain.size();i++){
            gain[i]+=gain[i-1];
        }
        gain.insert(gain. begin() , 0);

       int ans=*max_element(gain.begin() , gain.end());
         return ans;
        
    }
};