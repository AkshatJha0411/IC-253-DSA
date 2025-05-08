#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val, listIdx, elemIdx;
    bool operator>(const Node& other) const {
        return val > other.val;
    }
};

vector<int> mergeKSortedLists(const vector<vector<int>>& lists) {
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    for (int i = 0; i < lists.size(); ++i)
        if (!lists[i].empty())
            minHeap.push({lists[i][0], i, 0});

    vector<int> result;
    while (!minHeap.empty()) {
        Node cur = minHeap.top(); minHeap.pop();
        result.push_back(cur.val);
        if (cur.elemIdx + 1 < lists[cur.listIdx].size())
            minHeap.push({lists[cur.listIdx][cur.elemIdx + 1], cur.listIdx, cur.elemIdx + 1});
    }
    return result;
}

int main() {
    vector<vector<int>> lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<int> merged = mergeKSortedLists(lists);
    for (int num : merged) cout << num << " ";
    return 0;
}
