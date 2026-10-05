# Pruebas del sistema de refugio


## 1) Casos de prueba de situaciones válidas

### Caso 1: Registrar un perro correctamente
- Opción: 1
- Datos ingresados:
  - Nombre: Max
  - Edad: 3
  - Estado de salud: Saludable
  - Raza: Labrador
  - Tamaño: Mediano
- Resultado esperado:
  - El perro se registra correctamente.
  - Se asigna un ID válido.
  - Se muestra el mensaje de confirmación.

### Caso 2: Registrar un gato correctamente
- Opción: 2
- Datos ingresados:
  - Nombre: Luna
  - Edad: 2
  - Estado de salud: Bueno
  - Color del pelaje: Blanco
  - ¿Es de interior? (s/n): s
- Resultado esperado:
  - El gato se registra correctamente.
  - El animal queda guardado en el refugio.

### Caso 3: Registrar un adoptante correctamente
- Opción: 4
- Datos ingresados:
  - Nombre: Ana
  - Telefono: 1122334455
  - Correo: ana@mail.com
- Resultado esperado:
  - El adoptante queda registrado con un ID.
  - Se muestra el mensaje de registro exitoso.

### Caso 4: Crear solicitud de adopción válida
- Opción: 6
- Subopción: 1
- Datos ingresados:
  - ID del adoptante: 1
  - ID del animal: 101
- Resultado esperado:
  - La solicitud se crea correctamente.
  - Se devuelve un ID de solicitud válido.

### Caso 5: Confirmar solicitud de adopción
- Opción: 6
- Subopción: 2
- Datos ingresados:
  - ID de la solicitud: 1
- Resultado esperado:
  - La solicitud pasa a estado Confirmada.
  - El animal queda marcado como no disponible.
  - Se muestra un mensaje de operación realizada correctamente.

### Caso 6: Listar animales disponibles
- Opción: 3
- Respuesta: s
- Resultado esperado:
  - Solo se muestran los animales disponibles.
  - Los animales no disponibles no deben aparecer.

---

## 2) Casos de prueba de error

### Caso 7: Edad negativa
- Opción: 1
- Datos ingresados:
  - Nombre: Coco
  - Edad: -2
  - Estado de salud: Bueno
  - Raza: Schnauzer
  - Tamaño: Chiquito
- Resultado esperado:
  - El programa debería rechazar la edad inválida.
  - En la práctica, actualmente no valida este caso y puede aceptar el dato.

### Caso 8: Entrada no numérica en un campo numérico
- Opción: 5
- Datos ingresados:
  - ID del animal: abc
- Resultado esperado:
  - El programa debe mostrar: "Entrada invalida. Debe ingresar un numero."

### Caso 9: ID inexistente
- Opción: 6
- Subopción: 1
- Datos ingresados:
  - ID del adoptante: 999
  - ID del animal: 999
- Resultado esperado:
  - La solicitud no se crea.
  - Se muestra: "No se pudo crear la solicitud. Verifique los IDs y la disponibilidad."

### Caso 10: Solicitud de un animal ya confirmado
- Opción: 6
- Subopción: 1
- Datos ingresados:
  - ID del adoptante: 1
  - ID del animal: 101
- Resultado esperado:
  - El sistema debe rechazar la solicitud porque el animal ya no está disponible.
  - Se debe mostrar un error de disponibilidad.

---

## 3) Pruebas de copia profunda

### Caso 14: Copiar un refugio con animales y adoptantes
- Objetivo:
  - Verificar que la copia del objeto Refugio no comparte punteros ni referencias con el original.
- Procedimiento:
  1. Registrar varios animales.
  2. Registrar varios adoptantes.
  3. Crear solicitudes de adopción.
  4. Copiar el refugio usando el constructor de copia o el operador de asignación.
- Resultado esperado:
  - Los datos del refugio copiado deben ser iguales a los del original.
  - Las modificaciones en uno no deben afectar al otro.

### Caso 15: Modificar una copia del refugio
- Procedimiento:
  1. Crear un refugio original.
  2. Hacer una copia.
  3. Agregar un nuevo animal al refugio copiado.
- Resultado esperado:
  - El refugio original no debe cambiar.
  - El refugio copiado debe tener el nuevo animal.

---

## 4) Pruebas de liberación de memoria

### Caso 16: Destruir refugio con animales registrados
- Procedimiento:
  1. Registrar varios perros y gatos.
  2. Finalizar la ejecución del programa o destruir el objeto Refugio.
- Resultado esperado:
  - No deben quedar fugas de memoria.
  - El programa debe terminar sin errores de memoria.

### Caso 17: Destruir refugio con adoptantes y solicitudes
- Procedimiento:
  1. Registrar varios adoptantes.
  2. Crear varias solicitudes.
  3. Destruir el refugio.
- Resultado esperado:
  - Los punteros de adoptantes y solicitudes deben liberarse correctamente.
  - No deben quedar punteros colgantes.

---

## 5) Resumen de pruebas esperadas

| Tipo de prueba | Resultado esperado |
|---|---|
| Registro válido de un animal | Correcto |
| Registro válido de adoptante | Correcto |
| Solicitud válida | Correcta |
| Confirmación de solicitud | Correcta |
| Entrada inválida | Error controlado |
| ID inexistente | Error controlado |
| Animal no disponible | Excepción o mensaje de error |
| Copia profunda | Independencia de datos |
| Liberación de memoria | Sin fugas ni punteros colgantes |

---

## 6) Caso de prueba recomendado para entregar

### Caso de prueba final
- Registrar perro: Max, 3, Saludable, Labrador, Mediano
- Registrar adoptante: Ana, 1122334455, ana@mail.com
- Crear solicitud con adoptante y animal
- Confirmar solicitud
- Intentar crear otra solicitud para el mismo animal
- Resultado esperado:
  - La primera solicitud se crea correctamente.
  - La confirmación funciona.
  - La segunda solicitud falla por animal no disponible.

Este caso prueba tanto el flujo correcto como el manejo de errores del programa.
