/*
 * Registro.cpp
 *
 *  Created on: 20 may 2024
 *      Author: LENOVO
 */

#include "Registro.h"
#include <string.h>
#include <iostream>
using namespace std;

Registro::Registro() {
	id_registro=0;
	id_trabajo=0;
	id_cliente=0;
	fecha_hora[0]='0';

}

Registro::Registro(int id_maxReg, int id_tra, int id_cli, char* fecha){
	this->id_registro=id_maxReg;
	this->id_trabajo=id_tra;
	this->id_cliente=id_cli;
	strcpy(this->fecha_hora,fecha);
}



Registro::Registro(const Registro &reg) {
	this->id_registro=reg.id_registro;
	this->id_trabajo=reg.id_trabajo;
	this->id_cliente=reg.id_cliente;
	strcpy(this->fecha_hora,reg.fecha_hora);
}

const char* Registro::getFechaHora() const {
	return fecha_hora;
}

int Registro::getIdCliente() const {
	return id_cliente;
}

void Registro::setIdCliente(int idCliente) {
	id_cliente = idCliente;
}

int Registro::getIdRegistro() const {
	return id_registro;
}

void Registro::setIdRegistro(int idRegistro) {
	id_registro = idRegistro;
}

int Registro::getIdTrabajo() const {
	return id_trabajo;
}

void Registro::setIdTrabajo(int idTrabajo) {
	id_trabajo = idTrabajo;
}

void Registro::setFecha(char*fecha) {

	strcpy(fecha_hora,fecha);
}

Registro::~Registro() {
	// TODO Auto-generated destructor stub
}
