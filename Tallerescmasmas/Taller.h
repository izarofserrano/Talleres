

#ifndef TALLER_H_
#define TALLER_H_

class Taller {
	int id_taller;
	char nombre_taller[30];
	char dir_taller[30];
	char ciudad[30];
	int tlf_taller;
public:
	Taller();
	Taller(int id_taller, char* nom_taller, char* dir_taller, char*ciudad, int tlf_taller);
	Taller(const Taller &other);
	virtual ~Taller();

	const char* getCiudad() const {
		return ciudad;
	}

	const char* getDirTaller() const {
		return dir_taller;
	}

	int getIdTaller() const {
		return id_taller;
	}

	void setIdTaller(int idTaller) {
		id_taller = idTaller;
	}

	const char* getNombreTaller() const {
		return nombre_taller;
	}

	int getTlfTaller() const {
		return tlf_taller;
	}

	void setTlfTaller(int tlfTaller) {
		tlf_taller = tlfTaller;
	}
};

#endif /* TALLER_H_ */
