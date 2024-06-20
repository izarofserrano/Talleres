/*
 * Trabajo.h
 *
 *  Created on: 20 may 2024
 *      Author: LENOVO
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

class Trabajo {
	int id_trabajo;
	int id_vehiculo;
	int id_emp;
	char fecha_tra[11];
	char descripcion_tra[50];
public:
	Trabajo();
	Trabajo(int id_trabajo,int id_vehiculo,int id_emp, char *fecha_tra,char*descripcion_tra);
	Trabajo(const Trabajo &tra);

	const char* getDescripcionTra() const;
	char* getFechaTra();
	int getIdEmp() const;
	void setIdEmp(int idEmp);
	int getIdTrabajo() const;
	void setIdTrabajo(int idTrabajo);
	int getIdVehiculo() const;
	void setIdVehiculo(int idVehiculo);
	void setDescripcionTra(char * desc);
	void setFechaTra(char * fecha);

	static Trabajo pedirTrabajo(int id_maxTra, int id_emp, int id_v);
	static void imprimirTrabajo(Trabajo tra);

	virtual ~Trabajo();
};

#endif /* TRABAJO_H_ */
