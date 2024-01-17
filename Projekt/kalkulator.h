//Pawe� Harmata EIT 3 Projekt JPO 
//Kalkulator dla Elektronik�w/Informatyk�w

#pragma once

//Dodanie bibliotek 
#include <iostream>
#include "kalkulator_octa.h"
#include "kalkulator_bin.h"
#include "kalkulator_hex.h"

using std::cout,std::endl,std::cin;

class kalkulator{

private:

	//incjalizacja klas
	kalkulator_octa kalc_oct;
	kalkulator_bin kalc_bin;
	kalkulator_hex kalc_hex;

public:
	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji dzielenia kt�ra wyrzuca b�ad(-100) przy dzieleniu przez 0
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int value1 - licznik
	//	   int value2 - mianownik
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int zwraca wynik dzielenia
	///////////////////////////////////////////////////////////////////////////
	int dzielenie(int value1, int value2) {

		if (value2 == 0) {

			cout << "Nie mo�na dzieli� przez zero" << endl;
			return -100;

		}

		return value1 / value2;

	}

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji silnii
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int value - warto�� kt�ra wej�ciowa silnii
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int zwraca wynik silni
	///////////////////////////////////////////////////////////////////////////
	long long int silnia(int value) {

		if (value == 1 || value == 0) {
			
			return 1;

		}

		else {

			return value * silnia(value - 1);

		}
	}

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji pot�gi 
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int value1 - podstawa pot�gi
	//	   float x10 - wyk�adnik
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     double  zwraca wynik pot�gi
	///////////////////////////////////////////////////////////////////////////
	double pot�ga(float value1, float x10) {

		double result = 1;

		if (x10 < 0) {

			value1 = 1 / value1;
			x10 = -x10;

		}

		for (int i =0; i< x10; i++){
		
			result *= value1;

		}

		return result;
		
	}

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji pierwiastka
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int value1 - liczba
	//	   int x10 - stopie�
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     double zwraca wynik pierwiastkowania
	///////////////////////////////////////////////////////////////////////////
	double pierwiastek(int value1, int x10) {

		if (x10 == 0) {

			cout << "Stopie� nie mo�e by� r�wny zero";
			return std::nan("");

		}
		if (value1 < 0 && x10 % 2 == 0) {

			cout << "Dla stopnia parzystego warto�� musi by� dodatnia";
			return std::nan("");

		}

		return std::pow(value1, 1 / static_cast<double>(x10));
	}

