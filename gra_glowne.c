#include "podstawa.h"

void start(){
	srand(time(NULL)^clock());
	gra.zakres=ZAKRESP;
	gra.liczba_los=los(gra.zakres);
	gracz.pkt_gracza=0;
	gracz.pkt_zdobycie=10;
	gracz.zycie=ZYCIE;
	gracz.od_zakres=1;
	gracz.do_zakres=gra.zakres;
}//Wczytanie podstawowych statystyk

void gra_start(){
	while(gracz.zycie!=0){
		system("cls");
		printf("Liczba jest w zakresie od %d do %d\n",gracz.od_zakres,gracz.do_zakres);
		printf("Punkty do zdobycia: %d  Twoje pukty: %d  Twoje zycie: %d",gracz.pkt_zdobycie,gracz.pkt_gracza,gracz.zycie);
		printf("\nAby zakonczyc wczesniej wpisz: '0'");
		//printf(" TYMCZASOWE : %d",gra.liczba_los); Pokazywanie wylosowanej liczby
		printf("\nWpisz liczbe: ");
		scanf("%d",&gra.liczba);
		
		if((gra.liczba>=gracz.od_zakres)&&(gra.liczba<=gracz.do_zakres)){
			if(gra.liczba==gra.liczba_los){
				nastepny_poziom();
				printf("Zgadles ! Przechodzisz dalej :)");
				sleep(2);
			}else{
				fail();
				printf("To nie ta liczba.");
				sleep(1);
			}
		}else if(gra.liczba==0){
				gracz.zycie=0;
		}else{
			printf("Prosze wprowadz liczbe z podanego przedzialu !");
			sleep(2);
		}
		fflush(stdin);
	}
	koniec();
}//Glowna petla

long int los(int zakres){
	return (rand()%zakres+1);
}//Losowanie liczby

void nastepny_poziom(){
	gracz.pkt_gracza+=gracz.pkt_zdobycie;
	gra.zakres+=ZAKRESZWIEKSZ;
	gracz.do_zakres=gra.zakres;
	gracz.od_zakres=1;
	gra.liczba_los=los(gra.zakres);
	gracz.pkt_zdobycie=gra.zakres;
	gracz.zycie=ZYCIE;
}//Po zgadnieciu dobrej liczbu 

void fail(){
	gracz.zycie-=1;
	gracz.pkt_zdobycie-=gra.zakres/10;
	if(gra.liczba_los>gra.liczba){
		gracz.od_zakres=gra.liczba+1;
	}else
		gracz.do_zakres=gra.liczba-1;
}//Po zlym zganieciu liczby
int spr_spacja(){
	for(int i=0;gracz.imie[i];i++){
		if(gracz.imie[i]==' ')
			return 1;
	}
	return 0;
}
void koniec(){
	gracz.zycie=0;
	system("cls");
	printf("PRZEGRALES! Nastepnym razem bedzie lepiej :)\nTwoje punkty: %d\nPodaj nick (bez spacji i max 30 znakow): ",gracz.pkt_gracza);
	gets(gracz.imie);
	while(spr_spacja()){
		printf("\nProsze wpisac bez spacji!\n");
		gets(gracz.imie);
	}
	wpisz_do_ranking();
}

