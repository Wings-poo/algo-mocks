def f(x, a, b):
    return x * (a * x + b)

def ternary_search(l, r, a, b):
    while r - l > EPS:
        m1 = l + (r - l) / 3
        m2 = r - (r - l) / 3
        f1 = f(m1, a, b)
        f2 = f(m2, a, b)
        if f1 < f2:
            l = m1
        else:
            r = m2
    return f(l, a, b)

def height(xt, a, b):
    return ternary_search(0, xt, a, b)

def gauss(dp, col, n):
    for j in range(n - 1):
        l = j
        for i in range(j + 1, n):
            if (abs(dp[i][j]) > abs(dp[l][j])):
                l = i
        for k in range(j, n + 1):
            dp[j][k], dp[l][k] = dp[l][k], dp[j][k]
        for i in range(j + 1, n):
            for k in range(j, n + 1)[::-1]:
                dp[i][k] -= dp[j][k] * dp[i][j] / dp[j][j]
    for j in range(n)[::-1]:
        t = 0
        for k in range(j + 1, n):
            t += dp[j][k] * col[k]
        col[j] = (dp[j][n] - t) / dp[j][j]

def solve(dp, col, xt, yt, x, y):
    dp[0][0] = x ** 2
    dp[0][1] = x
    dp[0][2] = y
    dp[1][0] = xt ** 2
    dp[1][1] = xt
    dp[1][2] = yt

    gauss(dp, col, 2)

    return col[0], col[1]

def main():
    for _ in range(int(input())):
        xs, ys, xt, yt = map(int, input().split())
        xt -= xs
        yt -= ys

        obstacles = list()
        for _ in range(int(input())):
            xi, yi = map(int, input().split())
            obstacles.append((xi, yi))
        
        dp = list(list(0 for _ in range(MAX)) for _ in range(MAX + 1))
        column = list(0 for _ in range(MAX))

        maximum = max(0, yt)
        for a, b in obstacles:
            x = a - xs
            y = b - ys
            maximum = max(maximum, height(xt, *solve(dp, column, xt, yt, x, y)))
        
        print(round(maximum + ys, 6))

if __name__ == '__main__':
    MAX = 1001
    EPS = 1e-6

    main()