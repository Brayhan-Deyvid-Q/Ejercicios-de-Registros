#include<iostream>
#include<string>
#include<windows.h>
using namespace std; 

struct contactoEmail{
	string nombre;
	string sexo;
	int edad;
	int telefono;
	string email;
	string nacionalidad;
};


int main(){
	
	contactoEmail cont;
	char opcion;
	SetConsoleOutputCP(CP_UTF8);
	
	cout<<"\nBienvenido a Email\n";
	cout<<"a) Agregar un contacto"<<endl
	    <<"b) Eliminar un contacto"<<endl
	    <<"c) Lista de contactos registrados recientemente"<<endl
	    <<"d) Lista de contactos existentes"<<endl
	    <<"e) Salir"<<endl<<endl;
	cout<<"Opción: ";
	cin>>opcion;
	
	switch(opcion){
		case 'a': 
		cout<<"Ingrese el nombre completo del contacto: ";
		cin.ignore();
		getline(cin, cont.nombre);
		cout<<"Sexo (masculino/femenino): ";
		cin>>cont.sexo;
		cout<<"Ingrese la edad: ";
		cin>>cont.edad;
		cout<<"Ingrese el número de teléfono: ";
		cin>>cont.telefono;
		cout<<"Ingrese la dirección de correo electrónico: ";
		cin>>cont.email;
		cout<<"Ingrese la nacionalidad: ";
		cin>>cont.nacionalidad;
		
		cout<<"\nDatos del nuevo contacto:\n";
		cout<<"Nombre: "<<cont.nombre<<endl
		    <<"Sexo: "<<cont.sexo<<endl
		    <<"Edad: "<<cont.edad<<endl
		    <<"Número: "<<cont.telefono<<endl
		    <<"Email: "<<cont.email<<endl
		    <<"Nacionalidad: "<<cont.nacionalidad<<endl;
		    
		    break;
		    
		case 'b':
			break;
			
	    case 'c':
	    	break;
	    	
	    case 'd':
	    	break;
	    	
	    case 'e':
	    	break;
	    	
	    default:
	    	cout<<"Error: Opción no válida";
	    	break;
	}
	
	return 0;
}