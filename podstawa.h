/////Podstawowe biblioteki
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>

#define SZER 100 //Szerokosc konsoli
#define WYS 50 //Wysokosc konsoli
#define ZYCIE 10 //Zycie 
#define ZAKRESP 10 //Od jakiej liczby ma sie zaczynac zakres
#define ZAKRESZWIEKSZ 5 //O ile zwiekszamy zakres liczb
#define LRANK 10
/////////////////////////
int wczytaj_menu();
void wypisz_srodek(char *s),reguly(),start(),gra_start(),nastepny_poziom(),fail(),koniec(),wypisz_ranking(),wpisz_do_ranking(),sortowanie();
long int los(int zakres);

struct gra_struct{
	long int liczba_los;
	long int liczba;
	long int zakres;
}gra;

struct gracz_struct{
	long int pkt_gracza;
	long int pkt_zdobycie;
	int zycie;
	int od_zakres;
	int do_zakres;
	char imie[50];
}gracz;

struct ranking_struct{
	char buforek[30];
	int wynik[LRANK+1];
	char gracz_str[30][LRANK+1];
	int w;
	int g;
	int n;
}ranking;

FILE *plik;	

