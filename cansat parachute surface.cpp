#include<iostream> // libreria entrada y salida de datos
#include<conio.h>  // libreria para poder utilizar la funcion exit();



float masa();//funcion para elegir la masa del cansat
float forma();//elige la forma y asigna un coeficiente de arrastre
float descentVelocity();//la velocidad a tener en cuenta durante el descenso
int repeat();


int main(){

	
	float mass = masa();//coger  el valor de la funcion masa y copiarlo a una variable nueva
	float shape = forma();//coger el valor del coeficiente de arrastre y copiarlo en una nueva variable
	float speed =	descentVelocity();//coger el valor retornado por la funcion descentvelocity()

	//formula para obtener el area, esta dividida en dos partes para evitar errores matematicos
	
	float area1 = 2.0* mass * 9.8;
	float area2 = (shape* speed*speed *1.2754 );
	float area = (area1/area2)*10000.0;
	std::cout<<"Area requerida para el paracaidas   "<<area<<"  centimetros cuadrados";
	repeat();//limpia la pantalla y repite todo el proceso
	return 0;
}


float masa(){
	float masa = .0;//inicializamos la masa a un decimal
	std::cout<<"Escribe la masa para tu CanSat(en kilogramos) = "<<std::endl;
	std::cin>>masa;
	//comprobamos que es un valor que cumple con las normas
	if(masa<.36 && masa>.29){
		std::cout<<"\nMasa elegida: "<<masa<<" kg"<<std::endl;
		return masa;
	}else{
	
	exit(0);
	}
}

float forma(){

    float dragCoefficient = 0;	//el valor de arrastre
	int shapeChoice= 0;// para elegir la forma
	std::cout<<"ELIGE LA FORMA DE  TU PARACAIDAS\n\n 1.HEXAGONAL\n 2.SEMI-ESFERICO\n 3.CRUZADO\n 4.PARAPENTE\n\n    ";
	std::cin>>shapeChoice;
	switch(shapeChoice){
		//asignamos un coeficiente a cada forma y lo imprimimos para tener constancia de lo que hemos elegido
		case 1:	dragCoefficient = .77;	
			std::cout<<"Forma elegida  HEXAGONAL";
				std::cout<<"\nCoeficiente de arrastre "<<dragCoefficient;
				break;
		case 2: dragCoefficient = .69;
				std::cout<<"Forma elegida  SEMI-ESFERICO";
				std::cout<<"\nCoeficiente de arrastre "<<dragCoefficient;
				break;
		case 3: dragCoefficient = .7;
				std::cout<<"Forma elegida  CRUZADO";
				std::cout<<"\nCoeficiente de arrastre "<<dragCoefficient;
				break;
		case 4: dragCoefficient = .92;
				std::cout<<"Forma elegida  PARAPENTE";
				std::cout<<"\nCoeficiente de arrastre "<<dragCoefficient;
				break;
		default: exit(0);
				break;
	}
	return dragCoefficient;//devolvemos el valor para poder utilizarlo posteriormente
}
float descentVelocity(){
	//funcion para elegir la velocidad a utilizar
	float velocity= .0;
	std::cout<<"\n\nELIGE LA VELOCIDAD QUE QUIERAS UTILIZAR DURANTE EL DESCENSO\n\nRECUERDA: UNA VELOCIDAD ELEVADA(11m/s) TE PERMITIRA RECOGER MENOS DATOS\n\nUNA VELOCIDAD REDUCIDA(8m/s) TE PERMITIRA RECOGER MAS DATOS\n\n";
	std::cout<<"AHORA ESCRIBE LA VELOCIDAD QUE DESEES UTILIZAR DURANTE EL DESCENSO, entre 8.0m/s y 11.0m/s\n ";
	std::cin>>velocity;
	//comprobamos que los valores están dentro de lo acceptable
	if(velocity>7.9 && velocity<11.1){
	std::cout<<"\nVelocidad de descenso elegida  "<<velocity<<"m/s\n";
		return velocity;	
	}else{
		exit (0);//terminamos el programa
	}
}

int repeat(){
	//limpia la pantalla y da la opcion de repetir todo, sino, sale del programa
	int repetition = 0;
	std::cout<<"\n\nPULSA 1 PARA VOLVER A INTRODUCIR DATOS O CUALQUIER TECLA PARA SALIR\n    ";
	std::cin>>repetition;
	if(repetition == 1){
		system("CLS");
		main();
	}else{
		exit(0);
	}
}
