tiles = list(map(str, input().split()))
cnt = [0] * 3
pos = [[0 for x in range(3)] for y in 'mps']
mps = ['m', 'p', 's']

for i in range(3):
    t = tiles[i]
    p = int(mps.index(t[1]))
    cnt[p] += 1
    pos[p][i] = t[0]

if 3 in cnt:
    i = cnt.index(3)
    tmp = pos[i]
    tmp.sort()

    if int(tmp[0]) + 1 == int(tmp[1]) and int(tmp[1]) + 1 == int(tmp[2]):
        print(0)
        exit()
    elif tmp.count(tmp[0]) == len(tmp) and tmp[0] != 0:
        print(0)
        exit()
k = 0
for tmp in pos:
    tmp = list(map(int, tmp))
    tmp.sort()

    if tmp.count(0) > 1:
        continue

    k = tmp.count(tmp[0])
    if int(tmp.count(tmp[1])) > int(k):
        k = tmp.count(tmp[1])
    if k == 2:
        print(1)
        exit()

    if tmp[0] == 0  and (int(tmp[2]) - int(tmp[1])) <= 2:
        print(1)
        exit()
    elif (int(tmp[2]) - int(tmp[1])) <= 2:
        print(1)
        exit()
    elif (int(tmp[1]) - int(tmp[0])) <= 2 and tmp[0] != 0:
        print(1)
        exit()
    else:
        print(2)
        exit()
print(2)
