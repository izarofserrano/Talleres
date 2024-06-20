/*
 * Trabajo.cpp
 *
 *  Created on: 20 may 2024
 *      Author: LENOVO
 */

#include "Trabajo.h"
#include <string.h>
#include <iostream>
using namespace std;

Trabajo::Trabajo() {
	id_trabajo=0;
	id_vehiculo=0;
	id_emp=0;
	fecha_tra[0]='\0';
	descripcion_tra[0]='\0';

}

Trabajo::Trabajo(int id_trabajo,int id_vehiculo,int id_emp, char *fecha_tra,char*descripcion_tra){
	this->id_trabajo=id_trabajo;
	this->id_vehiculo=id_vehiculo;
	this->id_emp=id_emp;
	strcpy(this->fecha_tra,fecha_tra);
	strcpy(this->descripcion_tra,descripcion_tra);
}

Trabajo::Trabajo(const Trabajo &tra) {
	this->id_trabajo=tra.id_trabajo;
	this->id_vehiculo=tra.id_vehiculo;
	this->id_emp=tra.id_emp;
	strcpy(this->fecha_tra,tra.fecha_tra);
	strcpy(this->descripcion_tra,tra.descripcion_tra);
}

const char* Trabajo::getDescripcionTra() const {
	return descripcion_tra;
}

char* Trabajo::getFechaTra() {
	return fecha_tra;
}

int Trabajo::getIdEmp() const {
	return id_emp;
}

void Trabajo::setIdEmp(int idEmp) {
	id_emp = idEmp;
}

int Trabajo::getIdTrabajo() const {
	return id_trabajo;
}

void Trabajo::setIdTrabajo(int idTrabajo) {
	id_trabajo = idTrabajo;
}

int Trabajo::getIdVehiculo() const {
	return id_vehiculo;
}

void Trabajo::setIdVehiculo(int idVehiculo) {
	id_vehiculo = idVehiculo;
}

void Trabajo::setDescripcionTra(char * desc){
	strcpy(descripcion_tra,desc);
}
void Trabajo::setFechaTra(char * fecha){
	strcpy(fecha_tra,fecha);
}

Trabajo Trabajo::pedirTrabajo(int id_maxTra, int id_emp, int id_v){
	Trabajo tra;
	char fecha[1], desc[50];
	tra.setIdTrabajo(id_maxTra);
	tra.setIdEmp(id_emp);
	tra.setIdVehiculo(id_v);

	cout << "Fecha: ";
	cin >> fecha;
	tra.setFechaTra(fecha);
	cout << "Descripcion: ";
	cin >> desc;
	tra.setDescripcionTra(desc);

	return tra;
}
void Trabajo::imprimirTrabajo(Trabajo tra){
	cout<<"Id trabajo: "<<tra.getIdTrabajo()<<", Id vehiculo: "<<tra.getIdVehiculo()
		<<", Id empleado: "<<tra.getIdEmp()<<", Fecha: "<<tra.getFechaTra()
		<<", Descripcion: "<<tra.getDescripcionTra()<<endl;
}


Trabajo::~Trabajo() {
	// TODO Auto-generated destructor stub
}
