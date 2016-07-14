/*
 * Menu.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu()
{

}

void Menu::clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void Menu::pause()
{
	#ifdef _WIN32
	system("pause");
	#else
	system("read -n1 -r -p \"Press any key to continue...\" key");
	#endif
}


bool Menu::validate(int option)
{
	if(option >= 1 && option <= 5)
	{
		return true;
	}else
	{
		cout << "Please pick an option between 1 and 5"<< endl;
		pause();
		return false;
	}
}

void Menu::routeAction(int option)
{
	switch(option)
	{
	case 1:
		listContacts();
		break;
	case 2:
		addContacts();
		break;
	case 3:
		removeContacts();
		break;
	case 4:
		modifyContacts();
		break;

	case 5:
		cout << "Thanks for using our software, good bye!" << endl;
	}
	pause();
}

void Menu::listContacts()
{
	ifstream leer_archivo("Agenda.txt");
	Contacto contacto;

	leer_archivo.read((char *)&contacto, sizeof(contacto));
	if (leer_archivo.fail())
	{
		cout << " Ocurrio un ploblema, intentando abrir la agenda :(" << endl;
		exit(1);
	}
	cout << "id   Nombre     Telefono" << endl;
	while (!leer_archivo.eof())
	{

		cout << endl << contacto.id << " -> " << contacto.nombre << "   " << contacto.telefono << endl;
		leer_archivo.read((char *)&contacto, sizeof(contacto));

	}
	cout << endl;
	leer_archivo.close();
}

void Menu::addContacts()
{
	system("cls");
	Contacto contacto;
	ofstream archivo;
	string nombre_archivo = "Agenda.txt";
	archivo.open(nombre_archivo.c_str(), ios::app);
	contacto.id = id;
	cin.ignore();
	cout << "Agregar Contacto" << endl;
	cout << endl << "Nombre: ";
	cin.getline(contacto.nombre, 30);
	cout << endl << "Numero: ";
	cin.getline(contacto.telefono, 11);

	archivo.write((char *)&contacto, sizeof(contacto));

	archivo.close();
}

void Menu::removeContacts()
{
	fstream leer_archivo("Agenda.txt");
	ofstream archivo("borrar.txt");
	Contacto contacto;
	leer_archivo.read((char *)&contacto, sizeof(contacto));

	if (leer_archivo.fail())
	{
		cout << " Ocurrio un ploblema, intentando abrir la agenda :(" << endl;
		exit(1);
	}

	while (!leer_archivo.eof())
	{

		if (contacto.id != id)
		{

			archivo.write((char *)&contacto, sizeof(contacto));
		}
		leer_archivo.read((char *)&contacto, sizeof(contacto));
	}
	cout << endl;
	leer_archivo.close();
	archivo.close();

	remove("Agenda.txt");
	rename("borrar.txt", "Agenda.txt");
}

void Menu::modifyContacts()
{
	//TODO: Implement this
	cout << "Implement  Menu::modifyContacts" << endl;
}

void Menu::show()
{
	int option;
	do
	{
		clearScreen();
		cout << "ITLA Phonebook" << endl;
		cout << "1- List contacts" << endl;
		cout << "2- Add contacts" << endl;
		cout << "3- Remove contact" << endl;
		cout << "4- Modify contact" << endl;
		cout << "5- Exit" << endl;
		cout << "Select an option => ";
		cin >> option;
		if(validate(option))
		{
			routeAction(option);
		}
	}while(option !=5);
}
