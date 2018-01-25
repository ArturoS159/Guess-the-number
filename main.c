#include "podstawa.h"
int main() {
	int stop=0;
	while(stop!=1){
		int polecenie=wczytaj_menu();
		if(polecenie==1){
			start();
			gra_start();
		}else if(polecenie==2){
			wypisz_ranking();
		}else if(polecenie==3){
			reguly();
		}else if(polecenie==4){
			return 0;
		}else{
			printf("Nieznany znak !\nProsze wprowadz prawidlowy znak.");
			sleep(2);
		}
	}
	
	return 0;
}
