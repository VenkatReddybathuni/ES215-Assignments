#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <sys/resource.h>
#include <iomanip> 
using namespace std;
using namespace chrono;

struct  usage;


void matrixMultiplicationInt(int N, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>>& C) {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

}
void matrixMultiplicationDouble(int N, vector<vector<double>> A, vector<vector<double>> B, vector<vector<double>>& C) {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

}
// pair<double, double> giveUsageTime(auto usage_start, auto usage_end){
//     double user_time = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) + (usage_end.ru_utime.tv_nsec - usage_start.ru_utime.tv_nsec) / 1e9;
//     double system_time = (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec) + (usage_end.ru_stime.tv_nsec - usage_start.ru_stime.tv_nsec) / 1e9;
//     return {user_time, system_time}

// }
auto giveChronoTime(auto start, auto end){
    return end - start;
}

int main() {
    struct rusage usage_start, usage_end;
    vector<double> IntSys;
    vector<double> IntCPU;
    vector<double> DoubleSys;
    vector<double> DoubleCPU;
    for (int N : {64, 128, 256, 512, 1024}) {
        
        vector<vector<int>> A(N, vector<int>(N, 3));
        vector<vector<int>> B(N, vector<int>(N, 7));
        vector<vector<int>> C(N, vector<int>(N, 0));
        auto total_start = chrono::high_resolution_clock::now();
        getrusage(RUSAGE_SELF, &usage_start);
        auto meat_start = chrono::high_resolution_clock::now();
        matrixMultiplicationInt(N, A, B, C);
        auto meat_end = chrono::high_resolution_clock::now();
        getrusage(RUSAGE_SELF, &usage_end);
        auto total_end = chrono::high_resolution_clock::now();
        double user_time = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) + (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1e6;
        double system_time = (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec) + (usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec) / 1e6;
        IntSys.push_back(system_time);
        IntCPU.push_back(system_time+ user_time);
        // pair<double, double> times = giveUsageTime(usage_start, usage_end);
        cout << "For N = " << N  << " Int matrix multiplication" << endl;
        cout << "User CPU time: " << fixed << setprecision(12) << user_time<< " seconds" << endl;
        cout << "System CPU time: " << fixed << setprecision(12) << system_time << " seconds" << endl;
        cout << "Total CPU time :" << fixed << setprecision(12) << user_time+ system_time << "Seconds" << endl;
        chrono::duration<double> meat_duration = giveChronoTime(meat_start, meat_end);
        chrono::duration<double> total_duration = giveChronoTime(total_start, total_end);
        cout << fixed << setprecision(9);
        cout << "Meat portion time: " << meat_duration.count() << " seconds" << endl;
        cout << "Total execution time: " << total_duration.count() << " seconds" << endl;

        double proportion = (meat_duration.count() / total_duration.count()) * 100;
        cout << "Proportion of meat portion: " << proportion << "%" << endl;
        cout << string(50, '=') << endl;
        cout << endl;


    }

    for (int N : {64, 128, 256, 512, 1024}) {
        
        vector<vector<double>> A(N, vector<double>(N, 3));
        vector<vector<double>> B(N, vector<double>(N, 7));
        vector<vector<double>> C(N, vector<double>(N, 0));
        auto total_start = chrono::high_resolution_clock::now();
        getrusage(RUSAGE_SELF, &usage_start);
        auto meat_start = chrono::high_resolution_clock::now();
        matrixMultiplicationDouble(N, A, B, C);
        auto meat_end = chrono::high_resolution_clock::now();
        getrusage(RUSAGE_SELF, &usage_end);
        auto total_end = chrono::high_resolution_clock::now();
        double user_time = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) + (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1e6;
        double system_time = (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec) + (usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec) / 1e6;
        // pair<double, double> times = giveUsageTime(usage_start, usage_end);
        DoubleSys.push_back(system_time);
        DoubleCPU.push_back(system_time+ user_time);
        cout << "For N = " << N  << " Double matrix multiplication" << endl;
        cout << "User CPU time: " << fixed << setprecision(12) << user_time<< " seconds" << endl;
        cout << "System CPU time: " << fixed << setprecision(12) << system_time << " seconds" << endl;
        cout << "Total CPU time :" << fixed << setprecision(12) << user_time+ system_time << "Seconds" << endl;
        chrono::duration<double> meat_duration = giveChronoTime(meat_start, meat_end);
        chrono::duration<double> total_duration = giveChronoTime(total_start, total_end);
        cout << fixed << setprecision(9);
        cout << "Meat portion time: " << meat_duration.count() << " seconds" << endl;
        cout << "Total execution time: " << total_duration.count() << " seconds" << endl;

        double proportion = (meat_duration.count() / total_duration.count()) * 100;
        cout << "Proportion of meat portion: " << proportion << "%" << endl;
        cout << string(50, '=') << endl;
        cout << endl;

    }
    
    return 0;
}
