# Cursor
El cursor es la parte más importante,
este se encarga de trabajar las posiciones, el modo de trabajo, e incluso los estilos que se usaran al dibujar

Para esto se usa la struct [Cursor](../src/Cursor/cursor.h), en la cual guardamos el caracter para mostrar como cursor, las coordenadas de este, los estilos y el modo.

## Funciones

* `**update_cursor()**`: Se encarga de detectar las pulsaciones del teclado relacionadas a el, mover el cursor, limitar el movimiento, actualizar el modo y los colores.
* `**draw_cursor()**`: Se encarga de dibujar el cursor