long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);

    for (const auto &query : queries) {
        int a = query[0];
        int b = query[1];
        int k = query[2];
        
        arr[a - 1] += k;
        if (b < n) {
            arr[b] -= k;
        }
    }

    long max_value = 0;
    long current_value = 0;
    for (int i = 0; i < n; i++) {
        current_value += arr[i];
        if (current_value > max_value) {
            max_value = current_value;
        }
    }

    return max_value;
}
