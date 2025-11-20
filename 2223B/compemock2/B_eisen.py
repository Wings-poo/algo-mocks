while True:
    idx = int(input()) - 1

    if idx == -1:
        break

    bin_val = bin(idx)[2:][::-1]
    PS = []

    for exp in range(len(bin_val)):
        if bin_val[exp] == '1':
            PS.append(3**exp)

    PS = list(map(str, PS))
    if PS == []:
        print('{ }')
    else:
        print('{ ' + ', '.join(PS) + ' }')
