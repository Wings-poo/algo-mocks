'''
OnlineJudge
10212 - The Last Non-zero Digit
Code by: Amanda Lim
'''

from sys import stdin

# WA
def permutation (A, B):
    ans = 1
    diff = B - A
    diff //= 10
    print(A, B, diff, 8*diff)
    ans *= 8*diff
    
    if (ans == 0):
        ans = 1

    while (A%10 != 0):
        ans *= A
        A += 1
    while (B%10 != 0):
        ans *= B
        B -= 1

    while (ans%10 == 0):
        ans //= 10

    return ans%10

# TLE
def perm (A, B):
    ans = 1
    for i in range(A, B+1):
        ans *= i
        print(ans)
    while (ans%10 == 0):
        ans //= 10

    return ans%10 

for line in stdin:
    inp = line.split(' ')
    N = int(inp[0])
    M = int(inp[1])
    print(permutation(N-M+1, N))
    print(perm(N-M+1,N))
