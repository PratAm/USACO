/*
ID: amarpra1
PROG: calfflac
LANG: C++
*/

#include <fstream>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

int countLetters(string s) {
    int total = 0;

    for (unsigned int i = 0; i < s.size(); i++)
        if (isalpha(s[i]))
            total++;

    return total;
}

string removeOtherCharsAndFormat(string s, map<int, int> & realIndexes) {
    string res = "";
    int v = 0;

    for (unsigned int i = 0; i < s.size(); i++)
        if (isalpha(s[i])) {
            res += tolower(s[i]);
            realIndexes[v++] = i;
        }

    return res;
}

string getLargestPalindrome(string input) {
    int bestPalindrome = -1;
    int bestStart = 0;
    int bestEnd = 0;
    map<int, int> realIndexes;
    string formattedInput = removeOtherCharsAndFormat(input, realIndexes);
    int N = formattedInput.size();

    for (int i = 0; i < N; i++) {
        // odd-sized palindromes
        for (int j = 0; j <= 2000 && (i - j) >= 0 && (i + j) < N; j++) {
            if (formattedInput[i - j] == formattedInput[i + j]) {
                if (j * 2 + 1 > bestPalindrome) {
                    bestPalindrome = j * 2 + 1;
                    bestStart = i - j;
                    bestEnd = i + j;
                }
            } else {
                break;
            }
        }

        // even-sized palindromes
        if (i + 1 < N && formattedInput[i + 1] == formattedInput[i]) {
            for (int j = 0; j <= 2000 && (i - j) >= 0 && (i + 1 + j) < N; j++) {
                if (formattedInput[i - j] == formattedInput[i + 1 + j]) {
                    if (j * 2 + 2 > bestPalindrome) {
                        bestPalindrome = j * 2 + 2;
                        bestStart = i - j;
                        bestEnd = i + 1 + j;
                    }
                } else {
                    break;
                }
            }
        }
    }

    return input.substr(realIndexes[bestStart],
                        realIndexes[bestEnd] - realIndexes[bestStart] + 1);
}

int main() {
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");

    string input;
    string temp;
    while (getline(fin, temp)) {
        input += temp + '\n';
    }
    input = input.substr(0, input.size() - 1);

    string palindrome = getLargestPalindrome(input);
    fout << countLetters(palindrome) << endl;
    fout << palindrome << endl;

		fin.close();
		fout.close();

    return 0;
}
