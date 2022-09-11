class compare {
public:
    bool operator() (pair<char , int> &a, pair<char , int> &b) {
        return a.second < b.second;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        //we make a max heap and take out two characters .
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        if(a)pq.push(make_pair('a',a));
       if(b) pq.push(make_pair('b',b));
        if(c)pq.push(make_pair('c',c));
        while(pq.size() > 1){
            auto i=pq.top();
           
            pq.pop();
            auto j=pq.top();
           
            pq.pop();
            //if first element isgreater than 2 we add it to result
            if(i.second >= 2 ){
                 res+=(i.first);
                res+=(i.first);
                i.second = i.second-2;
            }
            //else add one
            else{
                res+=(i.first);
                 i.second = i.second-1;
            }
           //if second character is greater than 2 and we check one more condition if 2nd charcter length is greater than equal to first character length we add 2 characters otherwise 1.
            if(j.second >= 2 && j.second >= i.second){
                 res+=(j.first);
                      res+=(j.first);
                 j.second = j.second-2;
            }
            else{
                res+=(j.first);
                 j.second = j.second-1;
            }
            if(i.second > 0){
                pq.push(i);
            }
            if(j.second > 0){
                pq.push(j);
            }
            //cout<<res<<endl;
            
        }
      
        if(pq.size() == 1){
        auto i=pq.top();
              if(i.second >= 2 ){
                 res += (i.first);
                res += (i.first);
               
            }
            else{
                res += (i.first);
                 
            }
        }
        return res;
    }
};