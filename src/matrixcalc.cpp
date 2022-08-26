/*
---------------------------------------------
Author:		Armas Emilio
Date:		13/08/2022
Subject:	Proyecto 2B - Calculadora de Matrices
---------------------------------------------

*/
#include <iostream>
#include <conio.h>
#include "..\lib\utility.h"

using namespace std;

#define LIM 5 // max order 5x5

// variables globales

int mA, mB, nA, nB; // ordenes de las matrices

float A[LIM][LIM];
float B[LIM][LIM];
float C[LIM][LIM];


// declaracion de procedimientos y funciones

int menu();
void header();
void headerMatrix();
void initMatrix();
void nullMatrix(float M[][LIM]);
void showMatrix(char name, float M[][5], int m, int n);
void sum();
void subt1();
void subt2();
void prod1();
void prod2();
void dotProd();

int main()
{
	system("cls");
	cout.precision(3); // 3 decimales
	
	INGRESAR_MATRICES: // reingreso de matrices
	nullMatrix(A);
	nullMatrix(B);
	nullMatrix(C);
	system("cls");
	header();
	initMatrix();
	
	while(1)
	{
		system("cls");
		header();
		headerMatrix();
		nullMatrix(C); // encera la matriz que guarda las respuestas
		switch(menu())
		{
			case SUM:
				system("cls");
				header();
				headerMatrix();
				sum();
				setTextColor(LGREY);
				cout<<"\tPresione cualquier tecla para continuar..."; getch();
				setTextColor(WHITE);
				system("cls");
				break;

			case SUBT1:
				system("cls");
				header();
				headerMatrix();
				subt1();
				setTextColor(LGREY);
				cout<<"\tPresione cualquier tecla para continuar..."; getch();
				setTextColor(WHITE);
				system("cls");
				break;

			case SUBT2:
				system("cls");
				header();
				headerMatrix();
				subt2();
				setTextColor(LGREY);
				cout<<"\tPresione cualquier tecla para continuar..."; getch();
				setTextColor(WHITE);
				system("cls");
				break;

			case PROD1:
				system("cls");
				header();
				headerMatrix();
				prod1();
				setTextColor(LGREY);
				cout<<"\tPresione cualquier tecla para continuar..."; getch();
				setTextColor(WHITE);
				system("cls");
				break;

			case PROD2:
				system("cls");
				header();
				headerMatrix();
				prod2();
				setTextColor(LGREY);
				cout<<"\tPresione cualquier tecla para continuar..."; getch();
				setTextColor(WHITE);
				system("cls");
				break;

			case DOT_PROD:
				system("cls");
				header();
				headerMatrix();
				dotProd();
				setTextColor(LGREY);
				cout<<"\tPresione cualquier tecla para continuar..."; getch();
				setTextColor(WHITE);
				system("cls");
				break;

			case REINPUT:
				system("cls");
				goto INGRESAR_MATRICES;
				break;

			case EXIT:
				system("cls");
				header();
				setTextColor(LGREY);
				cout<<"\tAdios!"<<endl<<"\tPresione cualquier tecla para salir..."; getch();
				system("cls");
				exit(EXIT_SUCCESS);
				break;
		}
	}
	
	return 0;
}

/*
muestra las opciones
@return int option
*/
int menu()
{
	string in;
	int opt;
	setTextColor(LCYAN);
	cout<<"\tIngresa una opcion:"<<endl<<endl;
	setTextColor(WHITE);
	cout<<'\t'<<SUM<<". Suma de matrices (A+B)"<<endl
		<<'\t'<<SUBT1<<". Resta de matrices (A-B)"<<endl
		<<'\t'<<SUBT2<<". Resta de matrices (B-A)"<<endl
		<<'\t'<<PROD1<<". Producto de matrices (A*B)"<<endl
		<<'\t'<<PROD2<<". Producto de matrices (B*A)"<<endl
		<<'\t'<<DOT_PROD<<". Producto interno usual (Tr(A*B^T))"<<endl
		<<'\t'<<REINPUT<<". Reingresar matrices"<<endl
		<<'\t'<<EXIT<<". Salir"<<endl<<endl;
	cout<<"\tOpcion: "; getline(cin, in);
	fflush(stdin);

	if(in != "" && checkPosInt(in))
		opt = stoi(in);

	while(opt<0 || opt>REINPUT || !checkPosInt(in) || in == ""){
		setTextColor(LRED);
		cout<<"\tOpcion no valida, ingrese la opcion nuevamente"<<endl;
		setTextColor(WHITE);
		cout<<"\tOpcion: "; getline(cin, in);
		if(in != "" && checkPosInt(in))
			opt = stoi(in);
		fflush(stdin);
	}

	return opt;
}

