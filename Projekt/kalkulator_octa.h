//Pawe³ Harmata EIT 3 Projekt JPO 
//Kalkulator dla Elektroników/Informatyków
#pragma once

//Dodanie bibliotek 
#include <iostream>

//Utworzenie klasy odpowiedzialnej za konwersje systemu z dziesiêtnego na oktalny
//oraz na z oktalny na dziesiêtny
class kalkulator_octa
{
public:

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera OCT do DEC
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int oct_num - liczba OCT która chcemy konwertowaæ
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	int oct_dec(int oct_num) {

		//Stworzenie zmiennych 
		int result = 0, x10 = 0, value{};

		//G³owna pêtla odpowiadaj¹ca za konwersjê
		while (oct_num != 0) {
			
			//value przyjmuje modulo z wartoœci wejœciowej  przez co odzytujemy cyfry po kolei
			value = oct_num % 10;

			//Zabezpieczenie przed z³ymi znakami
			if (value < 0 || value > 7) {

				std::cerr << "Error: B³êdna liczba oktalna." << std::endl;
				return -3; 

			}

			//Zmniejszamy wartoœæ wejœciow¹ i dodajemy do wyniku kolejne potegi 8
			oct_num = oct_num / 10;
			result += value * std::pow(8, x10);
			x10++;

		}

		//Zwrócenenie wyniku
		return result;
	}

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera DEC do OCT
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int dec_num - liczba BIN która chcemy konwertowaæ
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	int dec_oct(int dec_num) {

		//Zabezpieczenie przed ujemnymi waroœciami
		if (dec_num < 0) {
			std::cerr << "Error: Liczba nie mo¿e byæ ujemna.." << std::endl;
			return -2;
		}

		//Zwraca zero dla zera
		if (dec_num == 0) {

			return 0;

		}

		//Utworzenie zmiennych
		int result{}, x10{}, buff{};
		x10 = 1;

		while (dec_num != 0) {

			//Stworzenie int value przyjmuj¹c¹ wartoœæ modulo z wartoœci wejœciowej dodanie do wyniku odpowiedniej cyfry(od 0 do 7) oraz pomno¿enie przez potege 10(pozycja cyfry)
			buff = dec_num % 8;
			result += buff * x10;
			x10 *= 10;

			//Podzielenie wartoœci wejœciowej przez 8
			dec_num /= 8;

		}

		//Zwrócenenie wyniku
		return result;

	}
};

