int makeAnagram(string a, string b) {
    vector<int> freqA(26, 0);
    vector<int> freqB(26, 0);

    for (char ch : a) {
        freqA[ch - 'a']++;
    }
    for (char ch : b) {
        freqB[ch - 'a']++;
    }

    int deletions = 0;
    for (int i = 0; i < 26; i++) {
        deletions += abs(freqA[i] - freqB[i]);
    }
    
    return deletions;
}
