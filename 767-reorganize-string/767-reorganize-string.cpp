class compare {
public:
    bool operator() (pair<char , int> &a, pair<char , int> &b) {
        return a.second <= b.second;
    }
};
class Solution {
    
public:
    string reorganizeString(string s) {
        string out="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<char>res;
        priority_queue<pair<char,int>,vector<pair<char, int>>,compare>pq;
        for(auto i:mp){
            pq.push(make_pair(i.first,i.second));
        }
        
        while(pq.size()>1){
        auto block=pq.top();
            pq.pop();
        auto temp=pq.top();
        pq.pop();
        res.push_back(block.first);
            res.push_back(temp.first);
            temp.second--;
            block.second--;
            if(temp.second >0){
                pq.push(temp);
            }
            if(block.second > 0){
                pq.push(block);
            }
            
        }
cout<<pq.size();
        if(pq.size() == 0){
             for(int i=0;i<res.size();i++){
            out+=res[i];
        }
        }
        else if(pq.top().second == 1){
            res.push_back(pq.top().first);
            pq.pop();
             for(int i=0;i<res.size();i++){
            out+=res[i];
        }
        }
        else{
            return "";
        }
        
       
            
        return out;
    }
};