# 夢Pixel
Un editor pixel art simple hecho en C
usando la libreria _ncurses_ para renderizar una
interfaz de usuario en la terminal.

## Compilar el proyecto
### Instalación de libreria
* **Linux:**
  > Generalmente no es necesarios, estas librerias son un estandar y ya vienen incluidas en el sistema operativo
    Se requiere el uso del toolchain de GNU GCC, junto con
    la dependecía de _ncurses_ y el programa make.
    * Instalación del toolchain (Arch)
    ```bash
    sudo pacman -S devtools ncurses
    ```
    * Instalación del toolchain (Debian y derivados)
    ```bash
    sudo apt install build-essentials libncurses5-dev libncursesw5-dev
    ```
* **Windows:**  
  No es necesario pues PDCurses viene precompilado e instalado en el proyecto. Para compilar/instalar de nuevo consultar la guía de [*AguHDz*](https://github.com/AguHDz/Libreria_NCURSES_en_MinGW).
### Compilación
* **Linux:**  
  Independientemente de tu distribución
  ```bash
  make clean && make
  ```
* **Windows con IDE:**  
Abrir el archivo .cbp en Code::Blocks y compilar/correr normalmente. Para otros IDE's, asegurarse de tener las carpetas `include` y `lib` como paths relativos en las opciones de `Compiler` y `Linker` respectivamente, así como `pdcurses` establecido en las `Link libraries`.    
Como referencia, en Code::Blocks estas opciones se encuentran en:
  - Project > Build options... > Search directories > Compiler
  - Project > Build options... > Search directories > Linker
  - Project > Build options... > Linker settings > Link libraries
