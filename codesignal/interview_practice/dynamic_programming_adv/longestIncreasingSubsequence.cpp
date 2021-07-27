int longestIncreasingSubsequence(vector<int> sequence) {
    int n = sequence.size();
    vector<int> lengths(n, 1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(sequence[j] < sequence[i]) {
                lengths[i] = max(lengths[i], lengths[j]+1);
            }
        }
    }
    return *max_element(lengths.begin(), lengths.end());
}
