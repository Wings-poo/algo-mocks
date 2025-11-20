'''
OpenKattis
filip
Code by: Amanda Lim
'''

def flip (N):
    newN = 0

    while N:
        newN *= 10
        newN += N%10
        N //= 10
    
    return newN

A, B = input().split(' ')
print(max(flip(int(A)), flip(int(B))))