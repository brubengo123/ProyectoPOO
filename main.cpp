#include "Refugio.h"
#include "Coleccion.h"
#include "Excepciones.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class FinDeEntrada {};

template <typename T>
void mostrarCantidad(const Coleccion<T> &coleccion, const string &tipo) {
	cout << "Coleccion de " << tipo << ": " << cantidadDe(coleccion)
		 << " elemento(s).\n";
}

void demostrarColecciones() {
	Coleccion<int> edades;
	Coleccion<string> nombres;
	edades.agregar(3);
	edades.agregar(5);
	nombres.agregar("Max");
	nombres.agregar("Luna");
	mostrarCantidad(edades, "enteros");
	mostrarCantidad(nombres, "textos");
	cout << "Instancias de Coleccion<int>: "
		 << Coleccion<int>::cantidadInstancias() << "\n";
	cout << "Instancias de Coleccion<string>: "
		 << Coleccion<string>::cantidadInstancias() << "\n";
}

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
		if (cin.eof()) {
			throw FinDeEntrada();
		}
		cout << "Entrada invalida. Debe ingresar un numero.\n";
		limpiarEntrada();
	}
}

string leerTexto(const string &mensaje) {
	string valor;
	while (true) {
		cout << mensaje;
		if (getline(cin, valor) && !valor.empty()) {
			return valor;
		}
		if (cin.eof()) {
			throw FinDeEntrada();
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
		if (cin.eof()) {
			throw FinDeEntrada();
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
		 << "9. Buscar animal por indice (comienza en 0)\n"
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
	const Animal *animal = refugio(id);
	if (animal == nullptr) {
		cout << "No se encontro un animal con ese ID.\n";
		return;
	}
	animal->mostrarInfo();
}

void buscarAnimalPorIndice(const Refugio &refugio) {
	int indice = leerEntero("Indice del animal (comienza en 0): ");
	if (indice < 0) {
		throw IndiceInvalidoException(indice);
	}
	refugio[static_cast<size_t>(indice)]->mostrarInfo();
}

void registrarAdoptante(Refugio &refugio) {
	string nombre = leerTexto("Nombre: ");
	string telefono = leerTexto("Telefono: ");
	string correo = leerTexto("Correo: ");
	string tipoVivienda = leerTexto("Tipo de vivienda: ");
	refugio.registrarAdoptante(nombre, telefono, correo, tipoVivienda);
}

void gestionarSolicitud(Refugio &refugio) {
	cout << "1. Crear solicitud\n"
		 << "2. Confirmar solicitud\n"
		 << "3. Cancelar solicitud\n";
	int accion = leerEntero("Seleccione una accion: ");

	if (accion == 1) {
		int idAdoptante = leerEntero("ID del adoptante: ");
		int idAnimal = leerEntero("ID del animal: ");
		int idSolicitud = refugio.crearSolicitud(idAdoptante, idAnimal);
		if (idSolicitud == 0) {
			cout << "No se pudo crear la solicitud. Verifique los IDs y la disponibilidad.\n";
		} else {
			cout << "Solicitud creada con ID: " << idSolicitud << "\n";
		}
		return;
	}

	int idSolicitud = leerEntero("ID de la solicitud: ");
	bool resultado = false;
	if (accion == 2) {
		resultado = refugio.confirmarSolicitud(idSolicitud);
	} else if (accion == 3) {
		resultado = refugio.cancelarSolicitud(idSolicitud);
	} else {
		cout << "Accion invalida.\n";
		return;
	}

	cout << (resultado ? "Operacion realizada correctamente.\n"
	                   : "No se pudo realizar la operacion.\n");
}

void devolverAnimal(Refugio &refugio) {
	int idAnimal = leerEntero("ID del animal a devolver: ");
	if (refugio.devolverAnimal(idAnimal)) {
		cout << "El animal ahora esta disponible nuevamente.\n";
	} else {
		cout << "No se pudo devolver el animal. Verifique el ID y su estado.\n";
	}
}

int main() {
	Refugio refugio;
	int opcion;

	do {
		mostrarMenu();
		try {
			opcion = leerEntero("Seleccione una opcion: ");
		} catch (const FinDeEntrada &) {
			cout << "\nFin de la entrada. Saliendo del sistema...\n";
			break;
		}
		cout << '\n';

		try {
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
			registrarAdoptante(refugio);
			break;
		case 5:
			buscarAnimal(refugio);
			break;
		case 6:
			gestionarSolicitud(refugio);
			break;
		case 7:
			devolverAnimal(refugio);
			break;
		case 8:
			refugio.listarAdoptantes();
			refugio.listarSolicitudes();
			break;
		case 9:
			buscarAnimalPorIndice(refugio);
			break;
		case 0:
			cout << "Saliendo del sistema...\n";
			break;
		default:
			cout << "Opcion invalida.\n";
		}
		} catch (const FinDeEntrada &) {
			cout << "\nFin de la entrada. Saliendo del sistema...\n";
			break;
		} catch (const IdDuplicadoException &ex) {
			cout << "Error de ID: " << ex.what() << "\n";
		} catch (const AnimalNoDisponibleException &ex) {
			cout << "Error de disponibilidad: " << ex.what() << "\n";
		} catch (const IndiceInvalidoException &ex) {
			cout << "Error de indice: " << ex.what() << "\n";
		} catch (const out_of_range &ex) {
			cout << "Error de rango: " << ex.what() << "\n";
		} catch (const exception &ex) {
			cout << "Error: " << ex.what() << "\n";
		}
	} while (opcion != 0);

	return 0;
}
