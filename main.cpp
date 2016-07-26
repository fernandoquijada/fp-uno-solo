/*
# |----------------------|
# | Juan Gomez Tarraga   |
# |Fernando Quijada Diaz |
# |----------------------|
*/

#include "unosolo.h"
#include <iostream>
#include <string>

int main() {
	int opcion, numMovimientos;
	tJuego juego;
	bool carga, jugar;
	string nombre;
	char opcionGuardar;

	jugar = menuPrincipal();

	while (jugar) {
		opcion = menuPartida();
		if (opcion == 1) { // Para escoger tablero.
			cout << "Escriba el nombre del tablero: ";
			cin >> nombre;
			carga = cargar(juego, nombre); // Carga el archivo nombrado.
			if (carga) {
				partida(juego); // Funcion que lleva el control de la partida.
				cout << "Desea guardar la partida? (S/N): ";
				cin >> opcionGuardar;
				if (opcionGuardar == 'S' || opcionGuardar == 's') {
					cout << "Introduzca nombre de archivo para guardar partida: ";
					cin >> nombre;
					guardar(juego, nombre);
				}
			}
			else
				cout << "No se pudo abrir el archivo :( " << endl;
		}
		else { // Tablero aleatorio.
			iniciarTablero(juego);
			fijarMeta(juego);
			cout << "Introduzca el numero de movimientos: ";
			cin >> numMovimientos;
			generarTablero(juego, numMovimientos);
			cout << "Desea guardar la partida? (S/N): ";
			cin >> opcionGuardar;
			if (opcionGuardar == 'S' || opcionGuardar == 's') {
				cout << "Introduzca nombre de archivo para guardar partida: ";
				cin >> nombre;
				guardar(juego, nombre);
			}
		}
		jugar = menuPrincipal();
	}
	return 0;
}
