ans = 0
def zigzag (N, perm, num_bool, last_num, up):
    if (len(perm) == N):
        global ans
        ans += 1
        return

    if (up):
        for i in range(last_num+1, N+1):
            if (num_bool[i] == 0):
                num_bool[i] = 1
                zigzag(N, perm + [i], num_bool, i, False)
                num_bool[i] = 0
    else:
        for i in range(last_num-1, 0, -1):
            if (num_bool[i] == 0):
                num_bool[i] = 1
                zigzag(N, perm + [i], num_bool, i, True)
                num_bool[i] = 0

N = int(input())
zigzag(N, [], [0] * (N + 1), 0, True)
if (N > 1):
    zigzag(N, [], [0] * (N + 1), N + 1, False)
print(ans)         