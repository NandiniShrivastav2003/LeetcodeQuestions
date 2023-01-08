class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
        }
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(mp1.count(i) && mp2.count(j)){
                    mp1[i]--;
                    if(mp1[i] == 0){
                        mp1.erase(i);
                    }
                    mp2[j]--;
                    if(mp2[j] == 0){
                        mp2.erase(j);
                    }
                    mp1[j]++;
                    mp2[i]++;
                    if(mp1.size() == mp2.size()){
                        return true;
                    }
                    mp1[j]--;
                    if(mp1[j] == 0){
                        mp1.erase(j);
                    }
                    mp2[i]--;
                    if(mp2[i] == 0){
                        mp2.erase(i);
                    }
                    mp1[i]++;
                    mp2[j]++;
                }
            }
        }
        return false;
        
    }
};