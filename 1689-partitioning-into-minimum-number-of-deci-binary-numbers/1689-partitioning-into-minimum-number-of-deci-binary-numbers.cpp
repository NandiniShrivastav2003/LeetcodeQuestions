class Solution {
public:
    int minPartitions(string n) {
       
        int num=n[0]-'0';
        cout<<num<<endl;
            for(int i=1;i<n.size();i++){
            if(num<(n[i]-'0')){
                num=(n[i]-'0');
            }
            }
        
        return num;
    }
};