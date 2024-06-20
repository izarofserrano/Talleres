
#include "Taller.h"
#include "string.h"

Taller::Taller() {
	id_taller=0;
	nombre_taller[0]='\0';
	dir_taller[0]='\0';
	ciudad[0]='\0';
	tlf_taller=0;


}

Taller::Taller(int id_taller, char* nom_taller, char* dir_taller, char*ciudad, int tlf_taller){
	this->id_taller=id_taller;
	strcpy(this->nombre_taller,nom_taller);
	strcpy(this->dir_taller,dir_taller);
	strcpy(this->ciudad,ciudad);
	this->tlf_taller=tlf_taller;
}

Taller::Taller(const Taller &ta) {
	this->id_taller=ta.id_taller;
	strcpy(this->nombre_taller,ta.nombre_taller);
	strcpy(this->dir_taller,ta.dir_taller);
	strcpy(this->ciudad,ta.ciudad);
	this->tlf_taller=ta.tlf_taller;
}
/*
const char* Taller::getCiudad() const {
	return ciudad;
}

const char* Taller::getDirTaller() const {
	return dir_taller;
}

int Taller::getIdTaller() const {
	return id_taller;
}

void Taller::setIdTaller(int idTaller) {
	id_taller = idTaller;
}

const char* Taller::getNombreTaller() const {
	return nombre_taller;
}

int Taller::getTlfTaller() const {
	return tlf_taller;
}

void Taller::setTlfTaller(int tlfTaller) {
	tlf_taller = tlfTaller;
}

*/
Taller::~Taller() {
	// TODO Auto-generated destructor stub
}
