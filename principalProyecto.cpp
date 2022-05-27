#include"alumnoVector.h"
#include<iostream>
using namespace std;
/*Globales*/
AlumnoVector alumnoVector;
/*Prototipos*/
void menuOpciones();
void adicionar();
void buscar();
void eliminar();
void modificar();
void listar();
/**/
int main()
{
	menuOpciones();

}
void menuOpciones()
{
	int opt;
	do
	{
		cout<<"--MENU DE OPCIONES----------\n";
		cout<<"--Adicionar Nuevo Alumno-[1]\n";
		cout<<"--Buscar-----------------[2]\n";
		cout<<"--Eliminar---------------[3]\n";
		cout<<"--Modificar--------------[4]\n";
		cout<<"--Listar-----------------[5]\n";
		cout<<"--Salir------------------[6]\n";
		cout<<"--Ingresar Opcion[1-6]:";
		cin>>opt;
		switch(opt)
		{
			case 1:system("cls");adicionar();break;
			case 2:system("cls");buscar();break;
			case 3:system("cls");eliminar();break;
			case 4:system("cls");modificar();break;
			case 5:system("cls");listar();break;
			case 6:	cout<<"#####Gracias por usar nuestro servicio#####";break;
			default:cout<<"Ingrese una opcion valida[1-6]";
		}
	}
	while(opt!=6);
}
void adicionar()
{
	string 	bandera,
			nom;
	int 	cod;
	//Crear Objeto de tipo Alumno
	do
	{
		cod = alumnoVector.getCorrelativo();
		cout<<"*****CODIGO("<<cod<<")********\n";
		cin.ignore();
		cout<<"INGRESE NOMBRE:";
		getline(cin,nom);

		Alumno alumno;	/*Crear el objeto - instancia*/
		alumno.setCodigo(cod);
		alumno.setNombre(nom);

		alumnoVector.add(alumno);/*Asignando el objeto al contenedor*/
		alumnoVector.grabarEnArchivo(alumno);
		cout<<"PARA CONTINUAR(S/N):";
		cin>>bandera;

		system("cls");
	}
	while(bandera =="S" || bandera =="s" );
}
void buscar()
{
	try
	{
		int cod;
		cout<<"Ingrese codigo a buscar:";
		cin>>cod;
		Alumno objetoABuscar = alumnoVector.buscarPorCodigo(cod);

		if(objetoABuscar.getNombre() !="Error")
		{
			cout<<"Registro Encontrado\n";
			cout<<"Codigo:"<<objetoABuscar.getCodigo()<<"\n";
			cout<<"Nombre:"<<objetoABuscar.getNombre()<<"\n";
			system("pause");
			system("cls");
		}
		else
		{
			cout<<"Registro NO ENCONTRADO!!!";
			system("pause");
			system("cls");
			menuOpciones();
		}
	}
	catch(exception e)
	{
		cout<<"Registro NO ENCONTRADO!!!";
	}
}
void eliminar()
{
	int cod;
	string flag;
	cout<<"Ingrese codigo a buscar:";
	cin>>cod;

	cout<<"Deseas Eliminar el Registro(S/N):";
	cin>>flag;
	if(flag == "S"|| flag=="s")
	{
		Alumno objetoABuscar = alumnoVector.buscarPorCodigo(cod);
		if(objetoABuscar.getNombre() !="Error")
		{
			alumnoVector.remove(objetoABuscar);
			cout<<"Registro Eliminado Satisfactoriamente!\n";
			alumnoVector.grabarModificarEliminarArchivo();
			system("cls");
		}
		else
		{
			cout<<"Registro NO ENCONTRADO!!!";
			system("pause");
			system("cls");
			menuOpciones();
		}
	}
	else
	{
		system("cls");
		menuOpciones();
	}
}
void modificar()
{
	int cod;
	string flag;
	cout<<"Ingrese codigo a buscar:";
	cin>>cod;

	cout<<"Deseas Modificar el Registro(S/N):";
	cin>>flag;
	if(flag == "S"|| flag=="s")
	{
		Alumno objetoABuscar = alumnoVector.buscarPorCodigo(cod);
		if(objetoABuscar.getNombre() !="Error")
		{
			string nombre;
			cout<<"Registro Encontrado\n";
			cout<<"Codigo:"<<objetoABuscar.getCodigo()<<endl;
			cout<<"Nombre:"<<objetoABuscar.getNombre()<<endl;
			cin.ignore();
			cout<<"Modificando Registros\n";
			cout<<"Modificando el Campo Nombre:";
			getline(cin,nombre);
			bool estado = alumnoVector.modificar(objetoABuscar,nombre);
			if(estado)
			{
				cout<<"Registro Modificado Satisfactoriamente!\n";
				alumnoVector.grabarModificarEliminarArchivo();
				system("pause");
				system("cls");
			}
			else
			{
				cout<<"No editado!";
			}
		}
		else
		{
			cout<<"Registro NO ENCONTRADO!!!";
			system("pause");
			system("cls");
			menuOpciones();
		}
	}
	else
	{
		system("cls");
		menuOpciones();
	}
}
void listar()
{
	//Imprimir
	for(int i=0;i<alumnoVector.rows();i++)
	{
		cout<<alumnoVector.get(i).getCodigo()<<"-"<<alumnoVector.get(i).getNombre()<<"\n";
	}
	system("pause");
	system("cls");
}
