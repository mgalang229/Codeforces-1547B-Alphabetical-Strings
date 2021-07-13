#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		// check if 'a' is found in the string
		size_t L = s.find('a');
		if (L == string::npos) {
			cout << "NO\n";
			continue;
		}
		// set 'n' with the value of the size of string 's'
		size_t n = s.length();
		// set 'R' with the value of 'L' (index of 'a')
		size_t R = L;
		bool yes = true;
		// start the loop with 1 (letter 'b')
		for (size_t i = 1; i < n; i++) {
			// find the position of the current letter being checked
			size_t pos = s.find(char('a' + i));
			// check if the position is either in the previous adjacent or the next adjacent
			// position of the string being formed
			if (pos == string::npos || (pos != L - 1 && pos != R + 1)) {
				yes = false;
				break;
			} else {
				// modify the left and right pointers depending on where the current letter is
				L = min(L, pos);
				R = max(R, pos);
			}
		}
		cout << (yes ? "YES" : "NO") << '\n';
	}
	return 0;
}
