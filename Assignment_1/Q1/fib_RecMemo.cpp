#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n = 50;
vector<long long> memo(n, -1);

long long fib_recmemo(int n) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fib_recmemo(n - 1) + fib_recmemo(n - 2);
    return memo[n];
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < n; ++i) {
        cout << fib_recmemo(i) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;
    cout << seconds << " seconds and " << nanoseconds << " nanoseconds have elapsed!" << endl;
    cout << "Time elapsed : " << seconds + nanoseconds*1e-9 << endl;
    return 0;
}
