#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include <cstdlib>

using namespace std;

class Adyacente{
	
	long int codigo;
		char nombre[35];
		char modalidad[20];
		short int semestres;
		Adyacente *sig;
	
	public:
		
		
		void CrearCabA(Adyacente *&cab,long int codigo, char nombre[],char modalidad[],short int semestres){
			cab=new Adyacente;
			cab->codigo=codigo;
			strcpy(cab->nombre,nombre);
			strcpy(cab->modalidad,modalidad);
			cab->semestres=semestres;
			cab->sig=NULL;
		}
		void AgregarNodoA(Adyacente *&cab, long int codigo, char nombre[],char modalidad[],short int semestres){
			Adyacente *aux=cab;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=new Adyacente;
			aux->sig->codigo=codigo;
			strcpy(aux->sig->nombre,nombre);
			strcpy(aux->sig->modalidad,modalidad);
			aux->sig->semestres=semestres;
			aux->sig->sig=NULL;
		}
		void CrearAdyacente(Adyacente *&cab){
			char nombre[35];
	    	char modalidad[20];
	    	short int semestre;
	    	long int codigo=666;
			cout<<"  INGRESE EL CODIGO DE LA CARRERA \n";
			while(codigo>0){
				cout<<"  CODIGO DE LA CARRERA: ";
				cin>>codigo;
				if(codigo>0){
					if(cab==NULL){
						fflush(stdin);
						cout<<"  DIGITE EL NOMBRE DEL PROGRAMA: ";
						cin.getline(nombre,35,'\n');
						fflush(stdin);
						cout<<"  DIGITE LA MODALIDAD: ";
						cin.getline(modalidad,20,'\n');
						fflush(stdin);
						cout<<"  DIGITE LA CANTIDAD DE SEMESTRES: ";
						cin>>semestres;
						CrearCabA(cab,codigo,nombre,modalidad,semestres);
						cout<<" "<<endl;
					}else{
						fflush(stdin);
						cout<<"  DIGITE EL NOMBRE DE LA CARRERA: ";
						cin.getline(nombre,35,'\n');
						fflush(stdin);
						cout<<"  DIGITE LA MODALIDAD: ";
						cin.getline(modalidad,20,'\n');
						fflush(stdin);
						cout<<"  DIGITE LA CANTIDAD DE SEMESTRES: ";
						cin>>semestres;
						AgregarNodoA(cab,codigo,nombre,modalidad,semestres);
						cout<<" "<<endl;
					}		
				}
			}
		}
		
		void mostrarAdy(Adyacente *cab){
			cout<<" "<<endl;
			cout<<"  CODIGO = "<<cab->codigo<<endl;
			cout<<"  NOMBRE DEL PROGRAMA = "<<cab->nombre<<endl;
			cout<<"  MODALIDAD = "<<cab->modalidad<<endl;
			cout<<"  CANTIDAD DE SEMESTRES = "<<cab->semestres<<endl;
		}
		
		void MostrarAd(Adyacente *cab){
			Adyacente *aux=cab;
			while(aux){
				mostrarAdy(aux);
				aux=aux->sig;
			}
		}
	
		void eliminarPro(Adyacente *&cab){
		Adyacente *aux,*aux1;
    	long int codigo;
		aux1=aux=cab;
    	cout<<"  INGRESE EL CODIGO DEL PROGRAMA QUE DESEA ELIMINAR: ";
       	cin>>codigo;
    	while(aux&&codigo!=cab->codigo) {
      		aux1=aux;
      		aux=aux->sig;
    	}
    	if(codigo==aux->codigo&&aux){
    		if(aux->sig==NULL){
        		aux1->sig=NULL;
      		}else{
      			if(aux==cab&&aux->sig) {
          			cab=cab->sig;
        		}else{
        			aux1->sig=aux->sig;
				}
			}
			cout<<"  PROGRAMA ELIMINADA CON EXITO"<<endl;
			delete aux;
		}else{
			cout<<"  PROGRAMA NO ENCONTRADA"<<endl;
		}
	}
	
};

