class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int x:stones) maxHeap.push(x);
        while(maxHeap.size()>1){
            int x=maxHeap.top();
            maxHeap.pop();
            int y=maxHeap.top();
            maxHeap.pop();
            if(x==y) continue;
            else if(x>y){
                maxHeap.push(x-y);
            }
        }
        return maxHeap.size()? maxHeap.top():0;
    }
};
