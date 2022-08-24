/*
---------------------------------------------
Copyrigth derechos reservados 2022 - EPN
Author:	Armas Emilio
Date:		13/08/2022
Subject:	Proyecto 2B
			Calculadora de Matrices
---------------------------------------------

*/
#include <iostream>
#include <conio.h>
#include "..\lib\utility.h"

using namespace std;

void header();
void headerMatrix();
void initMatrix();
int menu();
void showMatrix(float M[][5], int m, int n);
void sum();
void subt1();
void subt2();
void prod1();
void prod2();
void dotProd();

#define LIM 5 //max order 5x5

int m1, m2, n1, n2;

float A[LIM][LIM];
float B[LIM][LIM];
float C[LIM][LIM];

int main()
{
	system("cls");
	cout.precision(3); //3 decimals
	
	load:
	system("cls");
	header();
	initMatrix();
	
	do
	{
		system("cls");
		header();
		headerMatrix();
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
				goto load;
				break;

			case EXIT:
				system("cls");
				header();
				setTextColor(LGREY);
				cout<<"\tPresione cualquier tecla para salir..."; getch();
				system("cls");
				setTextColor(WHITE);
				exit(EXIT_SUCCESS);
				break;
		}

	}while (true);
	
	return 0;
}

/*
shows options
@return option
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

	if(in != "" && validarInt(in))
		opt = stoi(in);

	while(opt<0 || opt>REINPUT || !validarInt(in) || in == ""){
		setTextColor(LRED);
		cout<<"\tOpcion no valida, ingrese la opcion nuevamente"<<endl;
		setTextColor(WHITE);
		cout<<"\tOpcion: "; getline(cin, in);
		if(in != "" && validarInt(in))
			opt = stoi(in);
		fflush(stdin);
	}

	return opt;
}

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

//shows matrices
void headerMatrix()
{
	setTextColor(LCYAN);
	cout<<"\n\tMatrices: "<<endl<<endl;
	
	setTextColor(WHITE);
	cout<<"\tA  = "<<'\t';
	showMatrix(A,m1,n1);

	cout<<endl;

	cout<<"\tB  = "<<'\t';
	showMatrix(B,m2,n2);

	cout<<endl<<endl;

}

//initialize matrices
void initMatrix()
{	
	string input, rows,columns;
	setTextColor(LCYAN);
	cout<<"\n\tIngrese el numero de filas y columnas de la matriz A:"<<endl;
	setTextColor(WHITE);
	cout<<"\tFilas de A: "; getline(cin, input);
	m1 = getPositiveInt("Filas de A: ", input, LIM);

	cout<<"\tColumnas de A: "; getline(cin, input);
	n1 = getPositiveInt("Columnas de A: ", input, LIM);

	setTextColor(LCYAN);
	cout<<"\n\tIngrese el numero de filas y columnas de la matriz B:"<<endl;
	setTextColor(WHITE);

	cout<<"\tFilas de B: "; getline(cin, input);
	m2 = getPositiveInt("Filas de B: ", input, LIM);

	cout<<"\tColumnas de B: "; getline(cin, input);
	n2 = getPositiveInt("Columnas de B: ", input, LIM);

	cout<<endl<<endl;

	setTextColor(LCYAN);
	cout<<"\tIngrese los valores de las matrices: "<<endl<<endl;

	for (int i = 0; i<m1; i++)
		for (int j = 0; j<n1; j++)
		{
			A[i][j] = getMatrixNum("A", i, j);
		}

	cout<<endl;

	for (int i = 0; i<m2; i++)
		for (int j = 0; j<n2; j++)
		{
			B[i][j] = getMatrixNum("B", i, j);
		}
}

/*
shows a matrix
@param M matrix
@param m rows
@param n columns
*/
void showMatrix(float M[][LIM], int m, int n)
{
	setTextColor(WHITE);
	for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++)
			{
				cout<<M[i][j]<<"\t\t";
			}
			cout<<endl<<"\t\t";
		}
		cout<<endl;
}

