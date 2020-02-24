n = int(input())
inc = None
hp = None
if n % 4 == 1:
    inc = 0
    print("0 A")
    exit()
rem = n % 4
if rem == 3:
    inc = 2
    hp = 'A'
elif rem == 2:
    inc = 1
    hp = 'B'
elif rem == 0:
    inc = 1
    hp = 'A'
print(str(inc) + " " + hp)

# print({0: "1 A", 1: "0 A", 2: "1 B", 3: "2 A" }[int(input()) % 4])
