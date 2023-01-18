class MyStack {
public:
queue<int>q1;
    MyStack() {
        
    }
    void push(int x) {
     int n=q1.size();
        q1.push(x);
        while(n--){
            q1.push(q1.front());
            q1.pop();
        }
    }
    int pop() {
        int res=q1.front();
        q1.pop();
        return res;
        
    }
    
   
    int top() {
       return q1.front(); 
    }
    
    
    bool empty() {
        if(q1.empty() == false){
            return false;
        }
        return true;
    }
};

