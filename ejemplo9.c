#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    system("clear");

    int i, n;

    printf("Ejecutando el programa invocador (Ejercicio 9). Sus argumentos son:\n");
    for (i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);

    printf("\nIntroduce la cantidad de argumentos que deseas enviar: ");
    scanf("%d", &n);

    char *argv2[n + 2];
    char arg[n][20];

    for (i = 0; i < n; i++){
        printf("Argumento [%d]: ", i + 1);
        scanf("%s", arg[i]);
    }

    argv2[0] = "./ejemplo8";

    for (i = 0; i < n; i++){
        argv2[i + 1] = arg[i];
    }

    argv2[n + 1] = NULL;

    if (execv("./ejemplo8", argv2) < 0) {
        printf("Error en la invocacion del Ejercicio-8\n");
        exit(1);
    }

    return 0;
}
