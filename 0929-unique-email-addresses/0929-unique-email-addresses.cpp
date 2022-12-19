class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>mp;
        int i=0;
        for(i=0;i<emails.size();i++){
            string local="";
            string domain="";
            int j=-1;
            bool f=false;
            while(emails[i][++j] != '@'){
                if(f == true){
                    continue;
                }
                else if(emails[i][j] == '.'){
                    continue;
                }
                else if(emails[i][j] == '+'){
                   f=true;
                }
                else{
                    local+=emails[i][j];
                }
                
            }  
            while(j++<emails[i].size())
            {
                domain+=emails[i][j];
            }
          //  cout<<local+"@"+domain<<endl;
           mp[local+"@"+domain]++;
        }
        return mp.size();
    }
};