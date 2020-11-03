#include <iostream>
using namespace std;
void makeBell(int a);
int main() {
int conv=0;
while(conv!=-1) {
	cout << "Enter the number to bell, -1 to exit program." << endl;
	cin >> conv;
	makeBell(conv);
}
return 0;
}
void makeBell(int a) {
cout << a*.12 << " " << a*.13 << " " << a*.1 << " " << a*.26 << " " << a*.1 << " " << a*.11 << " " << a*.18 << "\n" <<endl;
}