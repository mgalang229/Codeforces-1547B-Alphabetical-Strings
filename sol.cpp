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
		// store 's' in another string variable 'temp'
		string temp = s;
		// sort 'temp' in non-decreasing order
		sort(temp.begin(), temp.end());
		bool checker = true;
		// check if the 'temp' string has duplicate letters
		for (int i = 0; i < (int) temp.size() - 1; i++) {
			if (temp[i] == temp[i + 1]) {
				checker = false;
				break;
			}
		}
		// create a string with contents of letters in the correct order with same size of 'temp'
		string letters = "";
		for (int i = 0; i < (int) temp.size(); i++) {
			letters += string(1, 'a' + i);
		}
		// check if 'temp' is in alphabetical order and if it starts with letter 'a'
		for (int i = 0; i < (int) temp.size(); i++) {
			if (temp[i] != letters[i]) {
				checker = false;
				break;
			}
		}
		if (!checker) {
			// if 'checker' is equal to false, then output NO
			cout << "NO\n";
			continue;
		}
		// locate the index of letter 'a' in string 's'
		int index = -1;
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] - 'a' == 0) {
				index = i;
				break;
			}
		}
		// check if all the values BEFORE letter 'a' is in decreasing order
		for (int i = 0; i < index - 1; i++) {
			if (s[i] < s[i + 1]) {
				// if it becomes false, then set 'checker' to false and break the loop
				checker = false;
				break;
			}
		}
		// check if all the values AFTER letter 'a' is in increasing order
		for (int i = index + 1; i < (int) s.size() - 1; i++) {
			if (s[i] > s[i + 1]) {
				// if it becomes false, then set 'checker' to false and break the loop
				checker = false;
				break;
			}
		}
		cout << (checker ? "YES" : "NO") << '\n';
	}
	return 0;
}
