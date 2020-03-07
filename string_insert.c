#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]) {
if(argc!=4) {	//incorrect number of inputs
	printf("Invalid input.");
	return -1;
}
int len1,len2,loc,i,j;	//string lengths, concat position,incrementors
loc=atoi(argv[2]);
for(len1=0;len1!='\0';len1++);	//get string lengths
for(len2=0;len2!='\0';len2++);
if((loc+1)>len1) {	//index is out of bounds
	printf("Index out of bounds.");
	return -2;
}
char *cat=(char*)malloc((len1+len2+1)*sizeof(char));	//create concat array of length len1+len2+esc char
//generate string
for(i=0;i<(len1+len2);i++) {
	if(i=loc) {
		for(j=0;j<len2;j++) {
			cat[i]=argv[3][j];
			i++;	//move outer loop forward to after middle string
		}
	}
	else {
		cat[i]=argv[1][i];	//add chars from first loop
	}
}
cat[len1+len2]='\0';	//end string with escape character
printf("%s",cat);
return 0;
}