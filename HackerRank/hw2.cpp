vector<int> rotLeft(vector<int> a, int d) {
    
    d = d % a.size(); 
    
    
    vector<int> b(a.begin() + d, a.end());  
    b.insert(b.end(), a.begin(), a.begin() + d); 
    
    return b;
}