class Vertice{
	
	long int nit;
	char nombreu[35];
	char caracter[25];
	
	Vertice *sig;
	Adyacente *frente;
	
	public:
	void CrearCabV(Vertice *&cabVe,long int nit,char nombreu[],char caracter[]){
		cabVe=new Vertice;
		cabVe->nit=nit;
		strcpy(cabVe->nombreu,nombreu);
		strcpy(cabVe->caracter,caracter);
		cabVe->frente=NULL;
		cabVe->sig=NULL;
	}
	void AgregarNodoVer(Vertice *&cabVe,long int nit,char nombreu[],char caracter[]){
		Vertice *aux=cabVe;
		while(aux->sig!=NULL){
			aux=aux->sig;			
		}
		aux->sig=new Vertice;
		aux=aux->sig;
		aux->nit=nit;
		strcpy(aux->nombreu,nombreu);
		strcpy(aux->caracter,caracter);
		aux->sig=NULL;
		aux->frente=NULL;
	}
	void crearVertice(Vertice *&cabVe){
		Vertice *aux;
		long int nit=666;
		char nombreu[35];
		char caracter[25];
		cout<<"  INGRESE LOS DATOS DE LA UNIVERSIDAD A REGISTRAR \n";
		while(nit>0){
				cout<<"  NIT DE LA UNIVERSIDAD: ";
				cin>>nit;
				if(nit>0){	
					/*if(cabVe->nit==nit){
						cout<<"  NIT REPETIDO INTENTE DE NUEVO"<<endl;
						system("cls");
						crearVertice(cabVe);
					}*/
					if(cabVe==NULL){
						fflush(stdin);
						cout<<"  DIGITE EL NOMBRE DE LA UNIVERSIDAD: ";
						cin.getline(nombreu,35,'\n');
						fflush(stdin);
						cout<<"  DIGITE EL CARACTER DE LA UNIVERSIDAD: ";
						cin.getline(caracter,25,'\n');
						cout<<" "<<endl;
						CrearCabV(cabVe,nit,nombreu,caracter);
					}else{
						if(nit==cabVe->nit){
							cout<<"  NIT REPETIDO INTENTE DE NUEVO"<<endl;
							cout<<" "<<endl;
						}else{
							fflush(stdin);
							cout<<"  DIGITE EL NOMBRE DE LA UNIVERSIDAD: ";
							cin.getline(nombreu,35,'\n');
							fflush(stdin);
							cout<<"  DIGITE EL CARACTER DE LA UNIVERSIDAD: ";
							cin.getline(caracter,25,'\n');
							cout<<" "<<endl;
							AgregarNodoVer(cabVe,nit,nombreu,caracter);
						}
					}		
				}
			}
	}
	
	
	void AgregarNodoAdyacente(Vertice *&cabVe,long int nit,char nombreu[],char caracter[]){
			Vertice *aux=cabVe;
			Adyacente A1;
			long int nit1;
			cout<<"  INGRESE EL NIT DE LA UNIVERSIDAD AL CUAL LE AÑADIRA EL PROGRAMA: ";
            cin>>nit1;
			while(aux->nit!=nit1){
				aux=aux->sig;
			}
			if(aux->nit==nit1){
				cout<<"  AGREGANDO PROGRAMA A LA UNIVERSIDAD: "<<aux->nombreu<<endl;
				A1.CrearAdyacente(aux->frente);
			}else{
				cout<<"  LA UNIVERSIDAD NO EXISTE: "<<endl;
			}
	}
			
			/*while(aux->nit!=nit1){
				aux=aux->sig;
			}
			if(aux->nit==nit1){
				cout<<"  AGREGANDO PROGRAMA A LA UNIVERSIDAD: "<<aux->nombreu<<endl;
				A1.CrearAdyacente(aux->frente);
			}else{
				AgregarNodoAdyacente(cabVe,nit,nombreu,caracter);
			}*/
	
	
	void mostrarVer(Vertice *cabVe){
		cout<<" "<<endl;
		cout<<"  NIT DE LA UNIVERSIDAD = "<<cabVe->nit<<endl;
		cout<<"  NOMBRE DE LA UNIVERSIDAD = "<<cabVe->nombreu<<endl;
		cout<<"  CARACTER = "<<cabVe->caracter<<endl;
	}
	
