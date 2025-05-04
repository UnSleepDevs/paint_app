#include "splash_screen.h"

void splashScreen(){
    char* instructions[5][2] = {
        {"w/a/s/d", "Movimiento básico"},
        {"m", "Cambio de Modo"},
        {"i", "Insertar un pixel"},
        {"r", "Quitar un pixel"},
        {"j/f", "Cambiar de color"}
    };

    move(0,0);

}
