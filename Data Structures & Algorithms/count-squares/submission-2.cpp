class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;


        for (auto &[x2, ys] : cnt) {
            if (x2 == x) continue;
            int d = x2 - x;
            ans += cnt[x2][y] * cnt[x][y + d] * cnt[x2][y + d];
            ans += cnt[x2][y] * cnt[x][y - d] * cnt[x2][y - d];
    }
    return ans;
    }
};
