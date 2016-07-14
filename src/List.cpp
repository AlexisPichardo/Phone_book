/*
 * List.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List::List(): _first(NULL), _last(NULL)
{


}

void List::add(Element* element)
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

void List::remove(int index)
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

void List::modify(int index, std::string name)
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
