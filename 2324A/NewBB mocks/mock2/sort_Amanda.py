'''
OpenKattis
sort
Code by: Amanda Lim
'''

# sorting taken from GeeksforGeeks

from collections import Counter
 
N, C = input().split()

ini_list = input().split()
 
# sorting on basis of frequency of elements
result = [item for items, c in Counter(ini_list).most_common()
                                      for item in [items] * c]
 
# printing final result
for i in result:
    print(i,end=" ")