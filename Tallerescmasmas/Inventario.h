
#ifndef INVENTARIO_H_
#define INVENTARIO_H_

class Inventario {
	int id_inventario;
	int id_taller;
	char material[30];
	int cant_inv;
public:
	Inventario();
	Inventario(int id_inventario,int id_taller,char *material, int cant_inv);
	Inventario(const Inventario &other);

	int getCantInv() const;
	void setCantInv(int cantInv);
	int getIdInventario() const;
	void setIdInventario(int idInventario);
	int getIdTaller() const;
	void setIdTaller(int idTaller);
	void setMaterial(const char* material);
	const char* getMaterial() const ;
	static Inventario pedirInventario(int id_taller, int id_maxInv);
	void imprimirInv(Inventario inv);
	virtual ~Inventario();
};

#endif /* INVENTARIO_H_ */
