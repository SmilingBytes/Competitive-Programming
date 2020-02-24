from sys import stdin, stdout


def main():
    t = int(stdin.readline())
    for _ in range(t):
        s, i, e = map(int, stdin.readline().split())
        m = s + e
        if m <= i:
            print(0)
        else:
            ans = 0
            while m > i:
                m -= 1
                i += 1
                ans += 1
            print(ans)


if __name__ == "__main__":
    main()
