class MedianFinder {
public:
    priority_queue <int> a;//max heap
          priority_queue <int, vector<int>, greater<int> > b;//min heap
    MedianFinder() {
          
    }
    
    void addNum(int num) {
        if(a.size() == b.size()){
            a.push(num);
            int x=a.top();
            a.pop();
            b.push(x);
        }
        else if(a.size() > b.size()){
            if(a.top() > num){
                int x= a.top();
                a.pop();
                a.push(num);
                b.push(x);
            }
            else{
                b.push(num);
            }
        }
        else{
            if(b.top() < num){
                a.push(b.top());
                b.pop();
                b.push(num);
            }
            else{
                a.push(num);
            }
        }
    }
    
    double findMedian() {
        if(a.size() == b.size()){
            return double(a.top()+b.top())/2;
        }
        else{
            return b.top();
        }
    }
};

