class MyCalendar {
public:
    
    vector<pair<int,int>>vec;
    MyCalendar() {
        
    }
    bool checkInterval(vector<pair<int,int>>check,int start,int end){
        check.push_back({start,end});
        sort(check.begin(),check.end());
        pair<int,int>temp=check[0];
        for(int i=1;i<check.size();i++){
            if(check[i].first >= temp.second){
                temp=check[i];
            }
            else{
                 
                return false;
               
            }
        }
        return true;
    }
    bool book(int start, int end) {
        if(vec.empty()){
            vec.push_back({start,end});
            return true;
        }
        
            
        if(checkInterval(vec,start,end) == true){
            vec.push_back({start,end});
            sort(vec.begin(),vec.end());
            return true;
        }
        
        
        return false;
    }
};

