#include "podstawa.h"

void wypisz_srodek(char *s){
	printf("---%*s%*s---\n",((SZER/2)-3)+strlen(s)/2,s,((SZER/2)-3)-strlen(s)/2,"");
}

void reguly(){
	char bufor[20];
	system("cls");
	printf("Gra losuje liczbe z przedzialu twoim zadaniem jest zgadnac ta liczbe.\nStaraj sie zdobyc jak najwiecej punktow.\n\nGra zostala zrobiona przez Artur Kowalski\n");
	gets(bufor);
}//Wypisanie zasad

int wczytaj_menu(){
	char buf[32];
	sprintf(buf, "mode %d,%d",SZER,WYS);
	system(buf);
	int znak;
	system("cls");
	wypisz_srodek(":::MENU:::");
	wypisz_srodek("1. Rozpocznij gre.");
	wypisz_srodek("2. Ranking.");
	wypisz_srodek("3. Zasady.");
	wypisz_srodek("4. Wyjscie.");
	scanf("%d",&znak);
	fflush(stdin);
	
	return znak;
}//Wypisywanie menu
