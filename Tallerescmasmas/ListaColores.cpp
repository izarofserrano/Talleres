/*

#include "ListaColores.h"
#include <string.h>
#include <stdio.h>
#include <winsock2.h>
#include <iostream>
using namespace std;
ListaColores::ListaColores() {
	aColores=NULL;
	numC=0;
	tamC=0;


}

void recibirListaColores(SOCKET s, char *sendBuff, char* recvBuff, ListaColores &colores){
	int numC, id_col;
	char nombreCol[30];
	recv(s, (char*)&numC, sizeof(numC), 0);

	colores.setAColores(numC) ;
	colores.setNumC(numC);
	colores.setTamC(numC);

	for (int i = 0; i < numC; i++) {
		// Recibir id_col
		Color c;
		recv(s,recvBuff,sizeof(recvBuff),0); //Recibo del servidor
		sscanf(recvBuff, "%d", &id_col);

		recv(s,recvBuff,sizeof(recvBuff),0); //Recibo del servidor
		sscanf(recvBuff, "%s", nombreCol);
		c.setIdCol(id_col);
		c.setNombreCol(nombreCol);
		colores.aniadirColor(colores,c);

}
}
void ListaColores::setAColores(int numC) {
	this->aColores[numC];
}

int ListaColores::getNumC() const {
	return numC;
}

void ListaColores::setNumC(int numC) {
	this->numC = numC;
}

int ListaColores::getTamC() const {
	return tamC;
}

void ListaColores::setTamC(int tamC) {
	this->tamC = tamC;
}
Color*& ListaColores::getAColores() {
    return aColores;
}

void ListaColores::aniadirColor(ListaColores& lColores, const Color& c) {
    if (lColores.getNumC() < lColores.getTamC()) {
        lColores.getAColores()[lColores.getNumC()] = c;
        lColores.setNumC(lColores.getNumC() + 1);
    } else {
        cout << "No hay suficiente espacio en la lista para añadir el color." << endl;
    }
}
ListaColores::~ListaColores() {
	if(aColores!=NULL){
		delete[]aColores;
	}
}
*/
