#include <iostream>
using namespace std;
int main() {
int b, t, tot=538;
//get counts
cout << "Enter B then T's votes: ";
cin >> b;
cin >> t;
//check if either number is 270 or more
if(b>269) {
	cout << "B wins!";
}
else if(t>269) {
	cout << "T wins!";
}
else {
	//calc votes each needs to win
	b=270-b;
	t=270-t;
	//number of votes needed for b and t
	cout << "No winner yet. B needs " << b << " votes to win." << endl;
	cout << "T needs " << t << " votes to win." << endl;
	//percent of remaining votes each needs
	b=b*100/(b+t-2);
	t=t*100/(b+t-2);
	cout << "B needs " << b << "% of the remaining vote. T needs " << t << "% of the remaining vote.";
}
return 0;
}