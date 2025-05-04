# Pixels
**Comón funciona el almacenamiento de los píxeles?**

Un pixel es la estructura que usamos para almacenar lo que
el usuario ha dibujado, en esta implementación se guarda:
    * Coordenadas del pixel
    * El color o los estilos de este

## Lista de píxeles
Esta estructura es algo más compleja de entender, ya que para
representar la lista de los pixeles colocados opte por utilizar una 
lista doblemente enlazada.

### Ventajas y contras
* **Ventajas**
    * Solo se almacenan los elementos que se estan usando, lo que
    ahorra maś memoria que crear una matriz.
    * Es más rápida la renderización del lienzo, ya que al esta solo
    contener los elementos necesarios solo recorremos lo necesario.
    * Podemos redimensionar la lista sin costo computacional alto.
* **Deventajas**
    * Para eliminar un elemento debemos recorrer la lista hasta encontrarlo
    lo que en un arreglo es más rápido.
    * Para acceder a un elemento es la misma historia

