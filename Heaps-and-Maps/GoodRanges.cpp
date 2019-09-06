// https://www.interviewbit.com/problems/good-ranges/

vector<int> Solution::solve(int A, vector<int> &B) {
    map<int, pair<int, int>> ranges;
    vector<int> res{};
    int low = 0, high = 0, sum = 0, diff, min, max;

    for (int c = 0; c < B.size(); c++) {
        diff = 0;
        if (c == 0) {
            ranges[B[0]] = { 1,A };
            diff = 1 + A;
        }
        else if (ranges.find(B[c]) != ranges.end()) {

        }
        else if (B[c] < ranges.begin()->first) {
            min = ranges.begin()->first;
            diff -= ranges[min].first;
            diff += B[c] + 1;
            ranges[min].first = B[c] + 1;
            ranges[B[c]] = { 1, min - 1 };
            diff += min;
        }

        else if (ranges.upper_bound(B[c]) == ranges.end()) {
            max = ranges.rbegin()->first;
            diff -= ranges[max].second;
            diff += B[c] - 1;
            ranges[max].second = B[c] - 1;
            ranges[B[c]] = { max + 1 , A };
            diff += max + 1 + A;
        }
        else {
            low = ranges.upper_bound(B[c])->second.first - 1;
            high = ranges.upper_bound(B[c])->first;
            diff -= ranges[low].second;
            diff += B[c] - 1;
            ranges[low].second = B[c] - 1;
            diff -= ranges[high].first;
            diff += B[c] + 1;
            ranges[high].first = B[c] + 1;
            ranges[B[c]] = { low + 1,high - 1 };
            diff += low + high;
        }
        sum += diff;
        sum = sum % 1000000007;
        res.push_back(sum);
    }
    return res;
}
