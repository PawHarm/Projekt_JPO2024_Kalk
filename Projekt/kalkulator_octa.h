//Pawe� Harmata EIT 3 Projekt JPO 
//Kalkulator dla Elektronik�w/Informatyk�w
#pragma once

//Dodanie bibliotek 
#include <iostream>

//Utworzenie klasy odpowiedzialnej za konwersje systemu z dziesi�tnego na oktalny
//oraz na z oktalny na dziesi�tny
class kalkulator_octa
{
public:

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera OCT do DEC
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int oct_num - liczba OCT kt�ra chcemy konwertowa�
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	int oct_dec(int oct_num) {

		//Stworzenie zmiennych 
		int result = 0, x10 = 0, value{};

		//G�owna p�tla odpowiadaj�ca za konwersj�
		while (oct_num != 0) {
			
			//value przyjmuje modulo z warto�ci wej�ciowej  przez co odzytujemy cyfry po kolei
			value = oct_num % 10;

			//Zabezpieczenie przed z�ymi znakami
			if (value < 0 || value > 7) {

				std::cerr << "Error: B��dna liczba oktalna." << std::endl;
				return -3; 

			}

			//Zmniejszamy warto�� wej�ciow� i dodajemy do wyniku kolejne potegi 8
			oct_num = oct_num / 10;
			result += value * std::pow(8, x10);
			x10++;

		}

		//Zwr�cenenie wyniku
		return result;
	}

	///////////////////////////////////////////////////////////////////////////
	//Dodanie funckji konwertera DEC do OCT
	///////////////////////////////////////////////////////////////////////////
	// INPUT:
	//     int dec_num - liczba BIN kt�ra chcemy konwertowa�
	///////////////////////////////////////////////////////////////////////////
	// OUTPUT:
	//     int result - wynik konwersji
	///////////////////////////////////////////////////////////////////////////
	int dec_oct(int dec_num) {

		//Zabezpieczenie przed ujemnymi waro�ciami
		if (dec_num < 0) {
			std::cerr << "Error: Liczba nie mo�e by� ujemna.." << std::endl;
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

			//Stworzenie int value przyjmuj�c� warto�� modulo z warto�ci wej�ciowej dodanie do wyniku odpowiedniej cyfry(od 0 do 7) oraz pomno�enie przez potege 10(pozycja cyfry)
			buff = dec_num % 8;
			result += buff * x10;
			x10 *= 10;

			//Podzielenie warto�ci wej�ciowej przez 8
			dec_num /= 8;

		}

		//Zwr�cenenie wyniku
		return result;

	}
};

