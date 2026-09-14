Actividad N°1
Un sistema de gestión para un refugio encaja perfectamente con el paradigma orientado a objetos (POO) porque permite trasladar las entidades y procesos del mundo real de manera directa y lógica al código.

Modelado natural (Abstracción): Los elementos físicos y lógicos del entorno (perros, gatos, adoptantes, el propio refugio) se identifican claramente como "objetos" independientes que interactúan entre sí.

Reutilización de características (Herencia): Dado que los perros y los gatos comparten atributos fundamentales (como ID, nombre, edad y estado de salud), se pueden agrupar bajo un concepto general o clase base (Animal). Esto elimina la repetición de código y permite que las clases específicas solo definan sus particularidades (como la raza del perro o si el gato es de interior).

Flexibilidad en la gestión (Polimorfismo): El sistema del refugio no necesita listas separadas ni funciones distintas para cada especie. Puede manejar un catálogo unificado de animales y pedirles que ejecuten acciones comunes (como mostrar su información), dejando que cada objeto responda automáticamente según su naturaleza.

Seguridad de los datos (Encapsulamiento): El estado de un animal (por ejemplo, si está disponible o ya fue adoptado) queda protegido dentro de su propio objeto. Solo se puede alterar mediante operaciones controladas, evitando que un animal sea "adoptado" dos veces por accidente.

Vínculos lógicos (Composición): Un trámite del mundo real, como una adopción, se representa vinculando objetos. Una SolicitudAdopcion funciona como un contrato que une orgánicamente a un Adoptante con un Animal, replicando la interacción administrativa real.