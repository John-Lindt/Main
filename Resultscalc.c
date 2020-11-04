#include <iostream>
using namespace std;
int main() {
int b, t, tot=538;
cout << "Enter B then T's votes: ";
cin >> b;
cin >> t;
b=270-t;
t=270-t;
if(b>269) {
	cout << "B wins!";
}
else if(t>269) {
	cout << "T wins!";
}
else {
	cout << "No winner yet. B has " << b << " votes to win." << endl;
	cout << "T has " << t << " votes to win." << endl;
	b=b*100/(538-b-t);
	t=t*100/(538-b-t);
	cout << "B needs " << b << "% of the remaining vote. T needs " << t << "% of the remaining vote.";
}
return 0;
}