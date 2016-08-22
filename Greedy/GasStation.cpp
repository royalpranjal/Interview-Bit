// https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int fuel = 0, start_i = 0, sum = 0;
    
    for(int i = 0; i < gas.size(); i++){
        sum = sum + (gas[i] - cost[i]);
        fuel = fuel + (gas[i] - cost[i]);
        if(fuel < 0){
            fuel = 0;
            start_i = i+1;
        }
    }
    
    if(sum >= 0){
        return start_i%(gas.size());
    }
    
    return -1;
}