	void MostrarVer(Vertice *cabVe){
		Vertice *aux=cabVe;
		cout<<"  LAS UNIVERSIDADES REGISTRADAS SON\n";
		while(aux){
			mostrarVer(aux);
			aux=aux->sig;
		}
	}
	
	void MostrarGrafo(Vertice *cabVe){
		Vertice *aux=cabVe;
		Adyacente A1;
		while(aux){
			if(aux->frente!=NULL){
				mostrarVer(aux);
				cout<<" "<<endl;
				cout<<"  LOS PROGRAMAS DE LA UNIVERSIDAD SON LOS SIGUIENTES"<<endl;
					A1.MostrarAd(aux->frente);	
			}else{
				if(aux->frente==NULL){
					cout<<"  LA UNIVERSIDAD "<<aux->nombreu<<" NO TIENE PROGRAMAS REGISTRADOS"<<endl;
				}
			}
			cout<<"------------------------------------------------------------------------------------------------------------- "<<endl;
			aux=aux->sig;		
		}
	}
	
	void mostrarProgramas(Vertice *cabVe){
		Vertice *aux=cabVe;
		Adyacente A1;
		while(aux){
			if(aux->frente!=NULL){
				cout<<" "<<endl;
				cout<<"  LOS PROGRAMAS REGISTRADOS EN EL GRAFO SON"<<endl;
					A1.MostrarAd(aux->frente);	
			}else{
				if(aux->frente==NULL){
					cout<<"  EL GRAFO NO TIENE PROGRAMAS REGISTRADOS"<<endl;
				}
			}
			cout<<"------------------------------------------------------------------------------------------------------------- "<<endl;
			aux=aux->sig;		
		}
	}
	
	
	void buscarUniversidad(Vertice *cabVe){
		Adyacente A1;
		int b = 0;
	    int busqueda;
	    Vertice *aux=cabVe;
	    cout<<"  INGRESE EL NIT DE LA UNIVERSIDAD QUE DESEA BUSCAR: ";
	    cin >>busqueda;
	    while(aux && !b){
      		if(aux->nit==busqueda) {
        		b=1;
      		}else{
        		aux=aux->sig;
      		}
		}
		while(aux){
			if(b){
	      		cout << "  LA UNIVERSIDAD EXISTE " <<endl;
	      		cout<<" "<<endl;
				cout<<"  NIT DE LA UNIVERSIDAD = "<<cabVe->nit<<endl;
				cout<<"  NOMBRE DE LA UNIVERSIDAD = "<<cabVe->nombreu<<endl;
				cout<<"  CARACTER = "<<cabVe->caracter<<endl;
				cout<<"  LOS PROGRAMAS REGISTRADOS EN LA UNIVERSIDAD SON"<<endl;						
	    	}else{
	      		cout << "  LA UNIVERSIDAD NO EXISTE" << endl;
	    	}
			aux=aux->sig;	
		}
	}
	
	/*void buscarPro(Vertice *cabVe,Adyacente *cab){
			Vertice *aux=cabVe;
			int b=0;
		    int busqueda;
		    Adyacente A1,*aux1=cab;
		    cout<<"  INGRESE EL CODIGO DEL PROGRAMA QUE DESEA BUSCAR: ";
		    cin>>busqueda;
		    while(aux&&aux->frente){
      			if(aux->frente!=NULL&&aux->frente->codigo==busqueda){
	        		A1.mostrarAdy(aux->frente);
	        		cout<<" "<<endl;
	        		cout<<"  SE ENCUENTRA DISPONIBLE EN LAS SIGUIENTES UNIVERSIDADES"<<endl;
	        		cout<<" "<<endl;
					cout<<"  NIT DE LA UNIVERSIDAD = "<<aux->nit<<endl;
					cout<<"  NOMBRE DE LA UNIVERSIDAD = "<<aux->nombreu<<endl;
					cout<<"  CARACTER = "<<aux->caracter<<endl;
					cout<<"------------------------------------------------------------------------------------------------------- "<<endl;
	      		}else{
	      			//cout<<"  NO SE ENCUENTRA REGISTRADO EL PROGRAMA"<<endl;
				}
				aux1=aux->frente->sig;
				aux=aux->sig;
			}
		}*/
		
