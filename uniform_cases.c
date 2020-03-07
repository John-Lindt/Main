#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_list(char ** data);
int main(int argc, char* argv[]) {

/*CS306 Assignment 2.1:
*Program accepts string(s) from command line and converts letters to
*uppercase or lowercase based on the case of the first letter*/
int inc=1;
char ** ret2=(char**)malloc(argv*sizeof(char*));
while(inc<argc) {
//input validation: make sure string has been input
if(argc=1) {
printf("Did not enter string or strings.");
return -1;
}
int i=0,gt=0,lt=0,mod,len;
for(len=0;argv[inc][len]!='\0';len++);
char *ret=(char*)malloc(len*sizeof(char));	//create array of proper length
if(ret==NULL) {
	printf("Memory not allocated.");
	exit(0);
}
//convert to uppercase or lowercase
while((i!=-1) && (i<len)) {
	if(argv[inc][i]>64 && argv[inc][i]<93) {
		gt=64;
		lt=93;
		mod=32;
		i=-1;
	}
	else if(argv[inc][i]>96 && argv[inc][i]<125) {
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
		if(argv[inc][i]>gt && argv[inc][i]<lt) {	//char is gt/lt, change case
			ret[i]=argv[inc][i]+mod;
		}
		else {	//not a character, don't modify
			ret[i]=argv[inc][i];
		}
		i++;
	}
}
ret2[inc]=ret;
inc++;
}
print_list(ret2);
//free sub-arrays
for(i=0;i<argc;i++) {
free(ret2[i]);
}
//free 2d array
free(ret2);
return 0;
}
void print_list(char **data) {
int j,k;
	for(j=0;j<argc;j++) {
	k=0;
	while(argc[j][k]!='\0') {
		printf("%c",argc[j][k]);
		k++;
	}
	printf(" ");
}