class CountSquares {
public:
    unordered_map<int, unordered_map<int,int>> cnt;

    CountSquares() {
    }

    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }

    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];

        int ans = 0;

        // Traverse all points having the same x-coordinate
        for(auto &[ny, freq] : cnt[x]) {

            if(ny == y)
                continue;

            int side = abs(ny - y);

            // Square on the right
            ans += freq *
                   cnt[x + side][y] *
                   cnt[x + side][ny];

            // Square on the left
            ans += freq *
                   cnt[x - side][y] *
                   cnt[x - side][ny];
        }

        return ans;
    }
};