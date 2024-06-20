
#include "Cliente.h"
#include <string.h>
#include <iostream>
using namespace std;

Cliente::Cliente() {
    nombre_cli[0] = '\0';
    apellido_cli[0] = '\0';
    dni_cli[0] = '\0';
    email_cli[0] = '\0';
    tlf_cli = 0;
}

Cliente::Cliente(char *nombre_cli,char *apellido_cli,char *dni_cli,char *email_cli,int tlf_cli){

	strcpy(this->nombre_cli, nombre_cli);
    strcpy(this->apellido_cli, apellido_cli);
    strcpy(this->dni_cli, dni_cli);
    strcpy(this->email_cli, email_cli);
    this->tlf_cli = tlf_cli;
}

Cliente::Cliente(const Cliente &other) {
    strcpy(this->nombre_cli, other.nombre_cli);
    strcpy(this->apellido_cli, other.apellido_cli);
    strcpy(this->dni_cli, other.dni_cli);
    strcpy(this->email_cli, other.email_cli);
    this->tlf_cli = other.tlf_cli;
}

const char* Cliente::getApellidoCli() const {
    return apellido_cli;
}

const char* Cliente::getDniCli() const {
    return dni_cli;
}

const char* Cliente::getEmailCli() const {
    return email_cli;
}

const char* Cliente::getNombreCli() const {
    return nombre_cli;
}

int Cliente::getTlfCli() const {
    return tlf_cli;
}

void Cliente::setNombreCli(char*nom){
	strcpy(nombre_cli,nom);
}
void Cliente::setApellidoCli(char*ap){
	strcpy(apellido_cli,ap);

}
void Cliente::setDNICli(char*dni){
	strcpy(dni_cli,dni);

}
void Cliente::setEmailCli(char*email){
	strcpy(email_cli,email);

}




void Cliente::setTlfCli(int tlfCli) {
    tlf_cli = tlfCli;
}

Cliente Cliente::pedirCliente() {
	Cliente c;
	cout << "Nombre: ";
	cin >> c.nombre_cli;

	cout << "Apellido: ";
	cin >> c.apellido_cli;

	cout << "DNI: ";
	cin >> c.dni_cli;

	cout << "Email: ";
	cin >> c.email_cli;

	cout << "Telefono: ";
	cin >> c.tlf_cli;
    return c;

}

void Cliente::imprimirCliente() {
	imprimir();
	cout<<"hola "<<nombre_cli<<endl;
    //cout << "Nombre: " << nombre_cli << ", Apellido: " << apellido_cli << ", DNI: " << getDniCli() << ", Email: " << email_cli << ", Telefono: " << tlf_cli << ", Tipo de usuario: " << getTipoUser() << endl;
}

char* Cliente::pedirDni(){
	char tempDni[10];
	cout << "DNI: ";
	cin >> tempDni;
	char* dni_cli = new char[strlen(tempDni) + 1];
	strcpy(dni_cli, tempDni);
	return dni_cli;

}

Cliente::~Cliente() {
    // No hay recursos dinámicos para liberar
}
