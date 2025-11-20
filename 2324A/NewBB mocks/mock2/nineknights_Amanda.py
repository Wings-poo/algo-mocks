'''
OpenKattis
nineknights
Code by: Amanda Lim
'''

dx = [-1,-1,1,1,-2,-2,2,2]
dy = [-2,2,-2,2,-1,1,-1,1]

grid = [] # could be []*5
for i in range(5):
    str = input() # could be grid[i] = input()
    grid.append(str)

valid = True
knights = 0
for i in range(5):
    for j in range(5):
        if (grid[i][j] == '.'):
            continue
        knights += 1

        for k in range(8):
            if (((i + dx[k]) >= 0) and ((i + dx[k]) < 5) and ((j + dy[k]) >= 0) and ((j + dy[k]) < 5)):
                if (grid[i + dx[k]][j + dy[k]] == 'k'):
                    valid = False

if (valid and (knights == 9)):
    print("valid")
else:
    print("invalid")