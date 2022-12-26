class Solution {
public:
   static  bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
      if(a.second==b.second)return a.first<b.first;
    return a.second > b.second;
}
    void Mysort(map<int, int>& M)
{
  
   
    vector<pair<int, int> > A;

    for (auto& it : M) {
        A.push_back(it);
    }
  
   
    sort(A.begin(), A.end(), cmp);
}
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& report, vector<int>& sd, int k) {
        set<string>s1;
        set<string>s2;
        for(int i=0;i<pf.size();i++){
            s1.insert(pf[i]);
        }
        for(int i=0;i<nf.size();i++){
            s2.insert(nf[i]);
            
        }
        map<int,int>ans;
        for(int i=0;i<sd.size();i++){
           int score=0;
                 istringstream ss(report[i]);
 
    string word;
                while (ss >> word)
    {
        if(s1.find(word) != s1.end()){
            score+=3;
        }
       else if(s2.find(word) != s2.end()){
           score-=1;
       }
        else{
          continue;
        }
    }
            ans[sd[i]]=score;
            
        }
        vector<pair<int, int> > A;

    for (auto& it : ans) {
        A.push_back(it);
    }
    sort(A.begin(),A.end(),cmp);
        vector<int>res;
        for(auto i:A){
            if(k == 0){
                break;
            }
            res.push_back(i.first);
            k--;
        }
        return res;
    }
};