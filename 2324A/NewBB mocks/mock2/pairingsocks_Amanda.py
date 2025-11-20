'''
OpenKattis
pairingsocks
Code by: Amanda Lim
'''

from queue import LifoQueue, Queue
N = int(input())
sockpile = Queue(maxsize = 2*N)

socks = input().split()
for i in socks:
    sockpile.put(i)

othersockpile = LifoQueue(maxsize = 2*N)
moves = 0

while (sockpile.qsize() > 0):
    sock = sockpile.get_nowait()
    taken = False

    if (othersockpile.qsize() > 0):
        othersock = othersockpile.get_nowait()
        if (sock == othersock):
            moves += 1
            taken = True
        else:
            othersockpile.put_nowait(othersock)
    
    if (not taken):
        othersockpile.put_nowait(sock)
        moves += 1

if (othersockpile.qsize() == 0):
    print(moves)
else:
    print("impossible")