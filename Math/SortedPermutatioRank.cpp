#define mod 1000003

void buildFact(vector<long> &fact,int len){
    fact.push_back(1);
    fact.push_back(1);
    for(int i = 2; i<= len ; i++){
        fact.push_back((fact[i-1]*i)%mod);
    }
}

int Solution::findRank(string A){
    vector<long> fact;
    // create a vector filled with factorial value of that index modulated
    buildFact(fact,A.length());
    
    // created a sorted version of given string
    string b = A;
    sort(b.begin() , b.end());
    
    // create to Hash to store actual location of each character in sorted manner
    unordered_map<char , int> pos;
    for(int i = 0; i<b.length(); i++)
        pos[b[i]] = i;
    
    // vector contains actual index for given index.
    vector<int> v;
    for(int i = 0; i<A.length(); i++)
        v.push_back(pos[A[i]]);
    
    // setting vector for factorial arithmatics
    for(int i = 0; i<v.size(); i++){
        for(int j = i+1; j<v.size(); j++){
            if(v[j] > v[i])
                v[j]--;
        }
    }
    reverse(v.begin() , v.end());
    
    // factorial arithmatics
    long n = 0;
    for(int i = 0; i < v.size() ; i++){
        n = (n + v[i]*fact[i])%mod;
    }
    n++;
    return n;
}