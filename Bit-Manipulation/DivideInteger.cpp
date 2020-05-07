int Solution::divide(int a, int b) {
    if(a==0)
    return 0;
    if(b==0)
    return (INT_MAX);
   int sign=1;
    //remove sign of operands
    int t=0,q=0;
    a=abs(a);
    b=abs(b);
    for(int i=31;i>=0;--i){
        if(t+(b<<i)<=a){
            t+=b<<i;
            q+=1LL<<i;
        }
    }
    return (sign*q>=INT_MAX||sign*q<INT_MIN)?INT_MAX:sign*q;
}
