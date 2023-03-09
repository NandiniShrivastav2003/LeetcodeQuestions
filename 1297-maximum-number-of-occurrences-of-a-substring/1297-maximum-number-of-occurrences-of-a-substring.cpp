class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
     map<char,int>mp;
        map<string,int>occ;
        int i=0,j=0;
        while(i<s.size()){
            mp[s[i]]++;
            while(i-j+1 == minSize  ){
                if(mp.size() <= maxLetters){
                string temp=s.substr(j,minSize);
                occ[temp]++;
               
            }
                if(mp[s[j]] == 1){
                    mp.erase(s[j]);
                }
                else{
                    mp[s[j]]--;
                }
                j++;
                
            
            }
            i++;
        }
        int maxi=0;
        for(auto i:occ){
          //  cout<<i.first<<" "<<i.second<<endl;
            if(i.second >maxi){
                maxi=i.second;
            }
        }
        return maxi;
    }
};