// muestra instrucciones y nombre
void header()
{
	setTextColor(LBLUE);
	cout<<"\t--------------------- CALCULADORA DE MATRICES --------------------"<<endl;
	setTextColor(WHITE);
	cout<<"\t|   Instrucciones:                                               |"<<endl
		<<"\t|    > Ingresa el orden y los elementos de las matrices.         |"<<endl
		<<"\t|    > Selecciona la opcion de que desees.                       |"<<endl
		<<"\t|    > De ser posible, se realizara la operacion.                |"<<endl
		<<"\t|    > Se pueden ingresar decimales y numeros negativos.         |"<<endl
		<<"\t|    > Trabaja con matrices hasta de orden 5x5.                  |"<<endl;
	setTextColor(LBLUE);
	cout<<"\t------------------------------------------------------------------"<<endl<<endl;
}

// muestra las matrices con las que se opera
void headerMatrix()
{
	setTextColor(LCYAN);
	cout<<"\n\tMatrices: "<<endl<<endl;

	showMatrix('A',A,mA,nA);
	cout<<endl;
	showMatrix('B',B,mB,nB);
	cout<<endl<<endl;

}

// inicializa matrices
void initMatrix()
{	
	string input, rows,columns;
	setTextColor(LCYAN);
	cout<<"\n\tIngrese el numero de filas y columnas de la matriz A:"<<endl;
	setTextColor(WHITE);
	cout<<"\tFilas de A: "; getline(cin, input);
	mA = getPositiveInt("Filas de A: ", input, LIM);

	cout<<"\tColumnas de A: "; getline(cin, input);
	nA = getPositiveInt("Columnas de A: ", input, LIM);

	setTextColor(LCYAN);
	cout<<"\n\tIngrese el numero de filas y columnas de la matriz B:"<<endl;
	setTextColor(WHITE);

	cout<<"\tFilas de B: "; getline(cin, input);
	mB = getPositiveInt("Filas de B: ", input, LIM);

	cout<<"\tColumnas de B: "; getline(cin, input);
	nB = getPositiveInt("Columnas de B: ", input, LIM);

	cout<<endl<<endl;

	setTextColor(LCYAN);
	cout<<"\tIngrese los valores de las matrices: "<<endl<<endl;

	for (int i = 0; i<mA; i++)
		for (int j = 0; j<nA; j++)
		{
			A[i][j] = getMatrixNum("A", i, j);
		}

	cout<<endl;

	for (int i = 0; i<mB; i++)
		for (int j = 0; j<nB; j++)
		{
			B[i][j] = getMatrixNum("B", i, j);
		}
}

/*
muestra una matriz
@param name nombre de la matriz
@param M matriz
@param m rows
@param n columns
*/
void showMatrix(char name, float M[][LIM], int m, int n)
{
	setTextColor(WHITE);
	cout<<"\t"<<name<<"  = "<<'\t';
	for (int i = 0; i<m; i++){ // muestra las m filas
			for (int j = 0; j<n; j++) // muestra las n columnas
			{
				cout<<M[i][j]<<"\t\t"; // muestra el elemento en la posicion i j
			}
			cout<<endl<<"\t\t";
		}
		cout<<endl;
}

// suma A + B
void sum()
{
	setTextColor(LCYAN);
	cout<<"\tSUMA DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(mA == mB && nA == nB) // los ordenes de las dos matrices deben ser iguales
	{
		for(int i = 0; i<mA; i++) // por cada fila
			for (int j = 0; j<nA; j++) // por cada columna
				C[i][j] = A[i][j]+B[i][j]; // suma el elemento i j de cada matriz y lo asigna al elemento i j de la matriz C

		cout<<"\tLa suma de las matrices A y B es la matriz C de orden "<<mA<<"x"<<nA<<": "<<endl<<endl;
		showMatrix('C',C, mA, nA);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar suma entre matrices de diferente orden."<<endl<<endl;
		setTextColor(WHITE);
	}	
}

