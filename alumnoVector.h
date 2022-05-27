#include<vector>
#include<iostream>
#include<fstream>
#include"alumno.h"
using namespace std;
class AlumnoVector
{
	//Variables miembro
	private:
		vector<Alumno> vectorAlumno;
	public:
	//Constructor
		AlumnoVector(){			
			cargarDatosDelArchivoAlVector();
		}
	//Operaciones
		int getCorrelativo()
		{
			if(vectorAlumno.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorAlumno[vectorAlumno.size() - 1].getCodigo() + 1;
			}
		}
		void add(Alumno obj)
		{
			vectorAlumno.push_back(obj);
		}
		
		Alumno get(int pos)
		{
			return vectorAlumno[pos];
		}
		int rows()
		{
			return vectorAlumno.size();
		}	
		Alumno buscarPorCodigo(int codigo)
		{
			Alumno objError;
			objError.setNombre("Error");
			for(Alumno x:vectorAlumno)	
			{
				if(codigo == x.getCodigo())
				{
					return x;
				}
			}
			return objError;
		}	
		void remove(Alumno obj)
		{
			vectorAlumno.erase(vectorAlumno.begin() + getPostArray(obj));
		}
		int getPostArray(Alumno obj)
		{
			for(int i=0;i<vectorAlumno.size();i++)		
			{
				if(obj.getCodigo() == vectorAlumno[i].getCodigo())	
				{
					return i;
				}
			}
			return -1;
		}
		bool modificar(Alumno obj,string nom)
		{
			for(int i=0;i<vectorAlumno.size();i++)		
			{
				if(obj.getCodigo() == vectorAlumno[i].getCodigo())	
				{
					vectorAlumno[i].setNombre(nom);
					return true;
				}
			}
			return false;
		}
		void grabarEnArchivo(Alumno obj)
		{
			try
			{
				fstream archivoAlumno;
				archivoAlumno.open("alumnos.csv",ios::app);
				if(archivoAlumno.good())				
				{
					archivoAlumno<<obj.getCodigo()<<";"<<obj.getNombre()<<";"<<endl;
					archivoAlumno.close();
				}
				else
				{
					cout<<"Archivo en mal estado!!!";
				}
			}
			catch(exception e)			
			{
				cout<<"Ocurrio un error al grabar en el archivo";
			}
		}
	void grabarModificarEliminarArchivo()
	{	
		try
		{
			fstream archivoAlumnos;
			archivoAlumnos.open("alumnos.csv", ios::out);
			if (archivoAlumnos.is_open())
			{
				for (Alumno x : vectorAlumno)
				{
					archivoAlumnos << x.getCodigo() << ";" << x.getNombre() << ";" << "\n";
					
				}
				archivoAlumnos.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo";
		}
	}
		void cargarDatosDelArchivoAlVector()
		{
			try
			{
				int 	i;
				size_t	posi;//Cantidad Maxima
				string 	linea;
				string 	temporal[2];
				fstream archivoAlumno;
				archivoAlumno.open("alumnos.csv",ios::in);
				if(archivoAlumno.is_open())
				{
					while(!archivoAlumno.eof() && (getline(archivoAlumno,linea)))	
					{
							i = 0;
							while((posi = linea.find(";")) != string::npos) /*npos = -1*/
							{
								temporal[i]=linea.substr(0,posi);
								linea.erase(0,posi + 1);
								++i;
							}	
							Alumno obj;
							obj.setCodigo(std::stoi(temporal[0]));
							obj.setNombre(temporal[1]);
							
							add(obj);
					}
				}
				archivoAlumno.close();
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al momento de leer en el archivo!!!";
			}
		}					
};
