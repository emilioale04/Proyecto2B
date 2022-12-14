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
revisa si la entrada es un numero entero positivo
@param str input string
@return true si es +int / false si no es +int
*/
bool checkPosInt(string str)
{
    for(int i = 0; i<str.length(); i++)
        if(isdigit(str[i]) == 0) 
            return false;
    return true;
}

/*
revisa si la entrada es un numero (+, -, .)
@param str input string
@return true si es num / false si no es num
*/
bool checkNum(string str)
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
cambia el color del texto en consola
@param Text int from 0 to 15
*/
void setTextColor(int Text)
{ 
    int colorTexto= Text;         // los colores van del 0 al 255 por eso se multiplica por 16
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   // referenciamos a la consola.
    SetConsoleTextAttribute(terminal, colorTexto); 
}

/*
obtiene un num (+, -, .) para una matriz
@param name nombre de la matriz
@param i fila
@param j columna
@return float num
*/
float getMatrixNum(string name, int i, int j){
	fflush(stdin);
    float val;
	string input;
	
	setTextColor(WHITE);
	cout<<"\tIngrese el numero "<<name<<"["<<i+1<<"]["<<j+1<<"]: ";	getline(cin, input);

	if(input!="" && checkNum(input) && input!="." && input!="-")
		val = stof(input);

	while(!checkNum(input) || input == "" || input == "." || input == "-"){
		setTextColor(LRED);
		cout<<"\tOpcion no valida, ingrese un numero valido"<<endl;
		setTextColor(WHITE);
	    cout<<"\tIngrese el numero "<<name<<"["<<i+1<<"]["<<j+1<<"]: ";	getline(cin, input);
		if(input!="" && checkNum(input) && input!="." && input!="-")
			val = stof(input);
		fflush(stdin);
	}

	return val;
}

/*
obtiene un +int
@param tag mensaje para el reingreso de un valor aceptable
@param val input string
@param lim max number
@return +int en el rango
*/
int getPositiveInt(string tag, string val, int lim)
{
	int m;
	if(val!="" && checkPosInt(val))
		m = stoi(val);

	while(m < 1 || m > lim || !checkPosInt(val) || val == ""){
		setTextColor(LRED);
		cout<<"\tOpcion no valida, ingrese un numero valido nuevamente"<<endl;
		setTextColor(WHITE);
		cout<<"\t"<<tag; getline(cin, val);
		if(val!="" && checkPosInt(val))
			m = stoi(val);
		fflush(stdin);
	}
	return m;
}