class Solution {
public:

    string intToRoman(int num) {
      unordered_map<int, string> mp = {{1, "I"}, {5,"V"}, {10,"X"}, {50,"L"}, {100,"C"}, {500,"D"}, {1000,"M"},{4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}};
       vector<int>given={1,4,5,9,10,40,50,90,100,400,500,900,1000};
       string ans="";
        int i=given.size()-1;
        
        while(num != 0 && i >=0){
     while(num >= given[i]){
           ans+=mp[given[i]];
           num=num-given[i];
        
           
       }   
           
            i--;
           
          
        }
        return ans;
    }
};