class CountSquares {
   private:
    map<vector<int>, int> freqMap;
    vector<vector<int>> points;

   public:
    CountSquares() {}

    void add(vector<int> point) {
        freqMap[{point[0], point[1]}]++;
        points.push_back(point);
    }

    int count(vector<int> query) {
        int count = 0;
        int x2 = query[0];
        int y2 = query[1];

        for (vector<int>& point : points) {
            int x = point[0];
            int y = point[1];

            // if (x-x2) == (y-y2) means diagonal
            if (abs(x - x2) == abs(y - y2) && x != x2 && y != y2) {

                // if it is then calculate wrt to freq of each point
                count += freqMap[{x, y2}] * freqMap[{x2, y}];
            }
        }

        return count;
    }
};
