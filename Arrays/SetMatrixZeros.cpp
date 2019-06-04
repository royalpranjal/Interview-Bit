//https://www.geeksforgeeks.org/a-boolean-matrix-question/
void Solution::setZeroes(vector<vector<int> > &A) {
    
    int R = A.size();
    int C = A[0].size();
    
    bool row[R]; 
    bool col[C]; 
  
    int i, j; 
      
    for (i = 0; i < R; i++) 
    { 
    row[i] = 0; 
    } 
  
    for (i = 0; i < C; i++) 
    { 
       col[i] = 0; 
    } 
  
    for (i = 0; i < R; i++) 
    { 
        for (j = 0; j < C; j++) 
        { 
            if (A[i][j] == 0) 
            { 
                row[i] = 1; 
                col[j] = 1; 
            } 
        } 
    } 
    
    for(i = 0; i < R; i++) 
    { 
        for (j = 0; j < C; j++) 
        { 
            if ( row[i] == 1 || col[j] == 1 ) 
            { 
                A[i][j] = 0; 
            } 
        } 
    }
}
