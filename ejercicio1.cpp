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


/*void eliminarContacto(contactoEmail cont[], int &n, int indice){
	if(indice>=0 && indice<n){
		for(int i=indice; i<n-1 ; ++i){
			cont[i]=cont[i+1];
		}
		n--;
	}else{
		cout<<"Índice no válido"<<endl;
	}
}*/

int main(){
	
	contactoEmail cont[100];
	int contacontact=0;
	int contador_a=0;
	int i;
	char opcion, indice;
	SetConsoleOutputCP(CP_UTF8);
	
	while(opcion != 'e'){
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
	     	i=contador_a;
	     	cout<<"Ingrese el nombre completo del contacto: ";
		    cin.ignore();
	    	getline(cin, cont[i].nombre);
		    cout<<"Sexo (masculino/femenino): ";
		    cin>>cont[i].sexo;
		    cout<<"Ingrese la edad: ";
	       	cin>>cont[i].edad;
		    cout<<"Ingrese el número de teléfono: ";
		    cin>>cont[i].telefono;
		    cout<<"Ingrese la dirección de correo electrónico: ";
		    cin>>cont[i].email;
		    cout<<"Ingrese la nacionalidad: ";
		    cin>>cont[i].nacionalidad;

	     	cout<<"\nDatos del nuevo contacto:\n";
	      	cout<<"Nombre: "<<cont[i].nombre<<endl
		        <<"Sexo: "<<cont[i].sexo<<endl
		        <<"Edad: "<<cont[i].edad<<endl
		        <<"Número: "<<cont[i].telefono<<endl
		        <<"Email: "<<cont[i].email<<endl
		        <<"Nacionalidad: "<<cont[i].nacionalidad<<endl;
		    contacontact++;
		    contador_a++;
		
		    break;  	  	  
	    case 'b':
			/*cout<<"Ingrese el índice del contacto a eliminar: ";
			cin>> indice;
			eliminarContacto(cont, contador_a, indice);
			cout<<"Contacto eliminado..."<<endl<<endl;*/
			break;	
	    case 'c':
	    		cout<<"\nDatos de los contactos registrados recientemente:\n";
	    	for(int i=0; i<contador_a; i++){
	    		cout<<"Contacto "<<i+1<<" : "<<endl;
		        cout<<"Nombre: "<<cont[i].nombre<<endl
		            <<"Sexo: "<<cont[i].sexo<<endl
     		        <<"Edad: "<<cont[i].edad<<endl
		            <<"Número: "<<cont[i].telefono<<endl
		            <<"Email: "<<cont[i].email<<endl
     		        <<"Nacionalidad: "<<cont[i].nacionalidad<<endl<<endl;
			}
	    	break;	
	    case 'd':	
	    	break;
	    case 'e':	
	    	break;
	    default:
	    	cout<<"Error: Opción no válida";
	    	break;
	}
 }
	return 0;
}