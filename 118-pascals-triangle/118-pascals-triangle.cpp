class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>outer;
        vector<int>inner(1,1);
        outer.push_back(inner);
        for(int i=2;i<=numRows;i++){
            vector<int>temp=outer.back();
            for(int i=0;i<temp.size();i++){
                if(i+1<temp.size()){
                    inner.push_back(temp[i]+temp[i+1]);
                }
}
            
            inner.push_back(1);
            outer.push_back(inner);
            inner.clear();
            inner.push_back(1);
}
        return outer;
    }
};