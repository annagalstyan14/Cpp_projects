void minimumBribes(vector<int> queue) {
    int bribes = 0;

    
    for (int i = 0; i < queue.size(); i++) {

        if (queue[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }

        for (int j = max(0, queue[i] - 2); j < i; j++) {
            if (queue[j] > queue[i]) {
                bribes++;
            }
        }
    }

    cout << bribes << endl;
}
