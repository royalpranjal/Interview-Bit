bool isadjacent(string s,string t)
{
    int c=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        c++;
        if(c>1)
        return false;
    }
    
    return c==1? true: false;

}
  
struct node 
{ 
    string word; 
    int len; 
}; 

int Solution::ladderLength(string start, string target, vector<string> &dict) {
    
    if(start==target)
    return 1;
    
    set <string> D;
    
     for(int i=0;i<dict.size();i++){
         string x=dict[i];
         D.insert(x);
     }

    queue<node> q; 
    node item = {start, 1};  
    q.push(item); 
  
    while (!q.empty()) 
    { 
        node curr = q.front(); 
        q.pop(); 
  
        for (set<string>::iterator it = D.begin(); it != D.end(); it++) 
        { 
            string temp = *it; 
            if (isadjacent(curr.word, temp)) 
            { 
                item.word = temp; 
                item.len = curr.len + 1; 
                q.push(item); 
  
                D.erase(temp); 
  
                if (temp == target) 
                  return item.len; 
            } 
        } 
    } 
    
    return 0;
}
