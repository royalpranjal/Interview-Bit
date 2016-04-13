// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {

    int steps = 0, dx, dy, i = 0;

    //cout << X[0] << "," << Y[0] << " " << X[1] << "," << Y[1];

    if(X.size() <=1 || Y.size() <= 1 || X.size() != Y.size()){
        return 0;
    }

    do{
        dx = X[i] - X[i+1];
        dy = Y[i] - Y[i+1];

        if(dx < 0){
            dx = -dx;
        }
        if(dy < 0){
            dy = -dy;
        }

        while( dx != 0 && dy != 0 ){
            dx--;
            dy--;
            steps++;
        }
        if(dx == 0){
            steps = steps + dy;
        }
        else{
            steps = steps + dx;
        }
        i++;
    }while(i < X.size()-1);

    return steps;
}
