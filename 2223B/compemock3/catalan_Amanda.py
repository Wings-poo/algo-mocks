'''
OpenKattis
catalan
Code by: Amanda Lim
'''

def fact (a,b):
    f = int(1)
    for i in range(a,b+1):
        f *= int(i)
    return f

def catalan (n):
    return fact(n+1,2*n)//fact(1,n+1)

Q = int(input())
for q in range(Q):
    x = int(input())
    print(int(catalan(x)))