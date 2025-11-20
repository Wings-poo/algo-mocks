'''
OpenKattis
integerlists
Code by: Amanda Lim
'''

from collections import deque

T = int(input())
for t in range(T):
    BAPC = input().strip()

    N = int(input())
    list_of_int = input().strip()
    list_of_int = list_of_int[1:-1]
    
    list_of_int = deque(list_of_int.split(','))
    if (N == 0):
        list_of_int.clear()

    reverse = False
    error = False
    for i in BAPC:
        if i == 'R':
            reverse = not reverse
        else:
            if bool(list_of_int) == False:
                error = True
                break
            if reverse:
                list_of_int.pop()
            else:
                list_of_int.popleft()
    
    if error:
        print("error")
    else:
        print('[', end="")
        if reverse:
            for i in range(len(list_of_int) - 1, -1,-1):
                print(list_of_int[i], end="")
                if (i > 0):
                    print(',', end="")
        else:
            for i in range(0,len(list_of_int)):
                print(list_of_int[i], end="")
                if (i < len(list_of_int) - 1):
                    print(',', end="")
        print(']')