#include<iostream>
#include<string>
#include<windows.h>
using namespace std; 

const int limite_contactos = 50; 

struct contactoEmail{
	string nombre;
	string sexo;
	int edad;
	int telefono;
	string email;
	string nacionalidad;
};


void eliminarContactos(contactoEmail contactos[], int &cantidadContactos, int indice){
	
	if(cantidadContactos==0){
		cout<<"No se ha registrado ningun contacto hasta el momento. "; 
	}
	
	if(indice >= 0 && indice < limite_contactos){
		for(int i=indice; i < cantidadContactos - 1; ++i){
			contactos[i]=contactos[i+1]; 
		}
		
		cantidadContactos--; 
		
		cout<<"\nEL CONTACTO SE ELIMINO SATISFACTORIAMENTE!\n"; 
		cout<<"\n"; 
		
	}
	else{
		cout<<"El indice ingresado no es valido. "; 
	}
}

void mostrarContactos(contactoEmail contactos[], int cantidadContactos){
	if(cantidadContactos == 0){
		cout<<"\nNingun contacto por mostrar. "<<endl;
	}
	else{
	   for(int i=0; i<cantidadContactos; ++i){
	   	cout<<"Contacto: "<<i+1<<" | "<<" -> "<<"INDICE: "<< i <<endl; 
	   	cout<<"Nombres completos: "<<contactos[i].nombre<<endl;
	   	cout<<"Sexo: "<<contactos[i].sexo<<endl; 
	   	cout<<"Edad: "<<contactos[i].edad<<endl; 
	   	cout<<"Telefono: "<<contactos[i].telefono<<endl; 
	   	cout<<"Email: "<<contactos[i].email<<endl; 
	   	cout<<"Nacionalidad: "<<contactos[i].nacionalidad<<endl; 
	   	cout<<"\n"; 
	   }
	}
}

string obtenerDominio(const string& email){
    int buscarroba=-1;
    for (int i=0;i<email.length();++i){
        if(email[i]=='@') {
            buscarroba=i;
            break;
        }
    }
    if(buscarroba == -1){
        return "";
    }
    string dominio = "";
    for(int i = buscarroba + 1; i<email.length();++i){
        dominio+=email[i];
    }
    return dominio;
}

void ordenServidor(contactoEmail contactos[], int cantidadContactos) {
    for (int i = 0; i<cantidadContactos - 1; ++i) {
        for (int j = 0; j<cantidadContactos - 1 - i; ++j) {
            if (obtenerDominio(contactos[j].email)>obtenerDominio(contactos[j + 1].email)){
                contactoEmail temp =contactos[j];
                contactos[j]=contactos[j + 1];
                contactos[j+1]=temp;
            }
        }
    }
}

int main(){
	
	contactoEmail cont[100];
	int contacontact=0;
	int contador_a=0;
	int i;
	char opcion, indice;
	SetConsoleOutputCP(CP_UTF8);
	int cantidadContactos=0;
	contactoEmail contactos[limite_contactos]; 

	
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
	     	//i=contador_a;
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
			int indice; 
		         cout<<"Ingrese el indice del contacto a eliminar."<<endl;
			 	cout<<"Tenga en cuenta que los indices inician desde el 0. Indice: "; 
		 	    cin>>indice; 
		    	eliminarContactos(contactos, cantidadContactos, indice); 
			break;	
	    case 'c':
	    		 mostrarContactos(contactos, cantidadContactos);  
				    break; 
	    	break;	
	    case 'd':
		if(cantidadContactos == 0){
			cout<<"\nNingun contacto por mostrar. "<<endl;
	}
     	    cout<<"\nMOSTRANDO CONTACTOS SEGUN EL ORDEN POR SERVIDOR: \n"; 
     	     
  		    ordenServidor(contactos, cantidadContactos); 
            mostrarContactos(contactos, cantidadContactos); 
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