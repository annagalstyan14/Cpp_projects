tring isValid(string s) {
    unordered_map<char, int> freqMap;

    for (char c : s) {
        freqMap[c]++;
    }
 
    unordered_map<int, int> countFreq;
    for (auto &entry : freqMap) {
        countFreq[entry.second]++;
    }

    if (countFreq.size() == 1) {
        return "YES";
    }

    if (countFreq.size() == 2) {
        auto it = countFreq.begin();
        int freq1 = it->first, count1 = it->second;
        it++;
        int freq2 = it->first, count2 = it->second;

        if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
            return "YES";
        }
 only once
        if ((abs(freq1 - freq2) == 1) && (count1 == 1 || count2 == 1)) {
            return "YES";
        }
    }

    return "NO";
}
