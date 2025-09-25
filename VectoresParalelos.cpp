#include <iostream>

int main(){

//declarar arrays y variables
int codigo[100];
std::string nombre[100];
int stock[100];
float precio[100];

bool continuar=true;
int opcion;
int codigoBuscado;
int tamaño=5;
int valor_maximo=0;
bool encontrado=false;
int indice;
int existencias;
int nueva_existencia;

//asignar valores de 5 productos
codigo[0]=101;
nombre[0]="Tornillo";
stock[0]=100;
precio[0]=20;

codigo[1]=102;
nombre[1]="Clavo";
stock[1]=78;
precio[1]=14;

codigo[2]=103;
nombre[2]="Cemento";
stock[2]=67;
precio[2]=350;

codigo[3]=104;
nombre[3]="Lámpara";
stock[3]=45;
precio[3]=79;

codigo[4]=105;
nombre[4]="Pintura";
stock[4]=23;
precio[4]=90;
//ciclo do  while para repetir el menú hasta que decida salir
do{
std::cout << std::endl;
std::cout << "--Sistema de inventario El Martillo--" << std::endl;
std::cout << "--Selecciona una opción--" << std::endl;
std::cout << "1. Consultar un producto por código" << std::endl;
std::cout << "2. Actualizar inventario" << std::endl;
std::cout << "3. Generar reporte de inventario" <<  std::endl;
std::cout << "4. Mostrar el producto más caro" << std::endl;
std::cout << "5. Salir" << std::endl;
std::cout << "Opción: ";
std::cin>>opcion;
//ciclo switch para las opciones del menú
switch(opcion) {

case 1:{
std::cout<<"Ingrese el código del producto"<<std::endl;
std::cin>>codigoBuscado;
for(int i=0; i<tamaño;i++){ //for para recorrer todas las posiciones del arreglo
if (codigo[i]==codigoBuscado){
	std::cout<<"Producto: "<<nombre[i]<<" | Código:"<<codigo[i]<<" | Precio: "<<precio[i]<<" | Existencias:"<<stock[i] <<std::endl; 
        encontrado=true; //bandera para indicar que se encontro el código del producto
	break;
	 }
    }
 if (!encontrado) {
        std::cout << "El producto no existe" << std::endl;
    }
}


break;

case 2: {
std::cout << "Ingrese el código del producto a actualizar: ";
std::cin >> codigoBuscado;

for (int i = 0; i < tamaño; i++) {
     if (codigo[i] == codigoBuscado) {
       encontrado = true;
       std::cout << "El producto a actualizar es: " << nombre[i] << std::endl;
       std::cout << "Ingrese la cantidad de existencias para agregar o restar al producto: ";
       std::cin >> existencias;
       int nueva_existencia = stock[i] + existencias; //suma del stock anterior y las existencias nuevas
            if (nueva_existencia >= 0) {
                stock[i] = nueva_existencia;
                std::cout << "Actualizado con éxito. Número de existencias actual: "<< stock[i] << std::endl;
            } else {
                std::cout << "Error: el número de existencias no puede ser menor a cero." << std::endl;
            }
            break;
        }
    }

if (!encontrado) {
std::cout << "El producto con código no existe." << std::endl;
    }
}
break;


case 3:{
std::cout<<"--Inventario:--"<<std::endl;
for(int i=0; i<tamaño;i++){ //ciclo for que imprimer todos los arreglos
std::cout<<"| Producto:"<<nombre[i]<<"		| Código:"<<codigo[i]<<"	| Precio:"<<precio[i]<<"	| Stock:"<<stock[i]<< std::endl;
}
}
break;

case 4:{
for(int i=0; i<tamaño;i++){
if (precio[i]>valor_maximo){
	valor_maximo=precio[i];
	indice=i; //guarda el indice para poder acceder al mismo indice de los otros arreglos
        }
    }
}
std::cout<<"El producto más caro es: "<< nombre[indice]<< " y su precio es: "<< precio[indice] <<std::endl;

break;

case 5:{
std::cout<<"Saliste del sistema de inventario" << std::endl;
continuar=false; //bandera que indica que el do while debe de terminar
}

break;

default: //mensaje de error si ingresa una opción no válida
std::cout << "Opción no válida"<<std::endl;
break;
}
//do while que repite el menu mientras que la bandera continuar sea cierta
}while(continuar);


return 0;
}

