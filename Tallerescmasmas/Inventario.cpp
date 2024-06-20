#include "Inventario.h"
#include <string.h>
#include <iostream>
using namespace std;

Inventario::Inventario() {
	id_inventario=0;
	id_taller=0;
	material[0]='\0';
	cant_inv=0;
}

Inventario::Inventario(int id_inventario,int id_taller,char *material, int cant_inv){
	this->id_inventario=id_inventario;
	this->id_taller=id_taller;
	strcpy(this->material,material);
	this->cant_inv=cant_inv;
}

Inventario::Inventario(const Inventario &inv) {
	this->id_inventario=inv.id_inventario;
	this->id_taller=inv.id_taller;
	strcpy(this->material,inv.material);
	this->cant_inv=inv.cant_inv;
}


int Inventario::getCantInv() const {
	return cant_inv;
}

void Inventario::setCantInv(int cantInv) {
	cant_inv = cantInv;
}

int Inventario::getIdInventario() const {
	return id_inventario;
}

void Inventario::setIdInventario(int idInventario) {
	id_inventario = idInventario;
}

int Inventario::getIdTaller() const {
	return id_taller;
}

void Inventario::setIdTaller(int idTaller) {
	id_taller = idTaller;
}

const char* Inventario::getMaterial() const {
	return material;
}

void  Inventario::setMaterial(const char* material) {
    strcpy(this->material, material);
}


Inventario Inventario::pedirInventario(int id_taller, int id_maxInv){
	Inventario inv;
	char material[30];
	int cant;
	inv.setIdInventario(id_maxInv);
	inv.setIdTaller(id_taller);

	std::cout << "Material: ";
	std::cin >> material;
	inv.setMaterial(material);

	std::cout << "Cantidad: ";
	std::cin >> cant;
	inv.setCantInv(cant);

	    return inv;

}

void Inventario:: imprimirInv(Inventario inv){
	cout<<"Id inventario: "<<inv.getIdInventario()<<", Id taller: "<<inv.getIdTaller()<<", Material: "<<inv.getMaterial()<<", Cantidad: "<<inv.getCantInv()<<endl;
}

Inventario::~Inventario() {
	// TODO Auto-generated destructor stub
}
