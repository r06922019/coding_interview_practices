#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

#define T int

int main() {
    auto comp = [](const T &a, const T &b) -> bool { return a > b; }; // min_queue
    priority_queue<T, vector<T>, decltype(comp)> pq(comp);
    for(int i = 0; i < 3; ++i) {
        pq.push(i);
    }
    printf("%d\n", pq.top());
    return 0;
}