//Crearemos un programa de calculadora pero que sea con funciones y menu switch pero tambien tendra que tener una parte de administrador donde pida contraseña y si es correcta te deje cerrar el programa y si no te diga que la contraseña es incorrecta y te vuelva a pedir la contraseña

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

//Variables globales
int opcion = 0;

// Contraseña de administrador (cambia esto por tu contraseña real)
char password[] = "1234";

// Prototipos de funciones
void suma();
void resta();
void multiplicacion();
void division();
void potencia();
void raiz();
void salir();
void apagar_sistema(); // función para apagar el sistema
int administrador(); //función para el inicio de sesión del administrador

//Función para el menú
void menu() {
    printf("1.- Suma\n");
    printf("2.- Resta\n");
    printf("3.- Multiplicación\n");
    printf("4.- División\n");
    printf("5.- Potencia\n");
    printf("6.- Raíz\n");
    printf("7.- Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            suma();
            break;
        case 2:
            resta();
            break;
        case 3:
            multiplicacion();
            break;
        case 4:
            division();
            break;
        case 5:
            potencia();
            break;
        case 6:
            raiz();
            break;
        case 7:
            salir();
            break;

        default:
            printf("Opción no válida. Intente de nuevo.\n");
            break;
    }
    printf("Presione Enter para continuar...");
    while (getchar() != '\n'); // Consumir caracteres adicionales hasta que se presione Enter
    getchar(); // Esperar a que se presione Ent
}

//Funciones para las operaciones
void suma(){
    float sum[3] = {0, 0, 0};
    printf("Ingrese el primer sumando: ");
    scanf("%f", &sum[0]);
    printf("Ingrese el segundo sumando: ");
    scanf("%f", &sum[1]);
    sum[2] = sum[0] + sum[1];
    printf("El resultado de la suma es: %.2f\n", sum[2]);
}
void resta(){
    float resta[3] = {0, 0, 0};
    printf("Ingrese el minuendo: ");
    scanf("%f", &resta[0]);
    printf("Ingrese el sustraendo: ");
    scanf("%f", &resta[1]);
    resta[2] = resta[0] - resta[1];
    printf("El resultado de la resta es: %.2f\n", resta[2]);
}
void multiplicacion(){
    float multi[3] = {0, 0, 0};
    printf("Ingrese el primer factor: ");
    scanf("%f", &multi[0]);
    printf("Ingrese el segundo factor: ");
    scanf("%f", &multi[1]);
    multi[2] = multi[0] * multi[1];
    printf("El resultado de la multiplicación es: %.2f\n", multi[2]);
}
void division(){
    float division[3] = {0, 0, 0};
    printf("Ingrese el dividendo: ");
    scanf("%f", &division[0]);
    printf("Ingrese el divisor: ");
    scanf("%f", &division[1]);
    division[2] = division[0] / division[1];
    printf("El resultado de la división es: %.2f\n", division[2]);
}
void potencia(){
    float potencia[3] = {0, 0, 0};
    printf("Ingrese la base: ");
    scanf("%f", &potencia[0]);
    printf("Ingrese el exponente: ");
    scanf("%f", &potencia[1]);
    potencia[2] = pow(potencia[0], potencia[1]);
    printf("El resultado de la potencia es: %.2f\n", potencia[2]);
}
void raiz(){
    double raiz[2] = {0, 0};
    double raiz2 = 0;
    printf("Ingrese el radicando: ");
    scanf("%lf", &raiz[0]);
    printf("Ingrese el índice: ");
    scanf("%lf", &raiz[1]);

    if (raiz[1] != 0) {
        raiz2 = pow(raiz[0], 1.0 / raiz[1]);
        printf("El resultado de la raíz es: %.2lf\n", raiz2);
    } else {
        printf("El índice debe ser diferente de cero (0).\n");
    }
}
//Función para salir del sistema
void salir(){
    int modo_admin_s = 0;

    //Ciclo para salir del sistema
    modo_admin_s = administrador();

    if(modo_admin_s) {
        while(1){
            apagar_sistema();
        }
    } else {
        printf("Contraseña incorrecta\n");
        menu();
    }
}

int administrador(){
    char pass[20];
    int intentos = 0;
    do{
        printf("Ingrese la contraseña: ");
        scanf("%s", pass);
        if(strcmp(pass, password) == 0){
            printf("Contraseña correcta\n");
            return 1;
        }else{
            printf("Contraseña incorrecta\n");
            intentos++;
        }
    }while(intentos < 3);
    printf("Ha excedido el número de intentos permitidos\n");
    return 0;
}
//Función para apagar el sistema
void apagar_sistema (){
    printf("Apagando el sistema...\n");
    exit(1);
}

//Funcion principal
int main(){
    printf("\t\t\t\n Bienvenido a el Sistema de Calculos\n");
    int modo_admin = 0;

    //Ciclo para el inicio de sesión del administrador
    modo_admin = administrador();

    if(modo_admin) {
        while(1){
            menu();
    }
    } else {
        apagar_sistema();
    }
    return 0;
}