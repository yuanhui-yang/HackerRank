// No Prefix Set
// https://www.hackerrank.com/challenges/no-prefix-set

/*
Given  strings. Each string contains only lowercase letters from (both inclusive). The set of  strings is said to be GOOD SET if no string is prefix of another string else, it is BAD SET. (If two strings are identical, they are considered prefixes of each other.)

For example, aab, abcde, aabcd is BAD SET because aab is prefix of aabcd.

Print GOOD SET if it satisfies the problem requirement. 
Else, print BAD SET and the first string for which the condition fails.

Input Format 
First line contains , the number of strings in the set. 
Then next  lines follow, where  line contains  string.

Constraints 
 
 Length of the string 

Output Format 
Output GOOD SET if the set is valid. 
Else, output BAD SET followed by the first string for which the condition fails.

Sample Input00

7
aab
defgab
abcde
aabcde
cedaaa
bbbbbbbbbb
jabjjjad
Sample Output00

BAD SET
aabcde
Sample Input01

4
aab
aac
aacghgh
aabghgh
Sample Output01

BAD SET
aacghgh
Explanation 
aab is prefix of aabcde. So set is BAD SET and it fails at string aabcde.
*/

#include <iostream>
#include <array>
#include <string>
using namespace std;

struct Node {
	array<Node*, 10> next;
	bool isEnd;
	Node () {
		next.fill(NULL);
		isEnd = false;
	}
};

struct Trie {
	Node * root;
	Trie() {
		root = new Node();
	}
	void insert(string str) {
		Node * it = root;
		for (const auto & ch : str) {
			int id = ch - 'a';
			if (!it->next[id]) {
				it->next[id] = new Node();
			}
			it = it->next[id];
		}
		it->isEnd = true;
	}
	bool search(string str) {
		Node * it = root;
		for (const auto & ch : str) {
			int id = ch - 'a';
			it = it->next[id];
			if (!it) {
				return false;
			}
			if (it->isEnd) {
				return true;
			}
		}
		return true;
	}
};

int main(void) {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	Trie tree;
	int N;
	cin >> N;
	while (N-- > 0) {
		string str;
		cin >> str;
		if (tree.search(str)) {
			cout << "BAD SET\n" << str << '\n';
			return 0;
		}
		tree.insert(str);
	}
	cout << "GOOD SET\n";
	return 0;
}
