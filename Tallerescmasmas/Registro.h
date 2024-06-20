/*
 * Registro.h
 *
 *  Created on: 20 may 2024
 *      Author: LENOVO
 */

#ifndef REGISTRO_H_
#define REGISTRO_H_

class Registro {
	int id_registro;
	int id_cliente;
	int id_trabajo;
	char fecha_hora[20];
public:
	Registro();
	Registro(int id_maxReg, int id_tra, int id_cli, char* fecha);
	Registro(const Registro &reg);

	const char* getFechaHora() const;
	int getIdCliente() const;
	void setIdCliente(int idCliente);
	int getIdRegistro() const;
	void setIdRegistro(int idRegistro);
	int getIdTrabajo() const;
	void setIdTrabajo(int idTrabajo) ;
	void setFecha(char*fecha);

	virtual ~Registro();
};

#endif /* REGISTRO_H_ */
