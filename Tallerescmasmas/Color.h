/*
 * Color.h
 *
 *  Created on: 19 may 2024
 *      Author: LENOVO
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color {
	int id_col;
	char nombre_col[30];

public:
	Color();
	Color(int id_color, char* nombre_c);
	Color(const Color &other);

	int getIdCol() const;
	void setIdCol(int idCol);
	const char* getNombreCol() const;
	void setNombreCol(const char* nombreCol);
	void imprimirColor(Color c);

	virtual ~Color();

};

#endif /* COLOR_H_ */
