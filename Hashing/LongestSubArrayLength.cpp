/*https://www.interviewbit.com/problems/longest-subarray-length/
Longest Subarray Length
Asked in:
DE Shaw
*/




    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

int Solution::solve(vector<int> &A) {
    unordered_map<int , int>map;
    int maxlen=0,cont=0;
    for(int i=0;i<A.size();i++){
        cont+=(A[i]==0?-1:1);
        if(cont==1){
            maxlen=i+1;
        }else if(map.find(cont)==map.end()){
            map[cont]=i;
        }
        if(map.find(cont-1)!=map.end()){
            maxlen=max(maxlen,i-map[cont-1]);
        }
    }
    return maxlen;



}
