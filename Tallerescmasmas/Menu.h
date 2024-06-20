
#ifndef MENU_H_
#define MENU_H_

class Menu {
public:
	Menu();
	char menuPrincipal();
	char menuRegistro();
	char menuGuardarSalir();
	char menuVerHistorial();
	char menuDecisionesCliente();
	char menuTalleres();
	char menuEmpleado();
	char menuInventario();
	char menuServicios();
	virtual ~Menu();
	Menu(const Menu &other);
};

#endif /* MENU_H_ */
