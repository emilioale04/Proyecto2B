#include<iostream>
#include<windows.h>

using namespace std;

void setTextColor(int Text);

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

/*
check int number
@param str input string
@return false if not number -
@return true if number
*/
bool validarInt(string str)
{
    for(int i = 0; i<str.length(); i++)
        if(isdigit(str[i]) == 0) 
            return false;
    return true;
}

/*
check number (+, -, .)
@param str input string
@return false if not number -
@return true if number
*/
bool validarNum(string str)
{
    int longitud = str.length();
    // Quitar espacios, saltos de línea, etcétera
    while (longitud > 0 && isspace(str[longitud - 1]))
        longitud--;
    if (longitud <= 0) return false;
    int i;
    int haEncontradoElPunto = 0;
    for (i = 0; i < longitud; ++i) {
        // En caso de que sea un guión, y que no esté al inicio, no es válido
        if (str[i] == '-' && i > 0) {
            return false;
        }
        // El punto solo puede aparecer una vez
        if (str[i] == '.') {
            // Si ya lo ha encontrado antes, entonces no es válido
            if (haEncontradoElPunto) {
                return false;
            } else {

                haEncontradoElPunto = 1;
            }
        }
        // Si no es dígito, tampoco es válido
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.') {
            return false;
        }
    }
    return true;
}

/*
hides or shows the cursor in console
@param cursor true or false
*/
void showcursor(bool cursor)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = cursor;
   SetConsoleCursorInfo(consoleHandle, &info);
}

/*
changes text color in console 
@param Text int from 0 to 15
*/
void setTextColor(int Text)
{ 
    int colorTexto= Text;         // los colores van del 0 al 255 por eso se multiplica por 16
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   // referenciamos a la consola.
    SetConsoleTextAttribute(terminal, colorTexto); 
}

/*
gets a number for a matrix (+, -, .)
@param name matrix name
@param i row
@param j column
@return float number
*/
float getMatrixNum(string name, int i, int j){
	fflush(stdin);
    float val;
	string input;
	
	setTextColor(WHITE);
	cout<<"\tIngrese el numero "<<name<<"["<<i+1<<"]["<<j+1<<"]: ";	getline(cin, input);

	if(input!="" && validarNum(input) && input!="." && input!="-")
		val = stof(input);

	while(!validarNum(input) || input == "" || input == "." || input == "-"){
		setTextColor(LRED);
		cout<<"\tOpcion no valida, ingrese un numero valido"<<endl;
		setTextColor(WHITE);
	    cout<<"\tIngrese el numero "<<name<<"["<<i+1<<"]["<<j+1<<"]: ";	getline(cin, input);
		if(input!="" && validarNum(input) && input!="." && input!="-")
			val = stof(input);
		fflush(stdin);
	}

	return val;
}

/*
gets a positive int
@param tag message to input
@param val input string
@param lim max number
@return positive number in the range
*/
int getPositiveInt(string tag, string val, int lim)
{
	int m;
	if(val!="" && validarInt(val))
		m = stoi(val);

	while(m < 1 || m > lim || !validarInt(val) || val == ""){
		setTextColor(LRED);
		cout<<"\tOpcion no valida, ingrese un numero valido nuevamente"<<endl;
		setTextColor(WHITE);
		cout<<"\t"<<tag; getline(cin, val);
		if(val!="" && validarInt(val))
			m = stoi(val);
		fflush(stdin);
	}
	return m;
}