// Disjoint set solution with path compression (will get TLE if we don't use path compression).

struct DisjointSet{
    DisjointSet* parent;
    
    DisjointSet(){
        parent = this;
    }
};

DisjointSet* getParent(DisjointSet* A){
    while(A->parent != A){
        A->parent = getParent(A->parent);
        A = A->parent;
    }
    
    return A;
}

void merge(DisjointSet* A, DisjointSet* B){
    while(getParent(A) != A){
        A = A->parent;
    }
    
    while(getParent(B) != B){
        B = B->parent;
    }
    
    A->parent = B;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), 
    [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[2] < b[2];
    });
    
    int n = B.size(), ans = 0;
    map<int, DisjointSet*> m;
    
    for(int i = 1; i <= A; i++){
        m[i] = new DisjointSet();
    }
    
    for(int i = 0; i < n; i++){
        
        
        if(getParent(m[B[i][0]]) != getParent(m[B[i][1]])){
            merge(m[B[i][0]], m[B[i][1]]);
            ans += B[i][2];
        }
    }
    
    return ans;
}
