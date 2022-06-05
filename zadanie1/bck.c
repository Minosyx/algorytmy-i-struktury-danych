#include <stdio.h>
#include "lib.c"

void printOptions(){
	printf("Nastepna operacja:\n");
	printf("1 - dodaj element na poczatku listy\n");
	printf("2 - dodaj element na koncu listy\n");
	printf("3 - usun pierwszy element listy\n");
	printf("4 - usun ostatni element listy\n");
	printf("5 - odszukaj zadany element\n");
	printf("6 - dodaj nowy element przed lub za wskazanym\n");
	printf("7 - usun wskazany element\n");
	printf("8 - wczytaj zawartosc listy z pliku\n");
	printf("9 - zapisz zawartosc listy do pliku\n");
	printf("10 - wyswietl zawartosc listy\n");
	printf("0 - zakoncz dzialanie programu\n");
	printf("Twoj wybor: ");
}


int main()
{
	wel lista = 0, *element = 0, *c6El = 0;
	wel prev = 0;
	int choice = 0, x = 0, bool = 1;
	int c6 = 0, c6a = 0;
	while(bool){
		printOptions();
		scanf("%d", &choice);
		switch(choice){
			case 1:
				clear_screen();
				printf("	Podaj wartosc do dodania: ");
				scanf("%d", &x);
				addStart(&lista, x);
				clear_screen();
				break;
			case 2:
				clear_screen();
				printf("	Podaj wartosc do dodania: ");
				scanf("%d", &x);
				addEnd(&lista, x);
				clear_screen();
				break;
			case 3:
				remStart(&lista);
				clear_screen();
				break;
			case 4:
				remEnd(&lista);
				clear_screen();
				break;
			case 5:
				clear_screen();
				printf("	Podaj szukana wartosc: ");
				scanf("%d", &x);
				element = findEl(&lista, &prev, x);
				if(*element == NULL){
					printf("	Brak podanego elementu na liscie\n");
					break;
				}
				printf("	Adres szukanej wartosci [%d] to: %p\n", (*element)->x, element);
				break;
			case 6:
				clear_screen();
				printf("	Podaj wartosc do wstawienia: ");
				scanf("%d", &x);
				printf("	Podaj wartosc elementu, ktorego szukasz: ");
				scanf("%d", &c6);
				printf("	Gdzie wstawic nowy element\n	1. Przed podanym\n	2. Po podanym\n");
				printf("	Twoj wybor: ");
				scanf("%d", &c6a);
				element = findEl(&lista, &prev, c6);
				if(c6a == 1)	addBefore(element, x);
				else if(c6a == 2)	addAfter(element, x);
				else("	Bledny wybor!\n");
				clear_screen();
				break;
			case 7:
				clear_screen();
				printf("	Podaj wartosc elementu do usuniecia: ");
				scanf("%d", &x);
				findEl(&lista, &prev, x);
				remEl(&lista, &prev);
				clear_screen();
				break;
			case 8:
				readFile(&lista);
				clear_screen();
				break;
			case 9:
				writeFile(lista);
				clear_screen();
				break;
			case 10:
				clear_screen();
				printf("Wybierz sposob wyswietlenia listy:\n	1. Do przodu\n	2. Do tylu\n");
				printf("Twoj wybor: ");
				scanf("%d", &x);
				if(x == 1) showList(lista);
				else if(x == 2) {
					rShowList(lista);
					printf("\n");
				}
				break;
			case 0:
				bool = 0;
				break;
			default:
				printf("Podano zly wybor!\n");
		}
	}
}