	buscarCarac(Vertice *cabVe){
		int b = 0;
	    char busqueda[25];
	    Vertice *aux=cabVe;
	    fflush(stdin);
		cout<<"  DIGITE EL CARACTER DE LA UNIVERSIDAD: ";
		cin.getline(busqueda,25,'\n');
		cout << "  LAS UNIVERSIDADES SON" <<endl;
	    while(aux && !b){
      		if(strcmp(busqueda,aux->caracter)==0) {
        		cout<<" "<<endl;
				cout<<"  NIT DE LA UNIVERSIDAD = "<<aux->nit<<endl;
				cout<<"  NOMBRE DE LA UNIVERSIDAD = "<<aux->nombreu<<endl;
				cout<<"  CARACTER = "<<aux->caracter<<endl;
      		}
      		aux=aux->sig;
		}
		/*while(aux){
			if(b){
	      		cout << "  LAS UNIVERSIDADES SON" <<endl;
	      		cout<<" "<<endl;
				cout<<"  NIT DE LA UNIVERSIDAD = "<<cabVe->nit<<endl;
				cout<<"  NOMBRE DE LA UNIVERSIDAD = "<<cabVe->nombreu<<endl;
				cout<<"  CARACTER = "<<cabVe->caracter<<endl;
		    	}else{
		      		cout << "  NO EXISTEN UNIVERSIDADES DE CARACTER PUBLICO" << endl;
		    }
			aux=aux->sig;	
		}*/
		
	}
	
/*	void buscarMo(Vertice *cabVe,Adyacente *cab){
			Vertice *aux=cabVe;
			int b=0;
		    char busqueda[25];
		    Adyacente A1,*aux1=cab;
		    fflush(stdin);
			cout<<"  DIGITE LA MODALIDAD DEL PROGRAMA: ";
			cin.getline(busqueda,25,'\n');
		    while(aux&&aux->frente){
      			if(aux->frente!=NULL&&strcmp(busqueda,aux->frente->modalidad)==0){
	        		A1.mostrarAdy(aux->frente);
	        		cout<<" "<<endl;
	        		cout<<"  SE ENCUENTRA DISPONIBLE EN LAS SIGUIENTES UNIVERSIDADES."<<endl;
	        		cout<<" "<<endl;
					cout<<"  NIT DE LA UNIVERSIDAD = "<<aux->nit<<endl;
					cout<<"  NOMBRE DE LA UNIVERSIDAD = "<<aux->nombreu<<endl;
					cout<<"  CARACTER = "<<aux->caracter<<endl;
					cout<<"------------------------------------------------------------------------------------------------------- "<<endl;
	      		}else{
	      			//cout<<"  NO SE ENCUENTRA REGISTRADO EL PROGRAMA"<<endl;
				}
				aux1=aux->frente->sig;
				aux=aux->sig;
			}
		}*/
	
