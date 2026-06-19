class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int number=points.size();
        priority_queue<pair<double,vector<int>>> maxHeap;
        for(int i=0;i<number;i++){
            double dist=distance(points[i][0],points[i][1]);
            maxHeap.push({dist,{points[i][0],points[i][1]}});
            if(maxHeap.size()>k) maxHeap.pop();
        }
        vector<vector<int>> res;
        while(maxHeap.size()){
            auto [dist,point]=maxHeap.top();
            maxHeap.pop();
            res.push_back(point);
        }
        return res;
    }

    double distance(int x,int y){
        return sqrt((x*x)+(y*y));
    }
};
