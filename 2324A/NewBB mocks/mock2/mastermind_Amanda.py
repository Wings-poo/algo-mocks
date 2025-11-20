'''
OpenKattis
mastermind
Code by: Amanda Lim
'''

N, A, B = input().split(' ')
N = int(N)

alphabetA = [0]*26
alphabetB = [0]*26
r = 0
s = 0
for i in range(len(A)):
    if (A[i] == B[i]):
        r += 1
    else:
        alphabetA[ord(A[i]) - ord('A')] += 1
        alphabetB[ord(B[i]) - ord('A')] += 1

for i in range(26):
    s += min(alphabetA[i], alphabetB[i])

print(r,s)