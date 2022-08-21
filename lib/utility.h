#include<iostream>
#include<windows.h>

using namespace std;

enum Colors 
{
    BLACK      = 0,
    BLUE       = 1,
    GREEN      = 2,
    CYAN       = 3,
    RED        = 4,
    MAGENTA    = 5,
    BROWN      = 6,
    LGREY      = 7,
    DGREY      = 8,
    LBLUE      = 9,
    LGREEN     = 10,
    LCYAN      = 11,
    LRED       = 12,
    LMAGENTA   = 13,
    YELLOW     = 14,
    WHITE      = 15
};

enum Options
{
    EXIT        = 0,
    SUM,
    SUBT1,
    SUBT2,
    PROD1,
    PROD2,
    DOT_PROD,
    REINPUT     
};

bool validarInt(string str){
    for(int i = 0; i<str.length(); i++)
        if(isdigit(str[i]) == 0) 
            return false;
    return true;
}

bool validarNum(string cadena) {
    int longitud = cadena.length();
    // Quitar espacios, saltos de línea, etcétera
    while (longitud > 0 && isspace(cadena[longitud - 1]))
        longitud--;
    if (longitud <= 0) return 0;
    int i;
    int haEncontradoElPunto = 0;
    for (i = 0; i < longitud; ++i) {
        // En caso de que sea un guión, y que no esté al inicio, no es válido
        if (cadena[i] == '-' && i > 0) {
            return 0;
        }
        // El punto solo puede aparecer una vez
        if (cadena[i] == '.') {
            // Si ya lo ha encontrado antes, entonces no es válido
            if (haEncontradoElPunto) {
                return 0;
            } else {

                haEncontradoElPunto = 1;
            }
        }
        // Si no es dígito, tampoco es válido
        if (!isdigit(cadena[i]) && cadena[i] != '-' && cadena[i] != '.') {
            return 0;
        }
    }
    return 1;
}

void gotoxy(int x, int y) 
{ 
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); 
COORD c; 
   c.X=x; 
   c.Y=y; 
   SetConsoleCursorPosition(h,c); 
}

void showcursor(bool cursor)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = cursor;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void setTextColor(int Text)
{ 
    int colorTexto= Text;         // los colores van del 0 al 255 por eso se multiplica por 16
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   // referenciamos a la consola.
    SetConsoleTextAttribute(terminal, colorTexto); 
}