	void eliminarUni(Vertice *&cabVe,long int nit){
		Vertice *aux,*aux1;
    	aux1=aux=cabVe;
    	while(aux&&nit!=aux->nit) {
      		aux1=aux;
      		aux=aux->sig;
    	}
    	if(nit==aux->nit&&aux){
    		if(aux->sig==NULL){
        		aux1->sig=NULL;
      		}else{
      			if(aux==cabVe&&aux->sig) {
          			cabVe=cabVe->sig;
        		}else{
        			aux1->sig=aux->sig;
				}
			}
			cout<<"  UNIVERSIDAD ELIMINADA CON EXITO"<<endl;
			delete aux;
		}else{
			cout<<"  UNIVERSIDAD NO ENCONTRADA"<<endl;
		}
	}
	
	
	void eliminar(Vertice *cabVe){
		Adyacente A1, *cab=NULL;
		int b = 0;
	    int busqueda;
	    Vertice *aux=cabVe;
	    cout<<"  INGRESE EL NIT DE LA UNIVERSIDAD QUE DESEA BUSCAR: ";
	    cin >>busqueda;
	    while(aux && !b){
      		if(aux->nit==busqueda) {
        		b=1;
      		}else{
        		aux=aux->sig;
      		}
		}
		while(aux){
			if(b){
				if(aux->frente!=NULL){
					A1.eliminarPro(aux->frente);
				}else{
					cout << "  LA UNIVERSIDAD NO TIENE PROGRAMAS" << endl;
				}						
	    	}else{
	      		cout << "  LA UNIVERSIDAD NO EXISTE" << endl;
	    	}
			aux=aux->sig;	
		}
	}
	
	
};


int main(){
	
	Adyacente objA,*cab=NULL;
	Vertice objV,*cabVe=NULL;
	
	char nombreu[35];
	char caracter[25];
	long int nit;
	long int codigo;
	int opcion;
	do{
		system("cls");
		cout<<endl;
		cout<<"  > SIMULADOR DE UNIVERSIDAD <"<<endl;
		cout<<endl;
		cout<<"  [1]: AGREGAR UNIVERSIDAD"<<endl;
		cout<<"  [2]: AGREGAR PROGRAMA"<<endl;
		cout<<"  [3]: MOSTRAR GRAFO"<<endl;
		cout<<"  [4]: BUSCAR UNIVERSIDAD"<<endl;
		cout<<"  [5]: BUSCAR PROGRAMA"<<endl;
		cout<<"  [6]: MOSTRAR LISTA DE UNIVERSIDADES DENTRO DEL GRAFO"<<endl;
		cout<<"  [7]: MOSTRAR LISTA DE PROGRAMAS DENTRO DEL GRAFO"<<endl;
		cout<<"  [8]: BUSCAR TIPO DE UNIVERSIDADES"<<endl;
		cout<<"  [9]: BUSCAR POR MODALIDAD DE PROGRAMA"<<endl;
		cout<<"  [10]: ELIMINAR UNIVERSIDAD"<<endl;
		cout<<"  [11]: ELIMINAR PROGRAMA"<<endl;
		cout<<"  [12]: SALIR"<<endl;
		cout<<endl;
		cout<<"  DIGITE OPCION: ";
		cin>>opcion;
				
		if(opcion==1){
			system("cls");
			objV.crearVertice(cabVe);	
		}
				
		if(opcion==2){
			system("cls");
			objV.AgregarNodoAdyacente(cabVe,nit,nombreu,caracter);
		}
		if(opcion==3){
			system("cls");
			objV.MostrarGrafo(cabVe);
		}
		if(opcion==4){
			system("cls");
			objV.buscarUniversidad(cabVe);
		}
		if(opcion==5){
			system("cls");
			//objV.buscarPro(cabVe,cab);
		}
		if(opcion==6){
			system("cls");
			objV.MostrarVer(cabVe);
		}
		if(opcion==7){
			system("cls");
			objV.mostrarProgramas(cabVe);		
		}
		if(opcion==8){
			system("cls");	
			objV.buscarCarac(cabVe);
				
		}
		if(opcion==9){
			system("cls");	
			//objV.buscarMo(cabVe,cab);
		}
		if(opcion==10){
			system("cls");	
			cout<<"  INGRESE EL NIT DE LA UNIVERSIDAD: ";
       		cin>>nit;
        	objV.eliminarUni(cabVe,nit);
		}
		if(opcion==11){
			system("cls");	
			objV.eliminar(cabVe);	
		}		
		cout<<endl<<endl<<"  ";
		system("pause");
		}while(opcion!=12);
	return 0;
}
