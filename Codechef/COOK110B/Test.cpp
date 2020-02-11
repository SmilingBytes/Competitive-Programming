#include <bits/stdc++.h>
#include <stdio.h>

int main(void) {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  long long unsigned A, B, C, sum, half, half2, half3;
  int ans = 3;

  scanf("%d", &t);
  for (int c = 0; c < t; c++) {
    scanf("%llu%llu%llu", &A, &B, &C);
    printf("%llu %llu %llu => ", A, B, C);

    sum = A + 2 * B + 3 * C;

    if (sum % 2 == 0) {
      half = sum / 2;
      if (half % 2 == 0 && half / 2 <= B) {
        printf("YES\n");
        continue;
      }
      if (half % 3 == 0 && half / 3 <= C) {
        printf("YES\n");
        continue;

      } else {
        if (half / 3 <= C) {
          half2 = half - 3 * (half / 3);
          if (half2 / 2 <= B) {
            half3 = half2 - 2 * (half2 / 2);
            if (half3 <= A) {
              printf("YES\n");
              continue;
            } else {
              printf("NO\n");
              continue;
            }
          } else {
            half3 = half2 - 2 * B;
            if (half3 <= A) {
              printf("YES\n");
              continue;
            } else {
              printf("NO\n");
              continue;
            }
          }
        } else {
          half2 = half - 3 * C;
          if (half2 / 2 <= B) {
            half3 = half2 - 2 * (half2 / 2);
            if (half3 <= A) {
              printf("YES\n");
              continue;
            } else {
              printf("NO\n");
              continue;
            }
          } else {
            half3 = half2 - 2 * B;
            if (half3 <= A) {
              printf("YES\n");
              continue;
            } else {
              printf("NO\n");
              continue;
            }
          }
        }
      }

    } else {
      printf("NO\n");
      continue;
    }
  }
  return 0;
}