//sum A + B
void sum()
{
	setTextColor(LCYAN);
	cout<<"\tSUMA DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(m1 == m2 && n1 == n2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n1; j++)
				C[i][j] = A[i][j]+B[i][j];

		cout<<"\tLa suma de las matrices A y B es la matriz C de orden "<<m1<<"x"<<n1<<": "<<endl<<endl;
		cout<<"\tC  = "<<"\t";
		showMatrix(C,m1,n1);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar suma entre matrices de diferente orden."<<endl<<endl;
		setTextColor(WHITE);
	}	
}

//subtract A - B
void subt1()
{
	setTextColor(LCYAN);
	cout<<"\tRESTA DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(m1 == m2 && n1 == n2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n1; j++)
				C[i][j] = A[i][j]-B[i][j];

		cout<<"\tLa resta de las matrices A y B es la matriz C de orden "<<m1<<"x"<<n1<<": "<<endl<<endl;
		cout<<"\tC  = "<<'\t';
		showMatrix(C,m1,n1);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar resta entre matrices de diferente orden."<<endl<<endl;
		setTextColor(WHITE);
	}
}

//subtract B - A
void subt2()
{
	setTextColor(LCYAN);
	cout<<"\tRESTA DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(m1 == m2 && n1 == n2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n1; j++)
				C[i][j] = B[i][j]-A[i][j];

		cout<<"\tLa resta de las matrices B y A es la matriz C de orden "<<m1<<"x"<<n1<<": "<<endl<<endl;
		cout<<"\tC  = "<<'\t';
		showMatrix(C,m1,n1);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar resta entre matrices de diferente orden."<<endl<<endl;
	}
}

//product A * B
void prod1()
{
	setTextColor(LCYAN);
	cout<<"\tMULTIPLICACION DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(n1 == m2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n2; j++)
			{	
				C[i][j] = 0;

				for(int k = 0; k<n1; k++)
					C[i][j] += A[i][k]*B[k][j];
			}

		cout<<"\tEl producto (A*B) de las matrices es la matriz C de orden "<<m1<<"x"<<n2<<": "<<endl<<endl;
		cout<<"\tC  = "<<'\t';
		showMatrix(C,m1,n2);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar el producto entre estas matrices por su orden."<<endl;
		setTextColor(WHITE);
		cout<<"\tEl numero de columnas de A debe ser igual al numero de filas de B."<<endl<<endl;
	}
}

//product B * A
void prod2()
{
	setTextColor(LCYAN);
	cout<<"\tMULTIPLICACION DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(n2 == m1)
	{
		for(int i = 0; i<m2; i++)
			for (int j = 0; j<n1; j++)
			{	
				C[i][j] = 0;

				for(int k = 0; k<n2; k++)
					C[i][j] += B[i][k]*A[k][j];
			}

		cout<<"\tEl producto (B*A) de las matrices es la matriz C de orden "<<m2<<"x"<<n1<<": "<<endl<<endl;
		cout<<"\tC  = "<<'\t';
		showMatrix(C,m2,n1);
		cout<<endl;
	}
	else{
		setTextColor(LRED);
		cout<<"\tNo se puede realizar el producto entre estas matrices por su orden."<<endl;
		setTextColor(WHITE);
		cout<<"\tEl numero de columnas de B debe ser igual al numero de filas de A."<<endl<<endl;
	}
}

//dot product trace(A * B^T)
void dotProd()
{
	setTextColor(LCYAN);
	cout<<"\tPRODUCTO INTERNO USUAL DE MATRICES"<<endl<<endl;
	setTextColor(WHITE);
	if(m1 == m2 && n1 == n2)
	{
		float trace = 0;
		for(int i = 0; i<m1; i++)
		{	
			C[i][i] = 0;

			for(int k = 0; k<n1; k++)
				C[i][i] += A[i][k]*B[i][k];
		}

		for(int i = 0; i<m1; i++)
				trace += C[i][i];

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
