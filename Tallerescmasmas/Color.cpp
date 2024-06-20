
#include "Color.h"
#include <string.h>
#include <iostream>

using namespace std;

Color::Color() {
	id_col=0;
	nombre_col[0]='\0';


}

Color::Color(int id_color, char* nombre_c){
	this->id_col=id_color;
	strcpy(this->nombre_col,nombre_c);

}
Color::Color(const Color &col) {
	this->id_col=col.id_col;
	strcpy(this->nombre_col,col.nombre_col);
}

int Color::getIdCol() const {
	return id_col;
}

void Color::setIdCol(int idCol) {
	id_col = idCol;
}

const char* Color::getNombreCol() const {
	return nombre_col;
}

void Color::setNombreCol(const char* nombreCol) {
    strcpy(nombre_col, nombreCol);
}

void imprimirColor(Color c){
	cout<<c.getIdCol()<<". "<<c.getNombreCol()<<endl;
}
Color::~Color() {
	// TODO Auto-generated destructor stub
}
