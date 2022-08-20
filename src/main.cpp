/*
---------------------------------------------
Developer:	Armas Emilio
Date:		13/08/2022
Subject:	Proyecto 2B
			Calculadora de Matrices
---------------------------------------------

*/
#include <iostream>
#include "..\lib\utility.h"

using namespace std;

void header();
int menu();
void input();
void sum();
void subtract();
void matrixProduct();
void dotProduct();
void determinant();
void showMatrix();

int m1, m2, n1, n2;

int A[0][0];
int B[0][0];
int C[0][0];


int main()
{

	header();
	input();
	switch (menu())
	{
		case SUM:
			//sum();
			break;

		case SUBT:
			//subtract();
			break;

		case PROD:
			break;

		case DOT_PROD:
			break;

		case REINPUT:
			break;

		case EXIT:
			break;

	}
	return 0;
}

int menu()
{
	string in;
	int opt;
	system("cls");
	cout<<"Ingresa una opcion:"<<endl<<endl
		<<SUM<<". Suma de matrices (A + B)"<<endl
		<<SUBT<<". Resta de matrices (A - B)"<<endl
		<<PROD<<". Producto de Matrices (A * B)"<<endl
		<<DETER<<". Determinante (det(A))"<<endl
		<<DOT_PROD<<". Producto Interno casual (Tr(A*B^T))"<<endl
		<<REINPUT<<". Reingresar matrices"<<endl
		<<EXIT<<". Salir"<<endl<<endl;
	cout<<"Opcion: "; getline(cin, in);
	fflush(stdin);

	if(in != "" && validarInt(in))
		opt = stoi(in);

	while(opt<0 || opt>6 || !validarInt(in) || in == ""){
		cout<<"Opcion no valida, ingrese la opcion nuevamente"<<endl;
		cout<<"Opcion: "; getline(cin, in);
		if(in != "" && validarInt(in))
			opt = stoi(in);
		fflush(stdin);
	}

	return opt;
}

void header()
{
	
}


void input()
{	
	string rows, columns;
	cout<<"Ingrese el numero de filas y columnas de la matriz A:"<<endl;
	cout<<"Filas de A:"; getline(cin, rows);
	
	if(rows!="" && validarInt(rows))
		m1 = stoi(rows);

	while(m1<1 || m1 >10 || !validarInt(rows) || rows == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Filas de A:"; getline(cin, rows);
		if(rows!="" && validarInt(rows))
			m1 = stoi(rows);
		fflush(stdin);
	}

	cout<<"Columnas de A:"; getline(cin, columns);
	
	if(columns!="" && validarInt(columns))
		n1 = stoi(columns);

	while(n1<1 || n1 >10 || !validarInt(columns) || columns == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Columnas de A:"; getline(cin, columns);
		if(columns!="" && validarInt(columns))
			n1 = stoi(columns);
		fflush(stdin);
	}
	
	cout<<"Ingrese el numero de filas y columnas de la matriz B:"<<endl;
	cout<<"Filas de B:"; getline(cin, rows);
	
	if(rows!="" && validarInt(rows))
		m2 = stoi(rows);

	while(m2<1 || m2 >10 || !validarInt(rows) || rows == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Filas de B:"; getline(cin, rows);
		if(rows!="" && validarInt(rows))
			m2 = stoi(rows);
		fflush(stdin);
	}

	cout<<"Columnas de B:"; getline(cin, columns);
	
	if(columns!="" && validarInt(columns))
		n1 = stoi(columns);

	while(n1<1 || n1 >10 || !validarInt(columns) || columns == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Columnas de A:"; getline(cin, columns);
		if(columns!="" && validarInt(columns))
			n1 = stoi(columns);
		fflush(stdin);
	}
	

}