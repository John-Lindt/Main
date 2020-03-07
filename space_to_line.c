#include <stdio.h>
int main() {
char next;
printf("Begin entering inputs:\n");
while(next!='.') {
//get next character
next=getchar();
if(next=='.');
else {
putchar(next == ' ' ? '\n' : next);
}
}
putchar('\n');
return 0;
}