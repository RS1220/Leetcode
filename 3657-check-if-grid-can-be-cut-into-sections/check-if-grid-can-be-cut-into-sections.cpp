class Solution {
public:
    
   int merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
           if(intervals[i][0]<result.back()[1]){
                  result.back()[1]=max(result.back()[1] , intervals[i][1]);
           }
           else  result.push_back(intervals[i]);

        }
        int num=result.size();

        return num;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        

        int m=rectangles.size();

        vector<vector<int>>x;
         vector<vector<int>>y;

         for(int i=0;i<m;i++){
         int a1=rectangles[i][0];
         int a2=rectangles[i][1];
         int a3=rectangles[i][2];
         int a4=rectangles[i][3];

         x.push_back({a1,a3});
         y.push_back({a2,a4});


         }

         int X=merge(x);
         if(X>=3) return true;

          int Y=merge(y);
         if(Y>=3) return true;


         return false;









        
    }
};