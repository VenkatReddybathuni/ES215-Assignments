import numpy as np
import time
import resource

def matrix_multiply(A, B, C):
    
    N = len(A)
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    return C

def calTime(start, end):
    return end - start

def measure_time(N, dtype):
    
    A = np.ones((N, N), dtype=dtype)
    B = np.ones((N, N), dtype=dtype)
    C = np.ones((N, N), dtype=dtype)
    
    total_start = time.time()
    usage_start = resource.getrusage(resource.RUSAGE_SELF)

    
    meat_start = time.time()
    matrix_multiply(A, B, C)
    meat_end = time.time()

    
    usage_end = resource.getrusage(resource.RUSAGE_SELF)
    total_end = time.time()

    
    # total_duration = total_end - total_start
    # meat_duration = meat_end - meat_start

    total_duration = calTime(total_start, total_end)
    meat_duration = calTime(meat_start, meat_end)
    user_time = (usage_end.ru_utime - usage_start.ru_utime)
    system_time = (usage_end.ru_stime - usage_start.ru_stime)

   
    print(f"N = {N}, dtype = {dtype}")
    print(f"Meat portion time: {meat_duration:.9f} seconds")
    print(f"Total execution time: {total_duration:.9f} seconds")
    print(f"Proportion of meat portion: {(meat_duration / total_duration) * 100:.9f}%")
    print(f"User CPU time: {user_time:.12f} seconds")
    print(f"System CPU time: {system_time:.12f} seconds")
    print(f"CPU time: {system_time + user_time:.12f} seconds")
    print("=" * 50)

for N in [64, 128, 256, 512, 1024]:
    measure_time(N, int)
    measure_time(N, float)
