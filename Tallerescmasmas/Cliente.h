

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Usuario.h"

class Cliente : public Usuario {
	char nombre_cli[30];
	char apellido_cli[30];
	char dni_cli[10];
	char email_cli[40];
	int tlf_cli;

public:
	Cliente();
	Cliente(char *nombre_cli,char *apellido_cli,char *dni_cli,char *email_cli,int tlf_cli);
	Cliente(const Cliente &c);

	const char* getApellidoCli() const;
	const char* getDniCli() const;
	const char* getEmailCli() const;
	const char* getNombreCli() const;
	int getTlfCli() const;
	void setTlfCli(int tlfCli);
	void setNombreCli(char*nom);
	void setApellidoCli(char*ap);
	void setDNICli(char*dni);
	void setEmailCli(char*email);

	static Cliente pedirCliente();
	void imprimirCliente();
	static char* pedirDni();

	virtual ~Cliente();

};

#endif /* CLIENTE_H_ */
