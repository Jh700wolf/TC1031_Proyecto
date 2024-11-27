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

*sortDeckCost():* Tiene una complejidad de o(nlogn) conforme al tiempo, pero una espacial de o(n). Se hizo el cambio para asegurar un algoritmo mas eficiente, y redujo considerablemente la complejidad de tiempo.

*sortDeckManaP():* Tiene una complejidad de o(nlogn) conforme al tiempo, pero una espacial de o(n). Se hizo el cambio para asegurar un algoritmo mas eficiente, y redujo considerablemente la complejidad de tiempo. 

*mostrarDeckPips():* Es una funcion O(n), ya que se recorren todos los elementos de esta lista desde el head al tail. 

*guardarCartas():* Es una funcion de O(n), ya que debe de ir guardadno cada elemento de cada carta de uno en uno.

**Total:** Para el total, vamos a asumir que el usuario abre todas las decks que tiene guardadas en el txt, lo que empieza como O(n). Despues agrega cartas, lo que solo agrega un O(1) si es solo una carta, o O(n) si agrega n cartas. La funcion para ver la deck usa O(3n), ya que son 3 que recorren toda la lista, y O(2n**2) para los 2 sorts que son necesarios, uno para acomodar de acuerdo a mana y otro de acuerto a coste total. Finalmente se guarda todo O(n). Aqui podemos asumir que la complejidad de todo es de O(2n^2+6n) mas o menos. 
## SICT0302 TOMA DECISIONES:
El programa permite de momento ver todos los drafts que estan dentro de el archivo de texto, agregar cartas y observar la lista que llevas (sorteandola primero y asegurandose que ambos arreglos no pierdan la conexion de carta y costo), y poder guardar nuevas decks dentro del archivo de texto. Ademas, cuenta con un caso prueba para que se pueda evaluar las tareas. Como tarea final, se agregara un analisis mas detallado a la deck del usuario, ademas de poder eliminar cartas previamente agregadas. 
