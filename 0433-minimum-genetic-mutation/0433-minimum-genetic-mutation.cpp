class Solution {
public:
    int minMutation(string s, string e, vector<string>& bank) {
        if(bank.size() == 0){
            return -1;
        }
        unordered_set<string>mp;
        bool f=false;
    for(int i=0;i<bank.size();i++){
        mp.insert(bank[i]);
        if(bank[i] == e){
            f=true;
        }
    }
        if(f == false){
            return -1;
        }
        queue<string>q;
        q.push(s);
        int ans=0;
        while(!q.empty()){
           ans=ans+1;
            int size=q.size();
            while(size--){
                 
                string temp=q.front();
                
                q.pop();
                for(int i=0;i<temp.size();i++){
                    string curr=temp;
                    for(char c='A';c<='Z';c++){
                        curr[i]=c;
                        if(temp.compare(curr) == 0){
                            continue;
                        }
                        if(curr.compare(e) == 0){
                            return ans;
                        }
                       
                            if(mp.find(curr) != mp.end()){
                                q.push(curr);
                                mp.erase(curr);
                               
                                
                        
                        }
                    }
                }
            }
        }
        return -1;
    }
};