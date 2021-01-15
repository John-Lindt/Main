#include <stdio.h>
#include <stdlib.h>
int main() {
/*Stab, a game where you can stab, defend, or heal
**player and computer are two arrays
**once hp (youHp or oppHp reaches 0, winner is declared
**game continues until user exits*/
/*Variable for attack type and loop break check,rand var for opponent attack type*/
int eInt=1,aType;
time_t t;
srand((unsigned) time(&t));
while(eInt!=0) {
	/*creating and initializing health, starts at 5*/
	int youHp=5, oppHp=5;
	printf("Welcome to Stab! You and your opponent start with 5 health and fight until one of your health reaches 0./n
	Enter 1 to stab (dealing 1 damage), 2 to block (protecting from attack), or 3 to heal (restore 1 health).");
	scanf(%i,exitInt);
	printf("Enter 1 to continue, 0 to quit.");
	scanf("%i",&eInt);
	aType=(rand()%3);
	while(youHp>5 && oppHp>5) {
	if(aType=0) {
		/*computer attempts to stab*/
		if(eInt=2) {
			printf("Opponent attack blocked!");
		}
		else {
			youHp=youHp-1;
			printf("You've been stabbed! %i health remaing.",%youHp);
		}
	}
	else if(aType=1) {
		if(eInt=1) {
			printf("Opponent blocks your attack!");
		}
	}
	else {
		if(oppHp>3) {
			/*computer attempts to stab*/
			if(eInt=2) {
			printf("Opponent attack blocked!");
			}
			else {
			youHp=youHp-1;
			printf("You've been stabbed! %i health remaing.",%youHp);
			}
		}
		else {
			oppHp=oppHp+1;
			printf("Opponent heals to %i hp.",&oppHp);
		}
	}}
	if(youHp>0 && oppHp=0) {
		printf("You win!");
	}
	else if(youHp=0 && oppHp>0) {
		printf("Opponent win.");
	}
}
return 0;
}