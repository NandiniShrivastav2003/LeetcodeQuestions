class Solution {
public:
    bool isRobotBounded(string s) {
        int x=0,y=0;
        char d='N';
          for(int i=0;i<s.size();i++){
              if(s[i] == 'G'){
                  if(d == 'N'){
                      y=y+1;
                  }
                  else if(d == 'E'){
                     x=x+1;
                  }
                  else if(d == 'W'){
                     x=x-1;
                  }
                  else{
                      y=y-1;
                  }
              }
              else if(s[i] == 'L'){
                  if(d == 'N'){
                      d='W';
                  }
                  else if(d == 'E'){
                      d='N';
                  }
                  else if(d == 'W'){
                      d='S';
                  }
                  else{
                      d='E';
                  }
              }
              else{
                 if(d == 'N'){
                      d='E';
                  }
                  else if(d == 'E'){
                      d='S';
                  }
                  else if(d == 'W'){
                      d='N';
                  }
                  else{
                      d='W';
                  } 
              }
          }
        if(x == 0 && y == 0){
            return true;
        }
        if(d == 'N'){
            return false;
        }
        return true;
    }
};