	///////////////////////////////////////////////////////////////////////////
	//Funckja pozwalaj�ca bezpiecznie pobra� int
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int specOpt - Opcja definiuj�ca dzia�anie programu
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int zwraca wpisanego inta
	///////////////////////////////////////////////////////////////////////////
	int	getInt(int specOpt) {

		if (specOpt == 1) {

			while (true) {

				cout << "Podaj pierwsz� liczb�: ";
				int value{};
				cin >> value;

				if (!cin) {
					//Inspirowane https://forum.pasja-informatyki.pl/183036/jak-zrobic-aby-nie-wczytywano-liter
					cin.clear();
					cout << "B�edna warto��! Spr�buj jescze raz" << endl;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
				else {

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return value;

				}
			}
		}

		if (specOpt == 2) {

			while (true) {

				cout << "Wybierz opcj�!: ";
				int value{};
				cin >> value;

				if (!cin) {

					cin.clear();
					cout << "B�edna warto��! Spr�buj jescze raz" << endl;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
				else {

					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return value;

				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////
	//Funckja pozwalaj�ca bezpiecznie pobra� floata
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     float zwraca wpisanego floata
	///////////////////////////////////////////////////////////////////////////
	float	getFloat() {

		while (true) {

			cout << "Podaj pierwsz� liczb�: ";
			float value{};
			cin >> value;

			if (!cin) {

				cin.clear();
				cout << "B�edna warto��! Spr�buj jescze raz" << endl;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			else {

				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;

			}
		}
	}

	///////////////////////////////////////////////////////////////////////////
	//Funckja pozwalaj�ca bezpiecznie pobra� chara
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     char zwraca wpisanego chara
	///////////////////////////////////////////////////////////////////////////
	char	getChar() {

		while (true) {

			cout << "Podaj operator (+,-,*,/,!,^,P(pierwiastek): ";
			char value{};
			cin >> value;

			if (!cin) {

				cin.clear();
				cout << "B�edna warto��! Spr�buj jescze raz";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			else {

				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;

			}
		}

	}

	///////////////////////////////////////////////////////////////////////////
	//G��wna funkcja ob��uguj�ca kalkulator
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//	 int opt - opcje definiuj�ce dzia�anie programu
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//   Wy�wietla wynik przeprowadzonych operacji matematycznych
	///////////////////////////////////////////////////////////////////////////
	void r�wnanie(int opt) {

		//zainiocjowanie zmiennych (Po dwie zmienne wej�ciowe dla int float oraz string i dla ka�dego typu zmienna wyj�ciowa oraz zmienna 
		//odpowiadaj�ca za dzia�anie algebraiczne) 
		int valuei1{}, valuei2{};
		float valuef1{}, valuef2{};
		char operator1{};
		string values1{}, values2{};
		int result{};
		float resultf{};
		string resulthex{};

		//Opcja dla systemu szesnatkowego(wykorzystuje string)
		if (opt == 5) {

			cout << "Podaj pierwsz� hex liczb�: ";
			cin >> values1;
			operator1 = getChar();

		}

		//Opcja dla liczb zmiennoprzecinkowych (wykorzystuje float)
		else if(opt == 2){

			valuef1 = getFloat();
			operator1 = getChar();

		}

		//Opcja dla pozosta�ych system�w
		else {

			valuei1 = getInt(1);
			operator1 = getChar();

		}

		//Przekszta�cenie system�w na int dla przeprowadzenia dzia�a� algebraicznych 
		switch (opt) {

		case 3:

			valuei1 = kalc_bin.bin_dec(valuei1);
			break;

		case 4:

			valuei1 = kalc_oct.oct_dec(valuei1);
			break;

		case 5:

			valuei1 = kalc_hex.hex_dec(values1);
			break;

		}

		if (operator1 == '+' || operator1 == '-' || operator1 == '/' || operator1 == '*' || operator1 == '^' || operator1 == 'P') {

			//Opcja dla systemu szesnatkowego(wykorzystuje string)
			if (opt == 5) {

				cout << "Podaj drug� liczb�: ";
				cin >> values2;

			}

			//Opcja dla liczb zmiennoprzecinkowych (wykorzystuje float)
			else if (opt == 2) {

				valuef2 = getFloat();

			}

			//Opcja dla pozosta�ych system�w
			else {

				valuei2=getInt(1);

			}

			//Przekszta�cenie system�w na int dla przeprowadzenia dzia�a� algebraicznych 
			switch (opt) {

			case 3:

				valuei2 = kalc_bin.bin_dec(valuei2);
				break;

			case 4:

				valuei2 = kalc_oct.oct_dec(valuei2);
				break;

			case 5:

				valuei2 = kalc_hex.hex_dec(values2);
				break;
			

			}

			//Wykonanie dzi�a� algebraicznych w zale�no�ci od operatora
			switch (operator1) {

			case '+':

				if (opt == 2) {

					resultf = valuef1 + valuef2;
					break;

				}

				else {

					result = valuei1 + valuei2;
					break;

				}
			case '-':

				if (opt == 2) {

					resultf = valuef1 - valuef2;
					break;

				}

				else {

					result = valuei1 - valuei2;
					break;

				}
				

			case '/':

				if (opt == 2) {

					resultf = dzielenie(valuef1, valuef2);
					break;

				}

				else {

					result = dzielenie(valuei1, valuei2);
					break;

				}

			case '*':

				if (opt == 2) {

					resultf = valuef1 * valuef2;
					break;

				}

				else {

					result = valuei1 * valuei2;
					break;

				}

			case '^':

				if (opt == 2) {

					resultf = pot�ga(valuef1, valuef2);
					break;

				}

				else {

					result = pot�ga(valuei1, valuei2);
					break;

				}
				

			case 'P':

				if (opt == 2) {

					resultf = pierwiastek(valuef1, valuef2);
					break;

				}

				else {

					result = pierwiastek(valuei1, valuei2);
					break;

				}

				

			}
		}

		else if (operator1 == '!' ) {

			if (opt == 2) {

				string answer{};
				cout << "�eby silnia dzia�a�a poprawnie potrzebuje liczby ca�kowitej! Czy chcesz kontynuowa�(TAK/NIE)";
				cin >> answer;

				if (answer == "TAK") {

					result = silnia(valuei1);

				}
				else {

					cout << "Error 999";
					return;

				}
			}

			result = silnia(valuei1);

		}

		//Wyj�tek dla b��dnego operatora
		else {

			cout << "Bledny operator" << endl;
			return;

		}

		//Przekszta�cenie wyniku int na oczekiwany system
		switch (opt) {

		case 3:

			result = kalc_bin.dec_bin(result);
			break;

		case 4:

			result = kalc_oct.dec_oct(result);
			break;

		case 5:

			resulthex = kalc_hex.dec_hex(result);
			break;

		}

		//Wypianie wyniku
		if (opt == 5) {

			cout << "Tw�j wynik to:  " << resulthex << endl << endl;

		}
		else if (opt == 2) {

			cout << "Tw�j wynik to:  " << resultf << endl << endl;

		}
		else {

			cout << "Tw�j wynik to:  " << result << endl << endl;

		}
	}



};

