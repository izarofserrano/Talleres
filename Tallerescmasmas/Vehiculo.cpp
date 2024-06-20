#include "Vehiculo.h"
#include <string.h>
#include <iostream>
using namespace std;

Vehiculo::Vehiculo() {
	id_vehiculo=0;
	id_cli=0;
	numSeguro[0]= '\0';
	anyoFabricacion=0;
	matricula[0]= '\0';
	marca[0]= '\0';
	modelo[0]= '\0';
	id_color=0;
}
Vehiculo::Vehiculo(int id_vehiculo,int id_cli, char* numSeguro,int anyoFabricacion, char* matricula, char *marca, char* modelo,int id_color ){
	this->id_vehiculo=id_vehiculo;
	this->id_cli=id_cli;
	strcpy(this->numSeguro,numSeguro);
	this->anyoFabricacion=anyoFabricacion;
	strcpy(this->matricula,matricula);
	strcpy(this->marca,marca);
	strcpy(this->modelo,modelo);
	this->id_color=id_color;
}


Vehiculo::Vehiculo(const Vehiculo &v) {
	this->id_vehiculo=v.id_vehiculo;
	this->id_cli=v.id_cli;
	strcpy(this->numSeguro,v.numSeguro);
	this->anyoFabricacion=v.anyoFabricacion;
	strcpy(this->matricula,v.matricula);
	strcpy(this->marca,v.marca);
	strcpy(this->modelo,v.modelo);
	this->id_color=v.id_color;
}

int Vehiculo::getAnyoFabricacion() const {
	return anyoFabricacion;
}

void Vehiculo::setAnyoFabricacion(int anyoFabricacion) {
	this->anyoFabricacion = anyoFabricacion;
}

int Vehiculo::getIdCli() const {
	return id_cli;
}

void Vehiculo::setIdCli(int idCli) {
	id_cli = idCli;
}

int Vehiculo::getIdColor() const {
	return id_color;
}

void Vehiculo::setIdColor(int idColor) {
	id_color = idColor;
}

int Vehiculo::getIdVehiculo() const {
	return id_vehiculo;
}

void Vehiculo::setIdVehiculo(int idVehiculo) {
	id_vehiculo = idVehiculo;
}

const char* Vehiculo::getMarca() const {
	return marca;
}

const char* Vehiculo::getMatricula() const {
	return matricula;
}

const char* Vehiculo::getModelo() const {
	return modelo;
}

const char* Vehiculo::getNumSeguro() const {
	return numSeguro;
}
void Vehiculo::setMarca(const char* marca) {
    strcpy(this->marca, marca);
}

void Vehiculo::setModelo(const char* modelo) {
    strcpy(this->modelo, modelo);
}

void Vehiculo::setNumSeguro(const char* numSeg){
	strcpy(this->numSeguro,numSeg);
}
void Vehiculo::setMatricula(const char* matricula){
	strcpy(this->matricula,matricula);
}


Vehiculo Vehiculo::pedirVehiculo(int id_maxV, int id_cli) {
	Vehiculo v;
	char marca[30], modelo[30], matricula[10],numSeguro[20];
	int anyo,id_color;
	v.setIdCli(id_cli);
	v.setIdVehiculo(id_maxV);
	cout << "Numero de seguro: ";
	cin >> numSeguro;
	v.setNumSeguro(numSeguro);
	cout << "Anyo fabricacion: ";
	cin >> anyo;
	v.setAnyoFabricacion(anyo);
	cout << "Matricula: ";
	cin >> matricula;
	v.setMatricula(matricula);

	cout << "Marca: ";
	cin >> marca;
	v.setMarca(marca);
	cout << "Modelo: ";
	cin >> modelo;
	v.setModelo(modelo);
	cout << "Color: ";
	cin >> id_color;
	v.setIdColor(id_color);


    return v;
}

char *Vehiculo::pedirMatricula(){
	char* matricula = new char[10];
	std::cout << "Matricula: ";
	std::cin >> matricula;
	return matricula;
}

Vehiculo::~Vehiculo() {
	// TODO Auto-generated destructor stub
}
