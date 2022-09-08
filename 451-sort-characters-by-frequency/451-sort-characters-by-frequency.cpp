class Solution {
public:
        string res="";
    static bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second > b.second;
}
    void sortA(map<char, int>& M)
{
  
   
    vector<pair<char, int> > A;
    for (auto& it : M) {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);
    
        for(auto it:A){
           while(it.second --){
               res+=it.first;
           }
        }
}

    string frequencySort(string s) {
      map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        sortA(mp);
        return res;
    }
};
