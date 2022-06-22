#include <bits/stdc++.h>
using namespace std;

#define d 256

void RabinKarp(string pat, string txt, int q) {
	int M = pat.size(), N = txt.size();
	int i, j;
	int p = 0, t = 0;
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (i = 0; i <= N - M; i++) {
		if (p == t) {
			for (j = 0; j < M; j++)
				if (txt[i + j] != pat[j])
                    break; // chac chan khong tim duoc, bo qua

			if (j == M)
				cout << i + 1 << '\t';
		}

		// tinh lai hash
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;
			if (t < 0)
                t = (t + q); // dam bao t luon duong
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	string text, pattern;

	getline(cin, text); getline(cin, pattern);

	// Loi dung phep Overflow de tinh mod
	int q = INT_MAX;

	RabinKarp(pattern, text, q);

	return 0;
}
