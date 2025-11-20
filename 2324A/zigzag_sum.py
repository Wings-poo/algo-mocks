ans = 0
def zigzag (N, sums_until_N, curr_sum, perm, last_num, up):
    if (curr_sum == N):
        global ans
        ans += 1
        sums_until_N[N] += 1
        return
    
    sums_until_N[curr_sum] += 1

    if (up):
        for i in range(last_num+1, N+1):
            zigzag(N, perm + [i], num_bool, i, False)
    else:
        for i in range(last_num-1, 0, -1):
            zigzag(N, perm + [i], num_bool, i, True)

N = int(input())
zigzag(N, [], [0] * (N + 1), 0, True)
if (N > 1):
    zigzag(N, [], [0] * (N + 1), N + 1, False)
print(ans)         