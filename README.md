# TC1031_Proyecto
## Descripcion del proyecto:
En este proyecto, se va crear una base de datos de drafts. Se supone que el usuario va a poder almacenar las cartas que seleccione 
en el draft, para despues analizar su manacurve (campana de los costes) y verla ordenada. Va a poder guardarse varios drafts para un solo usuario.
## Consideraciones:
El codigo actualmente presenta problemas en caso de que el usuario introduzca un valor que no sea del tipo de dato (o el rango de valores) especificados. NO introducir espacios en los strings o ints.
## SICT0301 EVALÚA LOS COMPONENTES:
Primero, seleccionando la opcion 3, el eveluador podra generar un "draft", viendo las cartas que actualmente tiene. Despues, si oberva la lista con la funcion de mostrarCartas(), se podra ver la lista despues del sort. SE PUEDE AGREGAR CARTAS PARA PROBAR TODO LO DEMAS EN ESTE DRAFT.
La complejidad se asume que es O(n**2), pero esto se elijio de esta forma para mantener una complejidad espacial baja, ademas de ser mas facil de manejar con 2 arreglos, ya que el merge hubiera acabado creando 4 arreglos. Mas adelante en este proyecto se buscará un metodo aun mas eficiente. 
## SICT0302 TOMA DECISIONES:
El programa permite de momento agregar cartas y observar la lista que llevas (sorteandola primero y asegurandose que ambos arreglos no pierdan la conexion de carta y costo). Ademas, cuenta con un caso prueba para que se pueda evaluar las tareas.
