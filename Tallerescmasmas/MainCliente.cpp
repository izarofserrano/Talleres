// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>

#include <winsock2.h>
#include <iostream>
#include "Menu.h"
#include "Usuario.h"
#include "Inventario.h"
#include "Vehiculo.h"
#include "Cliente.h"
#include "Trabajo.h"
#include "Registro.h"
#include "ListaColores.h"
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000
using namespace std;

void removeNewline(char* str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

void recibirVehiculosDeCliente(SOCKET s, char *recvBuff, int buffSize) {
    int id_vehiculo, id_cliente, anyo_fabricacion, id_color,n;
    char num_seguro[20], matricula[10], marca[30], modelo[30];

    while (true) {
        // Recibir ID del vehículo
        n=recv(s, recvBuff, buffSize, 0);
        if (strcmp(recvBuff, "FIN") == 0) {
            break; // Salir del bucle al recibir la señal "FIN"
        }
        recvBuff[n]='\0';
        id_vehiculo = atoi(recvBuff);

        // Recibir ID del cliente
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        id_cliente = atoi(recvBuff);

        // Recibir número de seguro
        n = recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        strncpy(num_seguro, recvBuff, sizeof(num_seguro) - 1);

        // Recibir año de fabricación
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        anyo_fabricacion = atoi(recvBuff);

        // Recibir matrícula
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        strncpy(matricula, recvBuff, sizeof(matricula) - 1);

        // Recibir marca
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        strncpy(marca, recvBuff, sizeof(marca) - 1);

        // Recibir modelo
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        strncpy(modelo, recvBuff, sizeof(modelo) - 1);

        // Recibir ID del color
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        id_color = atoi(recvBuff);

        // Imprimir la información recibida
        cout << "\tID Vehiculo: " << id_vehiculo
                  << ", ID Cliente: " << id_cliente
                  << ", Numero de Seguro: " << num_seguro
                  << ", Año de Fabricación: " << anyo_fabricacion
                  << ", Matrícula: " << matricula
                  << ", Marca: " << marca
                  << ", Modelo: " << modelo
                  << ", ID Color: " << id_color
                  << endl;


    }

}

void recibirTrabajosPorCliente(SOCKET s, char *recvBuff, int buffSize) {
    int id_trabajo, id_v, id_emp, n;
    char fecha[20]; // Aumenté el tamaño para manejar fechas más largas
    char desc[256]; // Aumenté el tamaño para manejar descripciones más largas

    while (true) {

        // Recibir ID del trabajo
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n] = '\0';
        if (strcmp(recvBuff, "FIN") == 0) break;
        id_trabajo = atoi(recvBuff);

        // Recibir ID del vehículo
        n = recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        id_v = atoi(recvBuff);

        // Recibir ID del empleado
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        id_emp = atoi(recvBuff);

        // Recibir fecha
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        strncpy(fecha, recvBuff, sizeof(fecha) - 1);
        fecha[sizeof(fecha) - 1] = '\0'; // Asegúrate de que la cadena esté terminada en nulo

        // Recibir descripción
        n=recv(s, recvBuff, buffSize, 0);
        recvBuff[n]='\0';
        strncpy(desc, recvBuff, sizeof(desc) - 1);
        desc[sizeof(desc) - 1] = '\0'; // Asegúrate de que la cadena esté terminada en nulo

        cout << "ID Trabajo: " << id_trabajo
        		<< ", ID Vehiculo: " << id_v
				<< ", ID Empleado: " << id_emp
				<< ", Fecha: " << fecha
				<< ", Descripcion: " << desc
				<< std::endl;


    }
}




