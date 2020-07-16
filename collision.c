#include <stdlib.h>
#include <stdio.h>
static int size=0;	//grid size
int rand(int a, int b);
int[][] mkgrid();
int[] move(int x, int y);
int main() {
int ct=0, grid[][], rem=10;	//number of movements, grid, remaining points
printf("Enter grid size: ");
scanf("%i",&size);
printf("Generating %i by %i grid with 10 points.\n");
grid=mkgrid();
while(rem>1) {
	ct++;
	int i,j=rem;	//incrementor and iterator
	for(i=0,i<9,i++) {
	for(j=rem,j>i;j--) {
		if(grid[i][0]=grid[j][0] && grid[i][1]=grid[j][1] && grid[i]!=-1) {
			rem-=2;	//points destroy each other
			grid[i][0]=-1;
			grid[j][0]=-1;
			printf("Strike at %i , %i. %i points remaining.",&grid[i][0],&grid[j][0],&rem);
		}
		else {
			j--;
		}
	}}	//continues if there are remaining points
}
printf("Reduced to no points in %i iterations",&ct);
return 0;
}

//function accepts number range and returns ret between range
int rand(int a, int b) {
	int ret;
	ret=(rand()%(b-a+1))+a;
	return ret;
}

//function generates grid array of 10 points
int[][] mkgrid() {
	int i,j, ret[10][2];
	for(i=0;i<size;i++;) {
		for(j=0;j<2;j++) {
			ret[i,j]=rand(0,size);
		}
	return ret;	
}

//function moves a point around the grid
//accepts current coordinates and moves them
int[] move(int x, int y) {
	int ret[]={x,y};
	//generate new positions
	ret[0]=rand((x-2),(x+2));
	ret[1]=rand((y-2),(x+2));
	//make sure points don't go off grid
	if(ret[0]<0) {
		ret[0]=0;
	}
	if(ret[1]<0) {
		ret[1]=0;
	}
	if(ret[0]>size) {
		ret[0]=size;
	}
	if(ret[1]>size) {
		ret[1]=size;
	}
	return ret;
}