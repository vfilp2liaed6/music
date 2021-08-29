#include <iostream>

using namespace std;

struct nodo{
	char dato;
	nodo* siguiente;
} *primero, *ultimo;

void insertarSong(char);
void avanzarSong();
char mostrarSong();

int main(){
	char a = 'a', b = 'b', c = 'c', d = 'd', e = 'e';
    insertarSong(c);
    insertarSong(d);
    insertarSong(e);
    insertarSong(a);
    insertarSong(b);

	int opcionMenu = 0;
	do
	{
		cout << "\n|------------------|";
		cout << "\n|   *   MP3   *    |";
		cout << "\n|------------------|";
		cout << "\n| 1. Escuchando    |";
		cout << "\n| 2. Siguiente     |";
		cout << "\n| 3. Salir         |";
		cout << "\n|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcionMenu;
		switch(opcionMenu){
		case 1:
			cout << "\n\n REPRODUCIENDO: \n\n";
            cout << "cancion "<< mostrarSong() <<endl;
            
			break;
		case 2:
			cout << "\n\n ADELANTANDO \n\n";
			avanzarSong();
			break;
		case 3:
			cout << "\n\n Saliendo...\n\n";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcionMenu != 3);
	
	return 0;
}
				
 
void insertarSong(char n){
	nodo* nuevo = new nodo();
	nuevo->dato = n; 
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
}

void avanzarSong(){
    nodo* S = new nodo();
    S = primero;
    primero = S->siguiente;
    ultimo = S;
}

char mostrarSong(){
	char song;
	if(primero!=NULL){
			song = primero->dato;
	}else{
		cout << "\n No hay canciones...\n\n";
	}
    return song;
}
