#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n = 50;
vector<long long> arr(n, -1);


long long fib_loop(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long a = 0, b = 1;
    long long temp;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return temp;
}


int main() {
    struct timespec start, end;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < n; ++i) {
        arr[i] = fib_loop(i);
        cout << arr[i] << " ";
        
    }
    cout << endl;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;
    cout << seconds << " seconds and " << nanoseconds << " nanoseconds have elapsed!" << endl;
    cout << "Time elapsed : " << seconds + nanoseconds*1e-9 << endl;
    return 0;
}