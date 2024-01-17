//Pawe³ Harmata EIT 3 Projekt JPO 
//Kalkulator dla Elektroników/Informatyków
#pragma once

//Dodanie bibliotek 
#include <iostream>

//Utworzenie klasy odpowiedzialnej za konwersje systemu z dziesiêtnego na binarny
//oraz na z binarnego na dziesiêtny
class kalkulator_bin
{
public:

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera BIN do DEC
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int bin_num - liczba BIN która chcemy konwertowaæ
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	int bin_dec(int bin_num) {

		//Stworzenie zmiennych 
		int result = 0, x10 = 0, value{};

		//G³owna pêtla odpowiadaj¹ca za konwersjê
		while (bin_num != 0) {

			//value przyjmuje modulo z wartoœci wejœciowej z przez co odzytujemy bity po kolei
			value = bin_num % 10;

			//Zabezpieczenie przed z³ymi znakami
			if (value != 0 && value != 1) {
				std::cerr << "Error:B³êdna liczba binarna ." << std::endl;
				return -3; 
			}

			//Zmniejszamy wartoœæ wejœciow¹ i dodajemy do wyniku kolejne potegi 2
			bin_num = bin_num / 10;
			result += value * std::pow(2, x10);
			x10++;

		}

		//Zwrócenenie wyniku
		return result;
	}

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera DEC do BIN
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int dec_num - liczba DEC która chcemy konwertowaæ
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     long long int result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	long long int dec_bin( int dec_num) {

		//Zabezpieczenie przed ujemnymi waroœciami
		if (dec_num < 0) {

			std::cerr << "Error: Liczba nie mo¿e byæ ujemna." << std::endl;
			return -2;

		}

		//Zwraca zero dla zera
		if (dec_num == 0) {

			return 0;

		}

		//Utworzenie zmiennych
		long long int result = 0, x10 =1, buff{};
		x10 = 1;

		while (dec_num != 0) {

			//Stworzenie int value przyjmuj¹c¹ wartoœæ modulo z wartoœci wejœciowej i dodanie wyniku(0 lub 1) oraz pomno¿enie przez potege 10(pozycja bitu)
			buff = dec_num % 2;
			result += buff * x10;
            x10 *= 10;

			//Podzielenie wartoœci wejœciowej przez 2
			dec_num /= 2;

		}

		//Zwrócenenie wyniku
		return result;

	}
};

