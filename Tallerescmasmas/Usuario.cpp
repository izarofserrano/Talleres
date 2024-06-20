#include <iostream>
#include <string.h>
#include "Usuario.h"
#include "Menu.h"
using namespace std;
Usuario::Usuario() {
    id_user = 0;
    username[0] = '\0';
    contrasenya[0] = '\0';
    tipo_user = 0;
}

Usuario::Usuario(int id_user, const char *username, const char *contrasenya, int tipo_user) {
    this->id_user = id_user;
    strcpy(this->username, username);
    strcpy(this->contrasenya, contrasenya);
    this->tipo_user = tipo_user;
}

Usuario::Usuario(const Usuario &other) {
    id_user = other.id_user;
    strcpy(username, other.username);
    strcpy(contrasenya, other.contrasenya);
    tipo_user = other.tipo_user;
}
//GETTERS
const char* Usuario::getContrasenya() const {
    return contrasenya;
}

int Usuario::getIdUser() const {
    return id_user;
}

int Usuario::getTipoUser() const {
    return tipo_user;
}

const char* Usuario::getUsername() const {
    return username;
}
//SETTERS
void Usuario::setTipoUser(int tipoUser) {
		tipo_user = tipoUser;
}
void Usuario::setUsername(const char* newUsername) {
    strcpy(username, newUsername);
}

void Usuario::setContrasenya(const char* newContrasenya) {
    strcpy(contrasenya, newContrasenya);
}
void Usuario::setIdUser(int idUser) {
    id_user = idUser;
}

Usuario Usuario::pedirUsuarioRegistro(int id_maxUsu) {
    Usuario u;
    Menu m;
    char opc;
    int num;

    u.setIdUser(id_maxUsu);

    cout << "USERNAME: ";
    cin >> u.username;
    cout << "CONTRASENYA: ";
    cin >> u.contrasenya;

    opc = m.menuRegistro();
    num = opc - '0';
    u.tipo_user = num;
    return u;
}

Usuario Usuario::pedirUsuarioIniciarSesion() {
    Usuario u;

    cout << "USERNAME: ";
    cin >> u.username;
    cout << "CONTRASENYA: ";
    cin >> u.contrasenya;

    return u;
}

void Usuario::imprimir() {
    cout << "ID User: " << id_user << " Username: " << username << " Contrasenya: " << contrasenya << endl;
}

Usuario::~Usuario() {
    // Destructor implementation, if needed
}
