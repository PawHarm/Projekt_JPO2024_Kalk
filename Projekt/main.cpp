//Paweł Harmata EIT 3 Projekt JPO 
//Kalkulator dla Elektroników/Informatyków

//Dodanie bibliotek 
#include <iostream>
#include "kalkulator.h"
#include "kalkulator_octa.h"
#include <locale.h>


using std::cin, std::cout, std::cin, std::endl;


int main()
{

	//incjalizacja klas
	kalkulator kalk;
	kalkulator_octa kalk_oct;
	kalkulator_hex kalk_hex;
	kalkulator_bin kalk_bin;

	//Ustawienie polskich znaków
	setlocale(LC_ALL, "polish");

	//Wypisanie interfejsu tekstowego
	cout << "Witaj w kalkulatorze dla elektroników i informatyków" << endl;

	while (true) {

		
		//Wypisanie głównego menu
		cout << endl<<"Wybierz opcje: " << endl
			 << "1.Konwersja na inne systemy" << endl
		     << "2.Kalkulator float" << endl 
			 << "3.Kalkulator binarny" << endl
		     << "4.Kalkulator oktalny" << endl 
			 << "5.Kalkulator hexadecymalny" << endl
		     << "6.Wyjdź" << endl;

		//Utworzenie i pobranie zmiennej odpowiedniej za wybór opcji
		int option1{};
		option1 = kalk.getInt(2);

		//Kod odpowiadający za wybór konwersji
		if (option1 == 1) {

			//Wypisanie menu konwersji
			cout << "Konwersje: " << endl 
				<< "1.Dec do Oct" << endl 
				<< "2.Oct do Dec" << endl
				<< "3.Dec do Bin" << endl 
				<< "4.Bin do Dec" << endl 
				<< "5.Dec do Hex" << endl 
				<< "6.Hex do Dec" << endl;

			//Utworzenie i pobranie zmiennej odpowiedniej za wybór opcji
			int option2{}, value{};
			option2 = kalk.getInt(2);

			
			//Wywołanie konwersji dla wybranego systemu
			if (option2 == 1) {
				
				cout << "Podaj liczbe do konwersji: ";
				cin >> value;
				cout<<kalk_oct.dec_oct(value);

			}

			if (option2 == 2) {

				cout << "Podaj liczbe do konwersji: ";
				cin >> value;
				cout<<kalk_oct.oct_dec(value);

			}
			if (option2 == 3) {

				cout << "Podaj liczbe do konwersji: ";
				cin >> value;
				cout << kalk_bin.dec_bin(value);

			}

			if (option2 == 4) {

				cout << "Podaj liczbe do konwersji: ";
				cin >> value;
				cout << kalk_bin.bin_dec(value);

			}
			if (option2 == 5) {

				cout << "Podaj liczbe do konwersji: ";
				cin >> value;
				cout << kalk_hex.dec_hex(value);

			}

			if (option2 == 6) {

				string valuehex{};
				cout << "Podaj liczbe do konwersji: ";
				cin >> valuehex;
				cout << kalk_hex.hex_dec(valuehex);

			}
		}
		//Wybór systemu używanego do działań algebraicznych
		if (option1 == 2) {

			kalk.równanie(2);
			
		}

		if (option1 == 3) {

			kalk.równanie(3);

		}

		if (option1 == 4) {

			kalk.równanie(4);

		}
		if (option1 ==5) {

			kalk.równanie(5);

		}

		//Opcja wyjścia z programu
		if (option1 == 6) {

			cout << endl << "Dowidzenia!" << endl;
			break;


		}

	}
}
