class Solution {
public:
 
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulk=false,heavy=false;
        string ans;
        
    long long res=(long long)length*(long long)width*(long long)height;
        if(length >= 1e4 || width >= 1e4 || height >= 1e4 ){
         bulk=true;   
        }
        if(res>=1e9){
            bulk=true;
        }
        if(mass >= 100){
            heavy=true;
        }
        if(bulk && heavy){
            ans="Both";
        }
        else if(!bulk && !heavy){
            ans="Neither";
        }
        else if(bulk && !heavy){
            ans="Bulky";
        }
        else if(heavy && !bulk){
            ans="Heavy";
        }
        return ans;
    }
};