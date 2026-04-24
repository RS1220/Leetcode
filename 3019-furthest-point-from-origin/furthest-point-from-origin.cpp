class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int countL=0;
        int countR=0;
       int  count=0;
        for(int i=0;i<n;i++){
         if(moves[i]=='L') countL++;
         else if(moves[i]=='R') countR++;
         
        }

        if(countL>=countR) {
          for(int i=0;i<n;i++){
       
          if(moves[i]=='_') moves[i]='L';
        
        }  }
        else{
            for(int i=0;i<n;i++){
       
          if(moves[i]=='_') moves[i]='R';
        
        }  

        }
      
        for(int i=0;i<n;i++){
         if(moves[i]=='L') count--;
         else count++;
        }
        return abs(count);
        
       
    }
};