# Descripción general del proyecto

## Trabajo integrador POO

### Integrantes
- Susino Vogler Bruno
- Menardi Luca

### Objetivo del sistema
Creamos un sistema para un refugio de animales que cuenta con las funciones básicas para su manejo.

Decidimos crear un diseño claro, ordenado y fácil de entender para que el programa sea intuitivo y sencillo de usar.

Las instrucciones de uso se encuentran en el archivo llamado "Instrucciones para correr el programa.md".

---

## Funcionalidades principales

El sistema permite:
- Registrar perros.
- Registrar gatos.
- Registrar adoptantes.
- Crear solicitudes de adopción.
- Confirmar o cancelar solicitudes.
- Devolver animales al estado disponible.
- Listar animales y adoptar.

---

## Caso de uso principal

### 1) Registrar un perro
Ejecutar el programa y elegir la opción:

- 1: Registrar perro

Ingresar:
- Nombre: Max
- Edad: 3
- Estado de salud: Saludable
- Raza: Labrador
- Tamaño: Mediano

Resultado esperado:
- Se registra el perro correctamente.
- Se muestra un mensaje similar a: "Perro registrado exitosamente con ID: 101".

### 2) Registrar un adoptante
Elegir la opción:

- 4: Registrar adoptante

Ingresar:
- Nombre: Ana
- Telefono: 1122334455
- Correo: ana@gmail.com

Resultado esperado:
- Se registra el adoptante con un ID.
- Se muestra un mensaje similar a: "Adoptante registrado exitosamente con ID: 1".

### 3) Crear una solicitud de adopción
Elegir la opción:

- 6: Crear, confirmar o cancelar solicitud de adopcion

Luego seleccionar:

- 1: Crear solicitud

Ingresar:
- ID del adoptante: el ID que devolvió el registro del adoptante
- ID del animal: el ID del perro registrado

Resultado esperado:
- Se crea la solicitud correctamente.
- Se muestra un ID de solicitud, por ejemplo: "Solicitud creada con ID: 1".

### 4) Confirmar la solicitud
Volver al menú y elegir nuevamente:

- 6: Crear, confirmar o cancelar solicitud de adopcion

Seleccionar:

- 2: Confirmar solicitud

Ingresar:
- ID de la solicitud: el ID generado en el paso anterior

Resultado esperado:
- La solicitud queda confirmada.
- El animal pasa a no estar disponible.
- Se muestra el mensaje: "Operacion realizada correctamente."

### 5) Salir del sistema
Elegir la opción:

- 0: Salir del sistema

---


