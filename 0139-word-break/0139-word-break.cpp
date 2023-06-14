class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
     set<string>words;
        for(string i:wordDict){
            words.insert(i);
            }
        
        set<int>vis;
        queue<int>q;
        q.push(0);
       
        while(!q.empty()){
            int ind=q.front();
            q.pop();
           // cout<<ind<<endl;
             if(ind == s.size()){
            return true;
            }
           
            for(int end=1;end<=s.size();end++){
               string temp= s.substr(ind,end);
                  //cout<<temp<<endl;
                if(words.find(temp) != words.end() && vis.find(end+ind) == vis.end()){
            
                    vis.insert(end+ind);
                    q.push(end+ind);
                }
            }
            }
            return false;
    }
};