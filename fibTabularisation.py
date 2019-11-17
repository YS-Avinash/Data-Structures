fib_series=[0,1]
n=int(input())
for i in range(2,n):
    fib_series.append(fib_series[i-2]+fib_series[i-1])
print(*fib_series,sep=",")
