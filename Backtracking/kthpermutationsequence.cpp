#include <bits/stdc++.h>
using namespace std;
bool flag=false;
int factorial(int n){
    /*if(n>12){
        return INT_MAX;
        return 0;
    }*/
    int p=1;
    int i;
    for(i=1;i<=n;i++){
        p*=i;
    }
    return p;
}
void permute(int index,int n,int k,int *c,string *st,vector<int>&v){
    if(index>=n){
        (*c)++;
//        cout<<(*c)<<endl;
        if((*c)==k){
            int i;
            for(i=0;i<n;i++){
                ostringstream str1; 
                str1<<v[i];  
                (*st)+=str1.str();
            }
            flag=true;
//            cout<<s<<endl;
            return;        
        }
        return;
    } 
    int i,temp;
    for(i=index;i<n;i++){
        if((*c)==k){
            return;
        }
        temp=v[index];
        v[index]=v[i];
        v[i]=temp;
        permute(index+1,n,k,c,st,v);
        temp=v[index];
        v[index]=v[i];
        v[i]=temp;
    }
}
string Solution::getPermutation(int A, int B) {
    int i,n,k,x;
    n=A;
    k=B;
    int f=factorial(n);
    vector<int>v;
    for(i=1;i<=n;i++){
        v.push_back(i);
    }
    string s;
    // if(k>f){
    //     k=k%f;
    // }
   
    // for(i=0;i<n;i++){
    //     ostringstream str1; 
    //     str1<<v[i];  
    //     s+=str1.str();    
    // }
    int cnt=1;
    while(cnt<k){
        next_permutation(v.begin(),v.end());
        cnt++;
    }
    for(i=0;i<n;i++){
        ostringstream str1; 
        str1<<v[i];  
        s+=str1.str();    
    }
//    permute(0,n,k,&cnt,&s,v);
//    cout<<s<<endl;
    return s;
}
