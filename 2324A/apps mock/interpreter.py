registers = [0 for i in range(10)]
RAM = [0 for i in range(1000)]
counter = 0
pointer = 0

i = 0
while True:
    try:
        instruction = input()
        RAM[i] = int(instruction)
        i += 1
    except EOFError:
        break

def int_to_code(num):
    return tuple(int(q) for q in ((3 - len(str(num))) * '0') + str(num))
    
while True:
    c, x, y = int_to_code(RAM[pointer])
    pointer += 1
    counter += 1
    if counter >= 10000:
        break
    if c == 1:
            break
    elif c == 2:
            registers[x] = y
    elif c == 3:
            registers[x] = (registers[x] + y) % 1000
    elif c == 4:
            registers[x] = (registers[x] * y) % 1000
    elif c == 5:
            registers[x] = registers[y]
    elif c == 6:
            registers[x] = (registers[x] + registers[y]) % 1000
    elif c == 7:
            registers[x] = (registers[x] * registers[y]) % 1000
    elif c == 8:
            registers[x] = RAM[registers[y]]
    elif c == 9:
            RAM[registers[y]] = registers[x]
    elif c == 0:
            if not registers[y] == 0:
                pointer = registers[x]

print(counter)