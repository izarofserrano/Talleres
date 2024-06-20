
#ifndef VEHICULO_H_
#define VEHICULO_H_

class Vehiculo {
	int id_vehiculo;
	int id_cli;
	char numSeguro[20];
	int anyoFabricacion;
	char matricula[10];
	char marca[30];
	char modelo[30];
	int id_color;
public:
	Vehiculo();
	Vehiculo(int id_vehiculo,int id_cli, char* numSeguro,int anyoFabricacion, char* matricula, char *marca, char* modelo,int id_color );
	Vehiculo(const Vehiculo &other);

	int getAnyoFabricacion() const;
	int getIdCli() const;
	int getIdColor() const;
	int getIdVehiculo() const;


	void setAnyoFabricacion(int anyoFabricacion);
	void setNumSeguro(const char* numSeg);
	void setMatricula(const char* matricula);
	void setIdCli(int idCli) ;
	void setIdVehiculo(int idVehiculo);
	void setMarca(const char* marca);
	void setIdColor(int idColor);
	void setModelo(const char* modelo);

	const char* getMarca() const;
	const char* getMatricula() const ;
	const char* getModelo() const;
	const char* getNumSeguro() const;

	static Vehiculo pedirVehiculo(int id_maxV, int id_cli)  ;
	static char*pedirMatricula();
	virtual ~Vehiculo();


};

#endif /* VEHICULO_H_ */
