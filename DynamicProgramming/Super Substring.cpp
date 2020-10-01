#include<bits/stdc++.h>
using namespace std;

int kmp(string &pattern, string & text){
    int len=0;
    vector<int>lps(pattern.size(),0); 
    for(int i=1;i<pattern.size();i++){
        if(pattern[len]==pattern[i]) lps[i]=++len;
        else{
            while(len && pattern[len]!=pattern[i]) len=lps[len-1];
            if(pattern[len]==pattern[i]) lps[i]=++len;
        }
    }
    int j=0;
    for(int i=0;i<text.size();i++){
        if(text[i]==pattern[j]) j++;
        else{
            while(j && text[i]!=pattern[j]) j=lps[j-1];
            if(text[i]==pattern[j]) j++;
        }
        if(j==pattern.size()) j=lps[j-1]; 
    }
    return j;
}

int getRedx(string &s1, string  & s2, string &s3){
    int n1=s1.size(),n2=s2.size(),n3=s3.size();
    int l=kmp(s2,s1),r=kmp(s3,s2);
    return l+r;
}

string combine(string &s1, string  & s2, string &s3){
    int n1=s1.size(),n2=s2.size(),n3=s3.size();
    int l=kmp(s2,s1),r=kmp(s3,s2);
    return (s1+s2.substr(l)+s3.substr(r));
}

void removeSubStrings(vector<string> & ar){
    // cerr<<"\nReduced to Vector:";for(auto s:ar) cerr<<s<<" ";
    vector<string> vec;
    int n=ar.size();
    for(int i=0;i<n;i++) {
        bool add=1;
        string &temp=ar[i]; 
        for(int j=0;j<n;j++) if(i!=j && ar[j].find(temp)!=string::npos) {add=0;break;}
        if(add) vec.push_back(temp);
    }
    ar=vec;
}

string getRes(vector<string> &ar,bool &at){
    // cerr<<"\nPassed Vector:";for(auto s:ar) cerr<<s<<" ";
    if(ar.size()==1) return ar[0];
    removeSubStrings(ar);
    if(ar.size()==2){
        int l=kmp(ar[0],ar[1]),r=kmp(ar[1],ar[0]);
        if(l>r) return ar[1]+ar[0].substr(l);
        return ar[0]+ar[1].substr(r);
    }
    int ii=0,jj=1,kk=2,mx=0,n=ar.size();
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j) for(int k=0;k<n;k++) if(i!=k && j!=k)  {
        int x=getRedx(ar[i],ar[j],ar[k]);
        if(at) { if(x>mx) {mx=x;ii=i,jj=j,kk=k;}}
        else { if(x>=mx){mx=x;ii=i,jj=j,kk=k;}}
    }
    // cerr<<"\nMax reduction->"<<ii<<" "<<jj<<" "<<kk<<" of "<<mx;
    vector<string> justPassItDude;
    for(int i=0;i<n;i++) if(i!=ii && i!=jj && i!=kk) justPassItDude.push_back(ar[i]);
    justPassItDude.push_back(combine(ar[ii],ar[jj],ar[kk]));
    return getRes(justPassItDude,at);
}

void removeDups(vector<string> &ar){
    sort(ar.begin(),ar.end());
    vector<string> res;
    for(int i=0;i<ar.size();i++)if(!res.size()||res.back()!=ar[i])res.push_back(ar[i]);
    ar=res;
}

int solve(vector<string> &A) {
    removeDups(A);
    bool withEquality=0;
    withEquality=1;
    string res1 = getRes(A,withEquality); 
    string res2 = getRes(A,withEquality); 
    return min(res1.size(),res2.size());
}

int main() {
	int n;
	cin>>n;
    vector<string> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	cerr<<"\n"<<solve(vec);
	return 0;
}

/*
BORDER TEST CASES:
10 nejqokaplfbrqe cjqpuidbwnbaml naiwqahtpubspt jvidmdlrhjhkjt pjvyhpbqlsm lcgkneuqsydk mruvnqlapmjhp sioft nehtaxnb xlpsgn

5 
rsdowi 
xlidxdiixperv 
eavnwypdinwdr 
acvanhelkov 
edcax

6 
inlocbpjeomukp 
sqhvo 
poserdbwicfxqw 
romveb 
qtojkyfbpwridm 
hlvltvcqyvfms
*/