int main(int argc, char *argv[]) {

	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	/*
	 * En sendBuff guardaremos lo que el cliente le envía al servidor
	 * En recvBuff guardaremos lo que el servidor le envía al cliente
	 * */
	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP); //INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	/*EMPIEZA EL PROGRAMA DEL CLIENTE*/
	recv(s,recvBuff,sizeof(recvBuff),0);
	cout<<recvBuff<<endl;
	/*ListaColores lColores;
	lColores.recibirListaColores(s,sendBuff,recvBuff, lColores);*/
	int enc,tipo_user,id_user, id_maxInv, id_maxUsu,id_maxTra, id_maxV,id_maxReg,existe,id_cli,n,count;
    char opcion_prin, opcion_emp, opcion_taller,opcion_inv,opcion_decisiones,opcion_serv;
	char opc_elim, equis_elim;
    Menu menu;
    Usuario u, user_new;
    Inventario inv;
    Trabajo tra;
    Vehiculo v;
    Registro reg;
    Cliente cli;
    char string[512];


	do{
		opcion_prin = menu.menuPrincipal();
		sprintf(sendBuff,"%c",opcion_prin); //Guardo en sendBuff lo que le quiero enviar al servidor
		send(s,sendBuff,strlen(sendBuff),0); //Envio al servidor
		//SWITCH 1
		switch(opcion_prin){
		case '0':{
			recv(s,recvBuff,sizeof(recvBuff),0); //Recibo del servidor
			cout<<recvBuff<<endl; //Visualizo lo recibido
			break;
		}
		case '1':{
			Usuario u_ini = Usuario::pedirUsuarioIniciarSesion();
			sprintf(sendBuff, "%s", u_ini.getUsername()); // Guardo en sendBuff el username
			removeNewline(sendBuff);
			send(s, sendBuff, strlen(sendBuff), 0); // Se lo envío al servidor
			sprintf(sendBuff, "%s", u_ini.getContrasenya());
			removeNewline(sendBuff);
			send(s, sendBuff, strlen(sendBuff), 0);

			recv(s, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%d", &enc);

			if (enc == -1) {
				cout<<"Lo sentimos, este usuario o contrasenya no se encuentra en la base de datos.\n";
			} else {

				recv(s,recvBuff,sizeof(recvBuff),0);
				sscanf(recvBuff,"%d",&tipo_user);
				cout<<tipo_user<<endl;
				u_ini.setTipoUser(tipo_user);
				cout<<"Has iniciado sesión con exito. Bienvenido "<<u_ini.getUsername()<<endl;

				if(tipo_user==1){
					int tlf,tipo_us;
					char nom[30],ap[30],dni[10],email[30];
					//CLIENTE
					do{
						opcion_decisiones = menu.menuDecisionesCliente();
						sprintf(sendBuff,"%c",opcion_decisiones); //Guardo en sendBuff lo que le quiero enviar al servidor
						send(s,sendBuff,strlen(sendBuff),0); //Envio al servidor
						switch(opcion_decisiones){
						case '0':
							cout<<"GRACIAS"<<endl;
							break;
						case '1':{
							cout<<"DATOS PERSONALES: "<<endl;
							n = recv(s,recvBuff,sizeof(recvBuff),0);
							recvBuff[n]='\0';
							sprintf(string,"%s",recvBuff);
							cout<<string<<endl;

							recv(s,recvBuff,sizeof(recvBuff),0);
							sscanf(recvBuff,"%d",&id_user);

							recv(s,recvBuff,sizeof(recvBuff),0);
							sprintf(nom,"%s",recvBuff);

							recv(s,recvBuff,sizeof(recvBuff),0);
							sprintf(ap,"%s",recvBuff);

							recv(s,recvBuff,sizeof(recvBuff),0);
							sprintf(dni,"%s",recvBuff);

							recv(s,recvBuff,sizeof(recvBuff),0);
							sprintf(email,"%s",recvBuff);

							recv(s,recvBuff,sizeof(recvBuff),0);
							sscanf(recvBuff,"%d",&tlf);
							recv(s,recvBuff,sizeof(recvBuff),0);
							sscanf(recvBuff,"%d",&tipo_us);

							cli.setIdUser(id_user);
							cli.setUsername(u.getUsername());
							cli.setContrasenya(u.getContrasenya());
							cli.setTipoUser(u.getTipoUser());
							cli.setNombreCli(nom);
							cli.setApellidoCli(ap);
							cli.setDNICli(dni);
							cli.setEmailCli(email);
							cli.setTlfCli(tlf);
							cout<<"Tus vehiculos:"<<endl;
							recibirVehiculosDeCliente(s, recvBuff, sizeof(recvBuff));


							break;
						}

						//HASTA AQUI OK
						case '2':{
							cout<<"\nTRABAJOS REALIZADOS EN TUS VEHICULOS:\n";
							recibirTrabajosPorCliente(s, recvBuff, sizeof(recvBuff));
							break;
						}
						case '3':{
							opcion_serv = menu.menuServicios();
							sprintf(sendBuff,"%d",opcion_serv);
							send(s,sendBuff,strlen(sendBuff),0);
							cout<<"Elige en que coche desea realizar el servicio"<<endl;
							recibirVehiculosDeCliente(s, recvBuff, sizeof(recvBuff));
							char * matricula = Vehiculo::pedirMatricula();
							sprintf(sendBuff,matricula);
							send(s,sendBuff,strlen(sendBuff),0);
							recv(s,recvBuff,sizeof(recvBuff),0);
							sscanf(recvBuff,"%d",&enc);
							if(enc==1){
								char nom[20];
								nom[0] = '\0';
								n=recv(s,recvBuff,sizeof(recvBuff),0);
								recvBuff[n]='\0';
								sscanf(recvBuff,nom);
								cout<<"Gracias! El servicio "<<nom<<" se efectuara en el coche con matricula "<<matricula<<endl;


							}else{
								cout<<"La matricula no coincide con ninguno de tus vehiculos.\n";
							}
							break;

						}
						default:
							break;

						}


					}while(opcion_decisiones!='0');

				}else{ //end cli
					//EMPLEADO
					char bienvenida[100];
					opcion_taller = menu.menuTalleres();
					int opc_taller = opcion_taller - '\0';
					sprintf(sendBuff,"%c",opcion_taller); //Guardo en sendBuff lo que le quiero enviar al servidor
					send(s,sendBuff,strlen(sendBuff),0);
					recv(s,recvBuff,sizeof(recvBuff),0);
					sscanf(recvBuff,"%s",bienvenida);

					do{
						opcion_emp = menu.menuEmpleado();
						sprintf(sendBuff,"%c",opcion_emp); //Guardo en sendBuff lo que le quiero enviar al servidor
						send(s,sendBuff,strlen(sendBuff),0);

						switch(opcion_emp){
						case'0':
							break;
						case '1':{ //INVENTARIO
							cout<<"Cargando inventario... Todos los datos han sido importados correctamente!\n";
							//mostrarInventario();
							cout<<"mostrarInventario()\n";
							opcion_inv=menu.menuInventario();
							sprintf(sendBuff,"%c",opcion_inv); //Guardo en sendBuff lo que le quiero enviar al servidor
							send(s,sendBuff,strlen(sendBuff),0);
							do{
								switch(opcion_inv){
								case '0':
									break;
								case '1':{
									recv(s, recvBuff, sizeof(recvBuff), 0);
									sscanf(recvBuff, "%d", &id_maxInv);
									inv = Inventario::pedirInventario(opc_taller,id_maxInv);

									sprintf(sendBuff, "%d",inv.getIdInventario());
									send(s, sendBuff, strlen(sendBuff), 0);
									sprintf(sendBuff, "%d",inv.getIdTaller());
									send(s, sendBuff, strlen(sendBuff), 0);
									sprintf(sendBuff, "%s",inv.getMaterial());
									removeNewline(sendBuff);
									send(s, sendBuff, strlen(sendBuff), 0);
									sprintf(sendBuff, "%d",inv.getCantInv());
									send(s, sendBuff, strlen(sendBuff), 0);
									break;
								}
								case '2':{ //eliminar
									//mostrarInventario()

									cout<<"Introduce el ID del material que deseas eliminar: \n";
									cin>>opc_elim;
									cout<<"*Para eliminar pulsa 'X': *\n";
									cin>>equis_elim;
									sprintf(sendBuff, "%c",equis_elim);
									send(s, sendBuff, strlen(sendBuff), 0);
									if(equis_elim == 'x' || equis_elim == 'X'){
										sprintf(sendBuff, "%d",opc_elim);
										send(s, sendBuff, strlen(sendBuff), 0);
									}
									break;
								}
								}
							}while(opcion_inv!=0);
							break;

						}

						case '2':{ //REGISTRO DE SERVICIO
							char* dni = Cliente::pedirDni();

							removeNewline(dni);
							sprintf(sendBuff, "%s", dni);
							send(s, sendBuff, strlen(sendBuff), 0);

							recv(s, recvBuff, sizeof(recvBuff), 0);
							sscanf(recvBuff, "%d", &existe);

							std::cout << "existe: " << existe << std::endl;

							if(existe==1){
								cout<<"El cliente existe\n";
								recv(s, recvBuff, sizeof(recvBuff), 0);
								sscanf(recvBuff, "%d", &id_cli);
								cout<<id_cli<<endl;

							}else{
								cout<<"El cliente con el DNI "<<dni<<" no existe\nVAMOS A INTRODUCIR TUS DATOS: \n"<<endl;
								recv(s, recvBuff, sizeof(recvBuff), 0);
								sscanf(recvBuff, "%d", &id_maxUsu);

								user_new = Usuario::pedirUsuarioRegistro(id_maxUsu);

								sprintf(sendBuff, user_new.getUsername());
								removeNewline(sendBuff);
								send(s, sendBuff, strlen(sendBuff), 0);
								sprintf(sendBuff, user_new.getContrasenya());
								removeNewline(sendBuff);
								send(s, sendBuff, strlen(sendBuff), 0);
								sprintf(sendBuff, "%d",user_new.getTipoUser());
								send(s, sendBuff, strlen(sendBuff), 0);


							}
							delete[] dni;
							cout<<"INGRESAR TRABAJO:\n----------\n";
							char * matricula = Vehiculo::pedirMatricula();
							sprintf(sendBuff, matricula);
							send(s, sendBuff, strlen(sendBuff), 0);

							recv(s, recvBuff, sizeof(recvBuff), 0);
							sscanf(recvBuff, "%d", &enc);

							recv(s, recvBuff, sizeof(recvBuff), 0);
							sscanf(recvBuff, "%d", &id_maxTra);
							int id_user_temp, id_v_temp;

							if(enc==1){

								cout<<"El coche con matricula "<<matricula<<" ha sido encontrado\n";
								recv(s, recvBuff, sizeof(recvBuff), 0);
								sscanf(recvBuff, "%d", &id_user_temp);
								recv(s, recvBuff, sizeof(recvBuff), 0);
								sscanf(recvBuff, "%d", &id_v_temp);

							}else{
								cout<<"Este coche no esta registrado.\n";
								recv(s, recvBuff, sizeof(recvBuff), 0);
								sscanf(recvBuff, "%d", &id_maxV);

								v=Vehiculo::pedirVehiculo(id_maxV,id_cli);

								sprintf(sendBuff, "%d",v.getIdVehiculo());
								send(s, sendBuff, strlen(sendBuff), 0);
								sprintf(sendBuff, "%d",v.getIdCli());
								send(s, sendBuff, strlen(sendBuff), 0);

								sprintf(sendBuff, v.getNumSeguro());
								removeNewline(sendBuff);
								send(s, sendBuff, strlen(sendBuff), 0);
								sprintf(sendBuff, "%d",v.getAnyoFabricacion());
								send(s, sendBuff, strlen(sendBuff), 0);
								sprintf(sendBuff, v.getMatricula());
								removeNewline(sendBuff);
								send(s, sendBuff, strlen(sendBuff), 0);

								sprintf(sendBuff, v.getMarca());
								removeNewline(sendBuff);
								send(s, sendBuff, strlen(sendBuff), 0);
								sprintf(sendBuff, v.getModelo());
								removeNewline(sendBuff);
								send(s, sendBuff, strlen(sendBuff), 0);
								sprintf(sendBuff, "%d",v.getIdColor());
								send(s, sendBuff, strlen(sendBuff), 0);

								id_user_temp=v.getIdCli();
								id_v_temp = v.getIdVehiculo();
							}


							tra = Trabajo::pedirTrabajo(id_maxTra,id_user_temp,id_v_temp);


							sprintf(sendBuff, "%d",tra.getIdTrabajo());
							send(s, sendBuff, strlen(sendBuff), 0);
							sprintf(sendBuff, "%d",tra.getIdVehiculo());
							send(s, sendBuff, strlen(sendBuff), 0);
							sprintf(sendBuff, "%d",tra.getIdEmp());
							send(s, sendBuff, strlen(sendBuff), 0);

							sprintf(sendBuff, tra.getFechaTra());
							removeNewline(sendBuff);
							send(s, sendBuff, strlen(sendBuff), 0);

							sprintf(sendBuff, tra.getDescripcionTra());
							removeNewline(sendBuff);
							send(s, sendBuff, strlen(sendBuff), 0);
							Trabajo::imprimirTrabajo(tra);
							recv(s, recvBuff, sizeof(recvBuff), 0);
							sscanf(recvBuff, "%d", &id_maxReg);
							reg.setIdRegistro(id_maxReg);
							reg.setIdCliente(id_cli);
							reg.setIdTrabajo(tra.getIdTrabajo());
							reg.setFecha(tra.getFechaTra());

						break;}

						case '3':
							break;
						}


					}while(opcion_decisiones!='0');
				}//end emp
			} //end usu
			break;
		}//end 1
		case '2': break; //REGISTRO

		}//end 2
	}while(opcion_prin!='0');


	/*ACABA EL PROGRAMA DEL CLIENTE*/
	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();


	return 0;
}


