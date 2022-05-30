class Solution {
public:
vector<vector<int>> res;
void combSum(int i, int target, vector<int> &m, vector<int> candidates, stack<int> st)
{
   
    if(i == candidates.size()){
        if (target == 0)
        {
            while (!st.empty())
            {
                m.push_back(st.top());
                st.pop();
            }
            res.push_back(m);
            m.clear();
          
        }
          return;
    }
    if ( candidates[i] <= target)
    {
        st.push(candidates[i]);

        combSum(i, target - candidates[i], m, candidates, st);
        st.pop();
    }
    combSum(i + 1, target, m, candidates, st);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<int> m;
    stack<int> st;
    combSum(0, target, m, candidates, st);
    return res;
}
};