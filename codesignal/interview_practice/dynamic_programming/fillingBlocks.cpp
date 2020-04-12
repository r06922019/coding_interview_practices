int fillingBlocks(int n) {
    vector<int> A(n+1, 0); // ends in ****
    vector<int> B(n+1, 0); // ends in __**
    vector<int> C(n+1, 0); // ends in _**_
    vector<int> D(n+1, 0); // ends in **__
    vector<int> E(n+1, 0); // ends in *__*

    A[0] = 1;
    A[1] = B[1] = C[1] = D[1] = 1;
    for(int i = 2; i <= n; ++i) {
        A[i] = A[i-1] + B[i-1] + C[i-1] + D[i-1] + A[i-2];
        B[i] = A[i-1] + D[i-1];
        C[i] = A[i-1] + E[i-1];
        D[i] = A[i-1] + B[i-1];
        E[i] = C[i-1];
    }
    return A[n];
}