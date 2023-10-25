# PID c++
## Simulador de un procesador de tareas implementado en c++ trabajo para Sistemas Operativos.
La idea principal es lograr que el programa logre organizar y procesar las tareas dependiento  dek tipo de procesador que se quiera simular (monoproceso o multiproceso) y de los diferentes ordenes especificados en el sistema.

EL programa ordena dependiendo el gusto del usuario, si existe una igualdad, eordenamiento toma otro rasgo del objeto para ordenar los 2 items iguales en un aspecto seleccionado.

Es decir, el usuario solicito que se orgnice todo por prioridad, despues alfabeticamente por su inicial, y despues por su identificador.

Si la prioridad es la misma en 2 o mas items, estos seran ordenados alfabeticamente por su inicial, si llegan a coincidir de nuevo 2 o mas, se ordenaran por el ID que se les fue asignando conforme a su creacion de la tarea.

El progama ocupa colas para guardar la información agregada, o lee un archivo txt para crear todas las tareas que esten en el archivo de texto
