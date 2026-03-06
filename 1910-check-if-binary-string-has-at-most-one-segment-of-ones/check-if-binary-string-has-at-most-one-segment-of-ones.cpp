class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.find("01")!=string::npos) return false;//npos means no position
        return true;
    }
};