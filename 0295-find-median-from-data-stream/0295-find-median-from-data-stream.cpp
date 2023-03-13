class MedianFinder {
public:
    priority_queue <int> mini;//max heap
          priority_queue <int, vector<int>, greater<int> > maxi;//min heap
    MedianFinder() {
          
    }
    
    void addNum(int num) {
        if(maxi.size() == mini.size()){
           maxi.push(num);

           mini.push(maxi.top());
           maxi.pop();
       }
       else if(mini.size()>maxi.size()){
if(mini.top() > num){
int x=mini.top();
mini.pop();
mini.push(num);
maxi.push(x);
}
else {
    maxi.push(num);
}
       }
       else {
 if(maxi.top() < num){
     int x=maxi.top();
     maxi.pop();
     maxi.push(num);
     mini.push(x);
 }
        else{   mini.push(num);
        }
       }
    }
    
    double findMedian() {
        if(mini.size() == maxi.size()){
            return double(mini.top()+maxi.top())/2;
        }
        else{
            return mini.top();
        }
    }
};

