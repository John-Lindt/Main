#include <stdio.h>
#include <string>
int rando=1;	//change each time
//making nation structs
struct nation {
//country name
std::string name="nul";
/*morale: morale of nation, compared when attacking, morale below -5=surrender
**loc: location in array for viable attack targets
**pop: population of country, increases 10% every turn
**alive: if country is still standing*/
int morale=0, loc=-1, pop=0, alive=1;
int canAttack[]={0,0,0,0,0,0};
};
//program allows user to see simulation of nations in conflict
int main(void) {
/*create nations:
**westCoast: connected to northwest and southwest 1
**northwest: connected to midwest, westCoast, eastCoast 2
**southwest: connected to westCoast, midwest, south 3
**midwest: connected to northwest, southwest, south, eastCoast 4
**south: connected to eastCoast, midwest, southwest 5
**eastCoast: connected to south, midwest, northwest 6*/
struct nation narr[6];
//name and connect nations
narr[0].name="West Coast";
narr[1].name="Northwest";
narr[2].name="Southwest";
narr[3].name="Midwest";
narr[4].name="South";
narr[5].name="East Coast";
narr[0].canAttack={0,1,1,0,0,0};
narr[1].canAttack={0,1,0,1,1,0};
narr[2].canAttack={1,0,0,1,1,0};
narr[3].canAttack={0,1,1,0,1,1};
narr[4].canAttack={0,0,1,1,0,1};
narr[5].canAttack={0,1,0,1,1,0};
//starting populations
narr[0].pop=48;
narr[1].pop=14;
narr[2].pop=15;
narr[3].pop=65;
narr[4].pop=114;
narr[5].pop=118;
printf("Welcome to John's battle simulator!\nEnter to start, 0 to exit.");
int cont=1,rem=6;
//main fight
scanf("%i",&cont);
while(cont!=0) {
	rando=rando*7;
	for(int i=0,i<6;i++) {
		for(int j=0;j<6;j++) {
			//attack successful with morale advantage
			if(rando%2=0 && (narr[i].morale-narr[j].morale>=0)
			&& narr[i].canAttack[j]=1) {
				rando=rando/3;
				//decrease loser pop by 20%
				narr[j].pop=narr[j].pop-narr[j].pop*.2;
				narr[j].morale=narr[j].morale-2;
				narr[i].morale++;
				if(narr[j].pop<1 || narr[j].morale<5) {
					//country conquered
					narr[j].alive=0;
					narr[i].canAttack[j]=0;
					narr[j].canAttack[i]=0;
					narr[i].morale++;
					rem--;
					j=20;
					printf("%s defeated %s!",narr[i].name,narr[j].name);
				}
			}
			//attack successful with morale disadvantage
			else if(narr[i].morale-narr[j].morale<0 && rand%2=0
			&& rando%3=0 && narr[i].canAttack[j]=1) {
				rando=rando*4;
				//decrease loser pop by 20%
				narr[j].pop=narr[j].pop-narr[j].pop*.2;
				narr[j].morale--;
				narr[i].morale++;
				if(narr[j].pop<1 || narr[j].morale<-4) {
					//country conquered
					narr[j].alive=0;
					narr[i].canAttack[j]=0;
					narr[j].canAttack[i]=0;
					narr[i].morale++;
					rem--;
					j=20;
					narr[j].pop=narr[i].pop/2;
					printf("%s defeated %s!",narr[i].name,narr[j].name);
				}
			}
			rando=rando+2;
			//attack failed
			else {
				//decrease pop by 15%
				narr[i].pop=narr[i].pop-narr[i].pop*.15;
				rando*2;
			}
			rando=rando/5;
		}
	}
	//fights done, disp results
	printf("Results:\n");
	for(int i=0,i<6,i++) {
		if(narr[i].alive=1) {
			rando=rando*7;
			printf("%s remaining population: %i\n",
			&narr[i].name,&narr[i].pop);
		}
		//increase pop by 10%
		narr[i].pop=narr[i].pop*1.1
	}
	rand=rand/6;
	printf("Continue?");
	scanf("%i",&cont);
	if(rem=1) {
		cont=0;
	}
}
if(westCoast.alive=1) {
	printf("West Coast survives.\n");
	cont++;
}
if(northwest.alive=1) {
	printf("Northwest survives.\n");
	cont++;
}
if(southwest.alive=1) {
	printf("Southwest survives.\n");
	cont++;
}
if(midwest.alive=1) {
	printf("Midwest survives.\n");
	cont++;
}
if(south.alive=1) {
	printf("South survives.\n");
	cont++;
}
if(eastCoast.alive=1) {
	printf("East Coast survives.\n");
	cont++;
}
if(cont=1) {
	printf("We have a winner!");
}
return 0;
}