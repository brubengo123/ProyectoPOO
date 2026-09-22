#include "Refugio.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void limpiarEntrada() {
	if (cin.fail()) {
		cin.clear();
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int leerEntero(const string &mensaje) {
	int valor;
	while (true) {
		cout << mensaje;
		if (cin >> valor) {
			limpiarEntrada();
			return valor;
		}
		cout << "Entrada invalida. Debe ingresar un numero.\n";
		limpiarEntrada();
	}
}

string leerTexto(const string &mensaje) {
	string valor;
	while (true) {
		cout << mensaje;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		if (getline(cin, valor) && !valor.empty()) {
			return valor;
		}
		cout << "Entrada invalida. Debe ingresar texto.\n";
		limpiarEntrada();
	}
}

bool leerSiNo(const string &mensaje) {
	char respuesta;
	while (true) {
		cout << mensaje << " (s/n): ";
		cin >> ws;
		if (cin >> respuesta) {
			if (respuesta == 's' || respuesta == 'S') {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return true;
			}
			if (respuesta == 'n' || respuesta == 'N') {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return false;
			}
		}
		cout << "Respuesta invalida. Use s o n.\n";
		limpiarEntrada();
	}
}

void mostrarMenu() {
	cout << "\n===== MENU DEL REFUGIO =====\n"
		 << "1. Registrar perro\n"
		 << "2. Registrar gato\n"
		 << "3. Listar animales y filtrar disponibles\n"
		 << "4. Registrar adoptante\n"
		 << "5. Buscar animal por ID\n"
		 << "6. Crear, confirmar o cancelar solicitud de adopcion\n"
		 << "7. Devolver un animal al estado disponible\n"
		 << "8. Mostrar solicitudes e historial de adopciones\n"
		 << "0. Salir\n";
}

void registrarPerro(Refugio &refugio) {
	string nombre = leerTexto("Nombre: ");
	int edad = leerEntero("Edad: ");
	string salud = leerTexto("Estado de salud: ");
	string raza = leerTexto("Raza: ");
	string tamano = leerTexto("Tamano: ");
	refugio.registrarPerro(nombre, edad, salud, raza, tamano);
}

void registrarGato(Refugio &refugio) {
	string nombre = leerTexto("Nombre: ");
	int edad = leerEntero("Edad: ");
	string salud = leerTexto("Estado de salud: ");
	string colorPelaje = leerTexto("Color del pelaje: ");
	bool esDeInterior = leerSiNo("¿Es de interior? (s = adentro, n = afuera)");
	refugio.registrarGato(nombre, edad, salud, colorPelaje, esDeInterior);
}

void buscarAnimal(const Refugio &refugio) {
	int id = leerEntero("ID del animal: ");
	Animal *animal = refugio.buscarAnimalPorId(id);
	if (animal == nullptr) {
		cout << "No se encontro un animal con ese ID.\n";
		return;
	}
	animal->mostrarInfo();
}

void registrarAdopcion(Refugio &refugio) {
	int id = leerEntero("ID del animal a adoptar: ");
	Animal *animal = refugio.buscarAnimalPorId(id);
	if (animal == nullptr) {
		cout << "No se encontro un animal con ese ID.\n";
		return;
	}
	if (!animal->isDisponible()) {
		cout << "El animal ya fue adoptado.\n";
		return;
	}
	animal->setDisponible(false);
	cout << "Adopcion registrada correctamente.\n";
}

int main() {
	Refugio refugio;
	int opcion;

	do {
		mostrarMenu();
		opcion = leerEntero("Seleccione una opcion: ");
		cout << '\n';

		switch (opcion) {
		case 1:
			registrarPerro(refugio);
			break;
		case 2:
			registrarGato(refugio);
			break;
		case 3: {
			bool soloDisponibles = leerSiNo("Desea filtrar solo animales disponibles");
			if (soloDisponibles) {
				refugio.listarAnimalesDisponibles();
			} else {
				refugio.listarAnimales();
			}
			break;
		}
		case 4:
			cout << "Funcion para registrar adoptante en desarrollo.\n";
			break;
		case 5:
			buscarAnimal(refugio);
			break;
		case 6:
			cout << "Funcion para crear, confirmar o cancelar solicitud de adopcion en desarrollo.\n";
			break;
		case 7:
			cout << "Funcion para devolver un animal al estado disponible en desarrollo.\n";
			break;
		case 8:
			cout << "Funcion para mostrar solicitudes e historial de adopciones en desarrollo.\n";
			break;
		case 0:
			cout << "Saliendo del sistema...\n";
			break;
		default:
			cout << "Opcion invalida.\n";
		}
	} while (opcion != 0);

	return 0;
}
