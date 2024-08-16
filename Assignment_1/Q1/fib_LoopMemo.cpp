#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n = 50;
vector<long long> memo(n, -1);

void fib_loopmemo(int n) {
    
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    for (int i = 0; i < n; ++i) {
        cout << memo[i] << " ";
    }
    cout << endl;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    fib_loopmemo(n);

    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;

    cout << seconds << " seconds and " << nanoseconds << " nanoseconds have elapsed!" << endl;
    cout << "Time elapsed : " << seconds + nanoseconds*1e-9 << endl;

    return 0;
}