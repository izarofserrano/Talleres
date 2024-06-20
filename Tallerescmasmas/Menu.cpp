

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {}

Menu::~Menu() {}

Menu::Menu(const Menu &other) {}

char Menu::menuPrincipal() {
    char opcion;
    cout << "TALLERES\n";
    cout << "--------\n";
    cout << "1. Iniciar Sesion\n";
    cout << "2. Registrarse\n";
    cout << "0. Salir\n";
    cout << "Elige una opcion: ";
    cin >> opcion;
    return opcion;
}

char Menu::menuRegistro() {
    char opcion;
    cout << "Tipo de usuario: \n";
    cout << "1. Cliente\n";
    cout << "2. Empleado\n";
    cout << "Elige una opcion: ";
    cin >> opcion;
    return opcion;
}

char Menu::menuGuardarSalir() {
    char opcion;
    cout << "1. Guardar\n";
    cout << "2. Salir\n";
    cout << "Elige una opcion: ";
    cin >> opcion;
    return opcion;
}

char Menu::menuVerHistorial() {
    char opcion;
    cout << "TALLERES\n";
    cout << "--------\n";
    cout << "CLIENTE: MENU-->VER HISTORIAL\n";
    cout << "1. Ver historial del coche introducido\n";
    cout << "2. Ver historial de todos tus coches\n";
    cout << "0. Salir\n";
    cout << "Elige una opcion: ";
    cin >> opcion;
    return opcion;
}

char Menu::menuDecisionesCliente() {
    char opcion;
    cout << "TALLERES\n";
    cout << "--------\n";
    cout << "CLIENTE: MENU\n";
    cout << "1. Tus datos\n";
    cout << "2. Ver historial de todos los servicios\n";
    cout << "3. Solicitar servicios\n";
    cout << "0. Salir\n";
    cout << "Elige una opcion: ";
    cin >> opcion;
    return opcion;
}

char Menu::menuTalleres() {
    char opcion;
    cout << "TALLERES\n";
    cout << "--------\n";
    cout << "EMPLEADO\n";
    cout << "Elige sucursal:\n";
    cout << "1. Bilbao\n";
    cout << "2. Barcelona\n";
    cout << "3. Madrid: \n";
    cout << "Elige una opcion: ";
    cin >> opcion;
    return opcion;
}
char Menu::menuEmpleado(){
	char opcion;
	cout << "TALLERES\n";
	cout << "--------\n";
	cout << "EMPLEADO\n";
	cout << "1. Inventario\n";
	cout << "2. Registro del servicio\n";
	cout << "0. Salir: \n";
	cout << "Elige una opcion: ";
	cin >> opcion;
	return opcion;
}
char Menu::menuInventario(){
	char opcion;
	cout << "TALLERES\n";
	cout << "--------\n";
	cout << "EMPLEADO\n";
	cout << "1. Aniadir producto\n";
	cout << "2. Eliminar producto\n";
	cout << "0. Salir: \n";
	cout << "Elige una opcion: ";
	cin >> opcion;
	return opcion;
}
char Menu::menuServicios(){
	char opcion;
		cout << "TALLERES\n";
		cout << "--------\n";
		cout << "Servicios:\n";
		cout << "1. Arreglos\n";
		cout << "2. Mantenimiento\n";
		cout << "3. Pintura\n";
		cout << "4. Revision\n";
		cout << "0. Salir: \n";
		cout << "Elige una opcion: ";
		cin >> opcion;
		return opcion;

}
