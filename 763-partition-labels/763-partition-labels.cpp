class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
       int n=intervals.size();
       int i;
         res.push_back(intervals[0]);
        for(i=1;i<n;i++){
          if(res.back()[1]>= intervals [i][0]  ){
               res.back()[1]=(max(res.back()[1],intervals[i][1]));   
             
              
            }
            else{
              res.push_back(intervals[i]);  
              
            }
        }
        return res;
    }
    int first(string s,char a){
        int pos;
        for(int i=0;i<s.size();i++){
            if(s[i] == a){
                pos=i;
                break;
            }
        }
        return pos;
    }
    int last(string s,char a){
        int pos;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == a){
                pos=i;
                break;
            }
        }
        return pos;
    }
    vector<int> partitionLabels(string s) {
        set<char>m;
        vector<int>res;
        vector<vector<int>>out;
        for(int i=0;i<s.size();i++){
            m.insert(s[i]);
        }
        for(auto i:m){
            res.push_back(first(s,i));
            res.push_back(last(s,i));
            out.push_back(res);
            res.clear();
        }
         vector<vector<int>>out1=  merge(out);
        res.clear();
        for(int i=0;i<out1.size();i++){
            res.push_back(out1[i][1]-out1[i][0] +1);
        }
        return res;
    }
};