// resta A - B
void subt1()
{
	setTextColor(LCYAN);
	cout<<"\tRESTA DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(mA == mB && nA == nB) // las matrices deben ser de igual orden
	{
		for(int i = 0; i<mA; i++) // por cada fila
			for (int j = 0; j<nA; j++) // por cada columna
				C[i][j] = A[i][j]-B[i][j]; // resta el elemento i j de A y el elemento i j de B y lo guarda en i j de C

		cout<<"\tLa resta de las matrices A y B es la matriz C de orden "<<mA<<"x"<<nA<<": "<<endl<<endl;
		showMatrix('C',C,mA,nA);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar resta entre matrices de diferente orden."<<endl<<endl;
		setTextColor(WHITE);
	}
}

// resta B - A
void subt2()
{
	setTextColor(LCYAN);
	cout<<"\tRESTA DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(mA == mB && nA == nB) 
	{
		for(int i = 0; i<mA; i++)
			for (int j = 0; j<nA; j++)
				C[i][j] = B[i][j]-A[i][j];

		cout<<"\tLa resta de las matrices B y A es la matriz C de orden "<<mA<<"x"<<nA<<": "<<endl<<endl;
		showMatrix('C',C,mA,nA);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar resta entre matrices de diferente orden."<<endl<<endl;
	}
}

// producto A * B
void prod1()
{
	setTextColor(LCYAN);
	cout<<"\tMULTIPLICACION DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(nA == mB)  // columnas de A iguales a filas de B
	{
		for(int i = 0; i<mA; i++)  // por cada fila de C (mismo # filas de A)
			for (int j = 0; j<nB; j++) // por cada columna de C (mismo # columnas de B) 
			{	
				C[i][j] = 0;

				for(int k = 0; k<nA; k++) // cada fila de A tiene nA/mB elementos y cada columna de B tiene nA/mB elementos
					C[i][j] += A[i][k]*B[k][j];   // cada elemento i j de C es la suma de los productos de los elementos de la fila i de A y la columna j de B
			}

		cout<<"\tEl producto (A*B) de las matrices es la matriz C de orden "<<mA<<"x"<<nB<<": "<<endl<<endl;
		showMatrix('C',C,mA,nB);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar el producto entre estas matrices por su orden."<<endl;
		setTextColor(WHITE);
		cout<<"\tEl numero de columnas de A debe ser igual al numero de filas de B."<<endl<<endl;
	}
}

// producto B * A
void prod2()
{
	setTextColor(LCYAN);
	cout<<"\tMULTIPLICACION DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(nB == mA)
	{
		for(int i = 0; i<mB; i++)
			for (int j = 0; j<nA; j++)
			{	
				C[i][j] = 0;

				for(int k = 0; k<nB; k++)
					C[i][j] += B[i][k]*A[k][j];
			}

		cout<<"\tEl producto (B*A) de las matrices es la matriz C de orden "<<mB<<"x"<<nA<<": "<<endl<<endl;
		showMatrix('C',C,mB,nA);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar el producto entre estas matrices por su orden."<<endl;
		setTextColor(WHITE);
		cout<<"\tEl numero de columnas de B debe ser igual al numero de filas de A."<<endl<<endl;
	}
}

// producto punto traza(A * B^T)
void dotProd()
{
	setTextColor(LCYAN);
	cout<<"\tPRODUCTO INTERNO USUAL DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(mA == mB && nA == nB) // deben tener mismo numero de filas y columnas para que resulte una matriz cuadrada (por la traza)
	{
		float trace = 0;
		for(int i = 0; i<mA; i++)  // por cada elemento de la diagonal
		{	
			C[i][i] = 0;

			for(int k = 0; k<nA; k++)  // # elementos filas de A y columnas de la transpuesta de B
				C[i][i] += A[i][k]*B[i][k];   // se toma elementos de la fila i de A y de la transpuesta de B
		}

		for(int i = 0; i<mA; i++)
				trace += C[i][i]; // suma elementos de la diagonal

		cout<<"\tEl producto interno usual de las matrices A y B es: "<<endl<<endl
			<<"\t"<<trace<<endl<<endl;
	}	
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar el producto interno usual entre las matrices por su orden."<<endl;
		setTextColor(WHITE);
		cout<<"\tLa matriz resultante de A*B^T debe ser cuadrada para obtener su traza."<<endl<<endl;
	}
}

/*
iguala una matriz a la matriz nula
@param M matriz
*/
void nullMatrix(float M[][LIM])
{
	for(int i = 0; i < LIM; i++) // cada fila
		for(int j = 0; j < LIM; j++) // cada columna
			M[i][j] = 0;
}
