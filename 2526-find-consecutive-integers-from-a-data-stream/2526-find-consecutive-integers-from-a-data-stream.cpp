class DataStream {
public:
   
    int val;int kk;
    int cnt=0;
    DataStream(int value, int k) {
       val=value;
        kk=k;
        
    }
    
    bool consec(int num) {
        if(num == val){
            cnt++;
        }
        else{
            cnt=0;
        }
        return cnt>=kk;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */