static const int MODULUS = 1000000007;

// compute 2^k modulo MODULUS
int power2modulo(int k)
{
    long result = 1;
    for (int i=0; i<k; i++) {
        result = (result + result) % MODULUS;
    }
    return result;
}

// compute greatest common divisor
int gcd(int A, int B) {
    int T;
    if (A < B)
        std::swap(A, B);
    while (B != 0) {
        T = B;
        B = A % B;
        A = T;
    }
    return A;
}

// compute binomial coefficient with modulo arithmetic
long binomial(int n, int r)
{
    priority_queue<int> numerator, denominator;
    priority_queue<int> new_numerator, new_denominator;
    int a = std::max(r, n - r);
    int b = n - a;
    long result = 1;
    long T;
    
    // do not compute factorials, but push the terms that make up the factorials
    for (int i=a+1; i<=n; i++) {
        numerator.push(i);
    }
    for (int i=2; i<=b; i++) {
        denominator.push(i);
    }
    
    // we try to cancel out the GCD of each numerator with each denominator
    int n_len = numerator.size();
    for (int i=0; i<n_len; i++) {
        int num = numerator.top();
        numerator.pop();
        if (num == 1)
            break;  // we can exit here because we use priority_queue
        int d_len = denominator.size();
        for (int j=0; j<d_len; j++) {
            int den = denominator.top();
            denominator.pop();
            // we reduce numerator and denominator using GCD
            long factor = gcd(num, den);
            num /= factor;
            den /= factor;
            if (den != 1) {
                new_denominator.push(den);
            }
            if (num == 1) {
                break;
            }
        }
        if (num != 1) {
            new_numerator.push(num);
        }
        while (!new_denominator.empty()) {
            denominator.push(new_denominator.top());
            new_denominator.pop();
        }
    }

    // at this point we should have exhausted all the denominators    
    assert(denominator.empty());
    
    // now we multiply the remaining numerator terms using modulo arithmetic
    while (!new_numerator.empty()) {
        result *= new_numerator.top();
        result %= MODULUS;
        new_numerator.pop();
    }
    
    return result;
}

// A segment is defined by a length and a multiplier.
// The length is the number of unvisited cities in a row.
// The multiplier is how many different paths can be made to visit all the cities.
typedef pair<int,int> segment_t;
typedef vector<segment_t> segments_t;

// Compute the number of permutations of paths,
// Combine the two segments at a time for ease of understanding.
// For example, consider two segments with 3 cities (AAA) and 4 cities (BBBB).
// There are 7 choose 3 ways to interleave the cities from the two segments.
// One such interleaving pattern is: ABAABBB.
// If there are X different paths for the A cities and Y different paths for B,
// the new combined segment has 7 cities and 7 choose 3 times X times Y paths.
int arrangements(segments_t &segments) {
    long num_paths;
    while (true) {
        auto itA = segments.begin();
        auto itB = segments.end()-1;
        if (itA == itB) {
            num_paths = itA->second;
            break;
        } else {
            itA->first += itB->first;
            num_paths = binomial(itA->first, itB->first);
            num_paths %= MODULUS;
            num_paths = (num_paths * itA->second) % MODULUS;
            num_paths = (num_paths * itB->second) % MODULUS;
            itA->second = num_paths;
            segments.erase(itB);
        }
    }
    return num_paths;
}

int Solution::solve(int A, vector<int> &B) {
    priority_queue<int> V;
    segments_t segments;

    if (B.size() == 0)
        return 0;

    // Insert B into priority queue V so we can sort the cities.
    for (auto p : B) {
        V.push(p);
    }

    int right = V.top();
    V.pop();
    if (right < A) {
        // Account for corner case where last region is one-sided.
        // In this case, there is only one path.
        segments.push_back(pair<int,int>(A - right, 1));
    }
    while (!V.empty()) {
        if ((V.top() + 1) == right) {
            // We skip over adjacent cities that have been visited.
            V.pop();
            --right;
        } else {
            // We make a maximal segment of consecutive unvisited cities.
            int consecutive = right;
            right = V.top();
            V.pop();
            consecutive -= right + 1;
            // For a segment of N consecutive unvisited cities bordered on both sides
            // by visited cities, there are 2^^(N-1) posible paths.
            // Record the length and number of paths.
            segments.push_back(segment_t(consecutive, power2modulo(consecutive-1)));
        }
    }
    if (right != 1) {
        // Account for corner case where last region is one-sided.
        segments.push_back(segment_t(right - 1, 1));
    }

    return arrangements(segments);
}