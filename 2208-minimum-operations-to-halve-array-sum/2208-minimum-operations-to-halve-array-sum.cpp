class Solution {
public:
    int halveArray(vector<int>& nums) {
     priority_queue<double>pq(nums.begin(),nums.end());
    double sum=0.0;
        for(int x:nums){
            sum+=x;
        }
        int c=0;
        double res=sum/2;
        while(sum > res) {
            double temp=pq.top();
            pq.pop();
           double x= (temp/2);
           sum-=x;
            c++;
            pq.push(temp-x);
        }
        
        return c;   
    }
};