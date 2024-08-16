#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int n = 50;
vector<long long> arr(n);
long long fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    struct timespec start, end;

    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    for (int i = 0; i < n; ++i) {
        arr[i] = fib_recursive(i);
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
