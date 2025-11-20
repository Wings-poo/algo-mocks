'''
OnlineJudge
623 - 500!
Code by: Amanda Lim
'''

from sys import stdin

factorial = [1] * 1001
num = 1
for i in range(1,1001):
    num *= i
    factorial[i] = num

for line in stdin:
    n = int(line)
    line = line[:-1]
    line = line + '!'
    print(line)
    print(factorial[n])