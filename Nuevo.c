#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int in_calculo();
int in_manual_de_usuario();
int in_resultados();
float fl_variables_calcular();
/* Manejo de archivos en lenguaje c */
/* Lectura de archivos */
/* Flujo de datos FILE */

/* PROGRAMA -> CANAL -> DISCO_DURO -- Escritura */
/* PROGRAMA <- CANAL(FLUJO DE DATOS) <- DISCO_DURO -- LECTURA */
int main(){
	int jm;
	char c_jm; //Char almacena el caracter que el usuario oprimio

	do{
            //Definimos como apareceran los apartados en nuestro proyecto
		printf("1.Manual de usuario\n");

		printf("2.Calculo Gasto Cardiaco\n");

		printf("3.Resultados \n");

		printf("4.Salir \n");

		scanf("%i", &jm);

		switch(jm){ //evalua el caracter para hacer lo indicado
			case 1:
			    in_manual_de_usuario();
			break;

			case 2:
			    in_calculo();
            break;

            case 3:
                in_resultados();
            break;

			case 4:
			printf("Usted ha salido del programa \n");
			break;
			default:
			printf("No se ha tecleado ninguna opcion valida");
		}
	}while(jm != 4);


	return 0;
}

int in_calculo(){
FILE * flujo = fopen("Jala.txt","rb"); //abrimos un flujo de datos con cierta informacion que sea solo de lectura en binario(rb)
if (flujo == NULL) {        //si es null se crea un error a la hora de abrir
    perror("Error en la apertura del archivo");
    return 1;
}
char ch_tabla_caracter; //Es un Byte de informacion. Almacena caracter por caracter del texto

while (feof(flujo) == 0){
        ch_tabla_caracter = fgetc(flujo); //recibe el flujo y regresa un caracter en la posicion actual del flujo de datos
        printf("%c", ch_tabla_caracter);
}

fclose(flujo); //libera la memoria utilizada
printf("\n\n Se ha leido el archivo correctamente..");

float n1,n2,GastoCardiaco;

printf("\nIngrese VS: ");
scanf("%f",&n1); //escanea el valor y lo almacena en la variable flotante
printf("\n");

printf("Ingrese FC: ");
scanf("%f",&n2);//escanea el valor y lo almacena en la variable flotante
//printf("n1=%f -- n2=%f",n1,n2);

GastoCardiaco=sqrt(pow(n1,2)*pow(n2,2)); //operación matematica
printf(" GastoCardiaco=%f \n",GastoCardiaco);


FILE* ark = fopen("resultados.txt","a"); //abrimos un flujo de datos con cierta informacion que sea de escritura(a)
if(ark == NULL){
    perror("Error en la creacion del archivo\n\n");

}else{
    int i, j;
    for(i = 0; i < 1; i++){
            for(j=0; j<1; j++){
            fprintf(ark," GastoCardiaco=%f \n",GastoCardiaco);// almacena los resultados del calculo en nuestro archivo "resultados.txt"

            }
fputc('\n',ark);
    }
    fflush(ark); //limpia el canal de informacion
    fclose(ark);//

    printf("Exito !!! \n");//cuando finalice genera un mensaje para corroborar
return 3;
}
return 1;
}

int in_manual_de_usuario(){
FILE * flujo = fopen("manualdeusuario.txt","rb"); //abrimos un flujo de datos con cierta informacion que sea solo de lectura en binario(rb)
if (flujo == NULL) {        //si es null se crea un error a la hora de abrir
    perror("Error en la apertura del archivo");
    return 1;
}
char ch_lectura_caracter; //Es un Byte de informacion. Almacena caracter por caracter del texto

while (feof(flujo) == 0){
        ch_lectura_caracter = fgetc(flujo); //recibe el flujo y regresa un caracter en la posicion actual del flujo de datos
        printf("%c", ch_lectura_caracter);
}

fclose(flujo); //libera la memoria utilizada
printf("\n\n Se ha leido el archivo correctamente.. \n");

return 2;

}




int in_resultados(){
FILE * flujo = fopen("resultados.txt","rb"); //abrimos un flujo de datos con cierta informacion que sea solo de lectura en binario(rb)
if (flujo == NULL) {        //si es null se crea un error a la hora de abrir
    perror("Error en la apertura del archivo");
    return 1;
}
char ch_resultados_caracter; //Es un Byte de informacion. Almacena caracter por caracter del texto

while (feof(flujo) == 0){
        ch_resultados_caracter = fgetc(flujo); //recibe el flujo y regresa un caracter en la posicion actual del flujo de datos
        printf("%c", ch_resultados_caracter);
}

fclose(flujo); //libera la memoria utilizada
printf("\n\n Se ha leido el archivo correctamente.. \n");

return 2;

}





















