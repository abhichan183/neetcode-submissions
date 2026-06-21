class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<pair<int,int>> s;
        for(int i=0;i<temperatures.size();i++){
            int temp=temperatures[i];
            while(!s.empty()&&temp>s.top().first){
                pair<int,int> pair=s.top();
                s.pop();
                res[pair.second]=i-pair.second;
            }
            s.push({temp,i});
        }
        return res;
    }
};
