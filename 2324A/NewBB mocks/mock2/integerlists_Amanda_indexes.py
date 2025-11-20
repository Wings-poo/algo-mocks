'''
OpenKattis
integerlists
Code by: Amanda Lim
'''

T = int(input())
for t in range(T):
    BAPC = input().strip()

    N = int(input())
    list_of_int = input().strip()
    list_of_int = list_of_int[1:-1]
    
    list_of_int = list_of_int.split(',')
    if (N == 0):
        list_of_int.clear()
    
    A = 0
    B = N
    reverse = False
    error = False
    for i in BAPC:
        if i == 'R':
            reverse = not reverse
        else:
            if A >= B:
                error = True
                break
            else:
                if reverse:
                    B -= 1
                else:
                    A += 1
    
    if error:
        print("error")
    else:
        print('[', end="")
        if reverse:
            for i in range(B - 1, A - 1,-1):
                print(list_of_int[i], end="")
                if (i > A):
                    print(',', end="")
        else:
            for i in range(A,B):
                print(list_of_int[i], end="")
                if (i < B - 1):
                    print(',', end="")
        print(']')
