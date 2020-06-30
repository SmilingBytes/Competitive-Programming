/**
 *    author:  ismail
 *    created: 29.06.2020  22:44:23
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

const int INIT = 1001001001;
const int MN = 200001;

struct Book {
  int num;
  bool a, b;
  ll time;
};

struct comp_time {
  inline const bool operator()(const Book& a, const Book& b) {
    return a.time > b.time;
  }
};
struct comp_rev_time {
  inline const bool operator()(const Book& a, const Book& b) {
    return a.time < b.time;
  }
};

int get_time(const priority_queue<Book, vector<Book>, comp_time>& pq) {
  if (pq.empty()) return INIT;
  return pq.top().time;
}

Book book[MN];

void solve() {
  ll N, M, K;
  cin >> N >> M >> K;

  bool c1, c2;
  for (int i = 0; i < N; i++) {
    cin >> book[i].time >> book[i].a >> book[i].b;
    book[i].num = i + 1;
  }

  priority_queue<Book, vector<Book>, comp_time> alice, bob, both, other;
  for (int i = 0; i < N; i++) {
    if (book[i].a && book[i].b) {
      both.push(book[i]);
    } else if (book[i].a) {
      alice.push(book[i]);
    } else if (book[i].b) {
      bob.push(book[i]);
    } else {
      other.push(book[i]);
    }
  }
  priority_queue<Book, vector<Book>, comp_rev_time> used_a, used_b, used_both,
      used_other;

  ll ans = 0;
  int ct = 0, total = 0;
  while (alice.size() + bob.size() + both.size() > 0 && (ct < K)) {
    int ab = INIT;
    if (alice.size() > 0 && bob.size() > 0) {
      ab = alice.top().time + bob.top().time;
    }
    int c = INIT;
    if (both.size() > 0) {
      c = both.top().time;
    }
    if (ab == INIT && c == INIT) {
      ans = -1;
      break;
    }

    if (ab < c) {
      used_a.push(alice.top());
      used_b.push(bob.top());

      alice.pop();
      bob.pop();
      ans += ab;
      total += 2;
    } else {
      used_both.push(both.top());

      both.pop();
      ans += c;
      total += 1;
    }
    ++ct;
  }

  if (ct < K) {
    cout << -1 << endl;
    return;
  }

  int cta = ct, ctb = ct;
  while (total < M) {
    if (alice.size() + bob.size() + both.size() + other.size() == 0) {
      cout << -1 << endl;
      return;
    }
    int opts[] = {get_time(alice), get_time(bob), get_time(both),
                  get_time(other)};
    int idx = min_element(opts, opts + 4) - opts;

    assert(opts[idx] != INIT);

    ans += opts[idx];
    ++total;
    if (idx == 0) {
      used_a.push(alice.top());
      alice.pop();

      ++cta;
    } else if (idx == 1) {
      used_b.push(bob.top());
      bob.pop();

      ++ctb;
    } else if (idx == 2) {
      used_both.push(both.top());
      both.pop();
    } else if (idx == 3) {
      used_other.push(other.top());
      other.pop();
    } else
      assert(false);

    while (cta > K && used_both.size() > 0 &&
           used_both.top().time > get_time(bob)) {
      ans += bob.top().time - used_both.top().time;
      both.push(used_both.top());
      used_both.pop();

      used_b.push(bob.top());
      bob.pop();

      --cta;
    }
    while (ctb > K && used_both.size() > 0 &&
           used_both.top().time > get_time(alice)) {
      ans += alice.top().time - used_both.top().time;
      both.push(used_both.top());
      used_both.pop();

      used_a.push(alice.top());
      alice.pop();

      --ctb;
    }
  }
  while (total > M) {
    if (used_a.empty() || used_b.empty() || both.empty()) {
      cout << -1 << endl;
      return;
    }
    ans += both.top().time - used_a.top().time - used_b.top().time;
    alice.push(used_a.top());
    used_a.pop();

    bob.push(used_b.top());
    used_b.pop();

    used_both.push(both.top());
    both.pop();

    --total;
  }

  cout << ans << endl;
  while (used_a.size() > 0) {
    cout << used_a.top().num << ' ';
    used_a.pop();
  }
  while (used_b.size() > 0) {
    cout << used_b.top().num << ' ';
    used_b.pop();
  }
  while (used_both.size() > 0) {
    cout << used_both.top().num << ' ';
    used_both.pop();
  }
  while (used_other.size() > 0) {
    cout << used_other.top().num << ' ';
    used_other.pop();
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  return solve(), 0;
}