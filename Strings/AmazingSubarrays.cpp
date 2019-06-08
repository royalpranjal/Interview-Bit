bool isVowel(char c)
{
    c = tolower(c);
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    return true;
    
    return false;
}

int Solution::solve(string A) 
{    
    int cnt = 0;
    for(int j=0;j<A.length();j++)
    {
        if(isVowel(A[j]))
        {
            cnt = (cnt + (A.length()-j))%10003;
        }
    }
    return cnt;
}
