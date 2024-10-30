long substrCount(int n, string s) {
    long count = 0;
    vector<pair<char, int>> groups;

    for (int i = 0; i < n; ) {
        int count = 0;
        char ch = s[i];
        while (i < n && s[i] == ch) {
            count++;
            i++;
        }
        groups.push_back({ch, count});
    }

    for (auto &group : groups) {
        count += (group.second * (group.second + 1)) / 2;
    }

    for (int i = 1; i < groups.size() - 1; i++) {
        if (groups[i].second == 1 && groups[i-1].first == groups[i+1].first) {
            count += min(groups[i-1].second, groups[i+1].second);
        }
    }

    return count;
}
