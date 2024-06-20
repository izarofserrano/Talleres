/*
#include <winsock2.h>
#include "Color.h"

#ifndef LISTACOLORES_H_
#define LISTACOLORES_H_

class ListaColores {
	Color *aColores;
	int numC;
	int tamC;
public:
	ListaColores();

	virtual ~ListaColores();

	Color*& getAColores();
	void setAColores(int numC) ;
	int getNumC() const ;
	void setNumC(int numC) ;
	int getTamC() const;
	void setTamC(int tamC) ;

	void recibirListaColores(SOCKET s, char *sendBuff, char* recvBuff, ListaColores &colores);
	void aniadirColor(ListaColores& lColores, const Color& c);
};


#endif *//* LISTACOLORES_H_ */
