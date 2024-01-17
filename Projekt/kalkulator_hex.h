//Pawe� Harmata EIT 3 Projekt JPO 
//Kalkulator dla Elektronik�w/Informatyk�w
#pragma once

//Dodanie bibliotek 
#include <iostream>
#include <algorithm>

using std::string,std::reverse;

//Utworzenie klasy odpowiedzialnej za konwersje systemu z dziesi�tnego na heksadecymalny
//oraz na z heksadecymalnego na dziesi�tny
class kalkulator_hex
{
public:

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera HEX do DEC
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     string hex_num - liczba HEX kt�ra chcemy konwertowa�
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	int hex_dec(string hex_num) {

		//Stworzenie zmiennych 
		int length = hex_num.size();
		int x10 = 1;
		int result{};

		//G�owna p�tla odpowiadaj�ca za konwersj�
		//Inspirowana https://www.geeksforgeeks.org/program-for-hexadecimal-to-decimal/
		for (int i = length - 1; i >= 0; i--) {
			char cChar = hex_num[i];

			if ((cChar >= '0' && cChar <= '9') ||
				(cChar >= 'A' && cChar <= 'F') ||
				(cChar >= 'a' && cChar <= 'f')) {

				//Utworzenie zmienej kt�ra b�dzie przyjmowa� warto�� znaku
				int dValue;
				if (cChar >= '0' && cChar <= '9') {
					//Wykorzystanie Kodu ASCII do odczytania warto�� z chara cyfry od 0 do 9
					dValue = cChar - '0';
				}
				else if (cChar >= 'A' && cChar <= 'F') {
					//Wykorzystanie Kodu ASCII do odczytania warto�� z chara du�e litery
					dValue = cChar - 'A' + 10;
				}
				else {
					//Wykorzystanie Kodu ASCII do odczytania warto�� z chara ma�e litery
					dValue = cChar - 'a' + 10;
				}

				//Pomno�enie warto�ci znaku przez pozycje w kt�rej si� znajduje
				result += dValue * x10;
				x10 *= 16;
			}

			//Zabezpieczenie przed podaniem z�ego znaku
			else {
				
				std::cerr << "Error:To nie jest liczba hex '" << cChar << "'" << std::endl;
				return -3; 
			}
		}
		//Zwr�cenenie wyniku
		return result;
	}

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera DEC do HEX
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int dec_num - liczba DEC kt�ra chcemy konwertowa�
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     string result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	string dec_hex(int dec_num) {

		//Zabezpieczenie przed ujemnymi waro�ciami
		if (dec_num < 0) {
			std::cerr << "Error: Liczba nie mo�e by� ujemna." << std::endl;
			return "-2";  
		}

		string result;

		while (dec_num != 0) {

			//Stworzenie int value przyjmuj�c� warto�� modulo z warto�ci wej�ciowej
			int value = dec_num % 16;
			if (value < 10) {

				//wykorzystanie kodu ASCII do przekszta�cenia int w char 0 w kodzie ASCII to 48 , 1 to 49 itd
				result.push_back(char(value + 48));

			}

			else {

				//wykorzystanie kodu ASCII do przekszta�cenia int w char A w kodzie ASCII to 55 , B to 56 itd
				result.push_back(char(value + 55));

			}

			//Podzielenie warto�ci wej�ciowej przez 16
			dec_num /= 16;

		}
		//Odwr�cenie kolejno�ci stringa i zwr�cenie wyniku
		reverse(result.begin(), result.end());
		return result;

	}
};

