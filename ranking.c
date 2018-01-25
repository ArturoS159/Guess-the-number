#include "podstawa.h"
void kopiowanie(char *src,char *dst){
	while(*dst++=*src++);
}
void struktura_aktualizacja(){
	plik = fopen("ranking.txt","r");
	ranking.w=0;
	ranking.g=0;
	ranking.n=0;
	if(plik==NULL){
		printf("Ranking jest pusty. Zagraj najpierw.\n");
		ranking.n=100;
	}else{
		while (fscanf(plik, "%s",ranking.buforek)!=EOF){
			if(ranking.n%2==0){
				kopiowanie(ranking.buforek,ranking.gracz_str[ranking.g]);
				ranking.g++;
			}else{
				ranking.wynik[ranking.w]=atoi(ranking.buforek);;
				ranking.w++;
			}
			ranking.n++;
		}
	}
	fclose(plik);
	sortowanie();
}
void wypisz_ranking(){
	struktura_aktualizacja();
	if(ranking.n==100);else{
		system("cls");
		printf("Ranking: \n");	
		for(int i=0;(i<ranking.w)&&(i<LRANK);i++){
			printf("%d. %s wynik: %d\n",i+1,ranking.gracz_str[i],ranking.wynik[i]);
		}
	}
	gets(ranking.buforek);
}

void wpisz_do_ranking(){
	if(gracz.pkt_gracza!=0){
		plik = fopen("ranking.txt","a+");
		fprintf(plik,"%s\n%d\n",gracz.imie,gracz.pkt_gracza);
		fclose(plik);
	}
}

void update_ranking(){
	plik = fopen("ranking.txt","w");
	fprintf(plik,"");
	fclose(plik);
	plik = fopen("ranking.txt","a+");
	for(int i=0;i<LRANK;i++)
		fprintf(plik,"%s\n%d\n",ranking.gracz_str[i],ranking.wynik[i]);
	fclose(plik);
}
void sortowanie(){
	int tmp;
	for(int y=0;y<ranking.w-1;y++){
		for(int x=0;x<ranking.w-y-1;x++){
				if(ranking.wynik[x+1]==1)break;
				if(ranking.wynik[x]<ranking.wynik[x+1]){
					kopiowanie(ranking.gracz_str[x],ranking.buforek);
					tmp=ranking.wynik[x];
					//////
					ranking.wynik[x]=ranking.wynik[x+1];
					kopiowanie(ranking.gracz_str[x+1],ranking.gracz_str[x]);
					//////
					ranking.wynik[x+1]=tmp;
					kopiowanie(ranking.buforek,ranking.gracz_str[x+1]);
				}
		}
	}
	if(ranking.w>LRANK)
			update_ranking();
}


