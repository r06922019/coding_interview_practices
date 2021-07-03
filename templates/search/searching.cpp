// find first element that >= x
int binary_search(vector<int> &arr, int l, int r, int x) {
    if(l == r) return l;
    int mid = l + (r-l)/2;
    if(x <= arr[mid])
        return binary_search(arr, l, mid, x);
    else
        return binary_search(arr, mid+1, r, x);
}

