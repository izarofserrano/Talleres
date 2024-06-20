/*
 * Usuario.h
 *
 *  Created on: 19 may 2024
 *      Author: LENOVO
 */

#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario {
	int id_user;
	char username[40];
	char contrasenya[40];
	int tipo_user;
public:
	Usuario();
	Usuario(int id_user, const char* username, const char* contrasenya, int tipo_user);
	Usuario(const Usuario &other);

	int getIdUser() const;
	int getTipoUser() const;
	const char* getUsername() const;
	const char* getContrasenya() const;

	void setIdUser(int idUser);
	void setTipoUser(int tipoUser);
	void setUsername(const char* newUsername);
	void setContrasenya(const char* newContrasenya);

	static Usuario pedirUsuarioRegistro(int id_maxUsu);
	static Usuario pedirUsuarioIniciarSesion();
	void imprimir();
	~Usuario();


};

#endif /* USUARIO_H_ */
