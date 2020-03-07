#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]) {

/*CS306 Assignment 2.1:
*Program accepts string from command line and converts letters to
*uppercase or lowercase based on the case of the first letter*/

//input validation: make sure string has been input
if(argc!=2) {
printf("Invalid input.");
return -1;
}
int i=0,gt=0,lt=0,mod,len;
for(len=0;argv[1][len]!='\0';len++);
char *ret=(char*)malloc(i*sizeof(char));	//create array of proper length
if(ret==NULL) {
	printf("Memory not allocated.");
	exit(0);
}
//convert to uppercase or lowercase
while((i!=-1) && (i<len)) {
	if(argv[1][i]>64 && argv[1][i]<93) {
		gt=64;
		lt=93;
		mod=32;
		i=-1;
	}
	else if(argv[1][i]>96 && argv[1][i]<125) {
		gt=96;
		lt=125;
		mod=-32;
		i=-1;
	}
	i++;
}
i=0;	//reset incrementer
if(gt=0) {
	//string has no characters, don't modify
}
else {
	while(i<len) {
		if(argv[1][i]>gt && argv[1][i]<lt) {	//char is gt/lt, change case
			ret[i]=argv[1][i]+mod;
		}
		else {	//not a character, don't modify
			ret[i]=argv[1][i];
		}
		i++;
	}
}
printf("Modified string: %s.",ret);
free(ret);
return 0;
}