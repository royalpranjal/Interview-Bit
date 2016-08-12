// https://www.interviewbit.com/problems/window-string/

struct info{
    int freq, arrived;
};

string Solution::minWindow(string S, string T) {
   
    unordered_map <char, info> myMap;
   
    for(int i = 0; i < T.length(); i++){
        if(myMap.find(T[i]) == myMap.end()){
            myMap[T[i]].freq = 1;
            myMap[T[i]].arrived = 0;
        }
        else{
            myMap[T[i]].freq++;
        }
    }
   
    int p = 0, q = 0, len = 0;
    int n = T.size(), N = S.size();
    int minI = 0, maxI = 0, minLen = INT_MAX;
   
    while(1){
       if(len < n){
            if(q == N){
                break;
            }
            if(myMap.find(S[q]) != myMap.end()){
                myMap[S[q]].arrived++;
                if(myMap[S[q]].arrived <= myMap[S[q]].freq){
                    len++;
                }
            }
            q++;
       }
       else if(len == n){
            if(q - p < minLen){
                minLen = q - p;
                minI = p;
                maxI = q;
            }
            if(myMap.find(S[p]) != myMap.end()){
                myMap[S[p]].arrived--;
                if(myMap[S[p]].freq > myMap[S[p]].arrived){
                    len--;
                }
            }
            p++;
       }
    }
   
    string ans = "";
    
    for(int i = minI; i < maxI; i++){
        ans = ans + S[i];
    }
    
    return ans;
}
