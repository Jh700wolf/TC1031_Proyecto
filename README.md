# TC1031_Proyecto
## Descripcion del proyecto:
En este proyecto, se va crear una base de datos de drafts. Se supone que el usuario va a poder almacenar las cartas que seleccione 
en el draft, para despues analizar su manacurve (campana de los costes) y verla ordenada. Va a poder guardarse varios drafts para un solo usuario.
## Consideraciones:
El codigo actualmente presenta problemas en caso de que el usuario introduzca un valor que no sea del tipo de dato (o el rango de valores) especificados. NO introducir espacios en los strings o ints.
## SICT0301 EVALÚA LOS COMPONENTES:
### EVALUACIÓN DE FUNCIONES IMPORTANTES DE DRAFT.H:
*insertCard():* Gracias a que uso una lista doblemente ligada y se puede usar la tail para acceder al final y asi sumar, esta funcion tiene una complejidad de O(1).

*llenarLands():* Es una funcion de comlpejidad de O(n), ya que se procesa n veces depediendo del número de cartas que faltan para llegar a 40. 

*mostrarDeckadelante():* Es una funcion O(n), ya que se recorren todos los elementos de esta lista desde el head al tail. 

*mostrarDeckdetras():* Es una funcion o(n), ya que se recorren todos los elementos de esta lista desde el tail al head.


## SICT0302 TOMA DECISIONES:
El programa permite de momento agregar cartas y observar la lista que llevas (sorteandola primero y asegurandose que ambos arreglos no pierdan la conexion de carta y costo). Ademas, cuenta con un caso prueba para que se pueda evaluar las tareas.
