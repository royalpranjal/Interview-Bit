long Solution::solve(int A, int B) {
    if(A%7) A+=(7-A%7);
    B-=B%7;
    int n=(B-A)/7+1;
    long long result=(long)n * long(A+B)/2;
    return result;
}
