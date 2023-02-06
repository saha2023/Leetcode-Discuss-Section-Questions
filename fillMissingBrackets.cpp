#include <iostream>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
bool isBalanced(int a, int b, int q) {
	int d = abs(a) + abs(b);
	if(d <= q) {
		q -=d;
		if(q%2 == 0) {
			return true;
		}
	}
	return false;
}
// Main function
int fillMissingBrackets(string s) {
	int count =0;
	int a=0, b=0, q=0, d, ta=0, tb=0, tq=0;
	int wholeStringCheck = 0;
	int n = s.size();
	if(n%2)
		return 0;

	// Compute total misbalanced occurrences of each bracket '(' & '['
	for(int i=0;i <n;i++) {
		if(s[i] == '[')
			ta++;
		if(s[i] == ']')
			ta--;
		if(s[i] == '(')
			tb++;
		if(s[i] == ')')
			tb--;
		if(s[i] == '?')
			tq++;
	}

	// Main part: Compute misbalanced occurrences of each bracket at every two character steps
	for(int i=0;i <n-1;i++) {
		if(s[i] == '[')
			a++;
		if(s[i] == ']')
			a--;
		if(s[i] == '(')
			b++;
		if(s[i] == ')')
			b--;
		if(s[i] == '?')
			q++;

		if(i%2) {
			int a2 = ta - a;
			int b2 = tb - b;
			int q2 = tq - q;
			
			// Check left & right misbalanced brackets are 'actually' balanced with or w/o help of '?'
			int firstHalf = isBalanced(a,b,q);
            int secondHalf = isBalanced(ta-a, tb-b, tq-q);
            count += (firstHalf and secondHalf);
		}
	}
	return count;
}



int main(){
    file_i_o();
    string s;
    cin>>s;
    cout<< fillMissingBrackets(s);
}