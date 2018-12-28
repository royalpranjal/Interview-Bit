//see this to check other variations of fizzbuzz: https://www.geeksforgeeks.org/fizz-buzz-implementation/

vector<string> Solution::fizzBuzz(int A) {
    vector<string> v;
    for(int i=1; i<=A; i++)
    {
        if(i%15==0)
            v.push_back("FizzBuzz");
        else if(i%3==0)
            v.push_back("Fizz");
        else if(i%5==0)
            v.push_back("Buzz");
        else
            v.push_back(to_string(i));
    }
    return v;
}
