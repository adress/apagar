#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {

    if (argc == 1) {
    	
        printf("Nombre del Programa: %s", argv[0]);
        printf("\nDebe inicar el tiempo para apagar el equipo");
        
    } else if (argc == 2) {
    	
        if (strcmp(argv[1], "cancelar") == 0) {
            system("shutdown -a");
            printf("Apagado cancelado");
        }else{
        	printf("Argumento invalido");
		}
		
    } else if (argc == 3) {
    	//validar desbordamiento
        int seconds = atoi(argv[1]);
        
        if (strcmp(argv[2], "s") == 0) {
            seconds *= 1;
        } else
        if (strcmp(argv[2], "m") == 0) {
            seconds *= 60;
        } else
        if (strcmp(argv[2], "h") == 0) {
            seconds *= 3600;
        } else
        if (strcmp(argv[2], "d") == 0) {
            seconds *= 86400;
        } else{
        	printf("\nArgumento de tiempo invalido");
        	return 0;
		}
        
        //shutdown -s -t 2419200 +/- segundos de 1 mes
        char buf[22];
        snprintf(buf, 22, "shutdown -s -t %d", seconds);
        //printf("\nCantidad de segundos %s", buf);
        system(buf);

    } else {
        printf("\ncantidad de argumentos invalidos");
    }
    
    return 0;
}
