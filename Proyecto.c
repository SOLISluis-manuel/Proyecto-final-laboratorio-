#include <stdio.h>

#define NUM_APARATOS 10
#define NUM_COMPONENTES 100

// Estructura para almacenar la información de cada aparato
typedef struct {
    int componentes[NUM_COMPONENTES];
    int num_componentes;
    int unidades_mensuales;
} Aparato;

// Función para leer la información de los componentes de cada aparato
void leerComponentes(Aparato aparatos[]) {
    for (int i = 0; i < NUM_APARATOS; i++) {
        printf("Aparato %d:\n", i + 1);
        printf("Ingrese el número de componentes: ");
        scanf("%d", &aparatos[i].num_componentes);

        printf("Ingrese los identificadores de los componentes:\n");
        for (int j = 0; j < aparatos[i].num_componentes; j++) {
            printf("Componente %d: ", j + 1);
            scanf("%d", &aparatos[i].componentes[j]);
        }
    }
}

// Función para leer las unidades mensuales de cada aparato
void leerUnidadesMensuales(Aparato aparatos[]) {
    for (int i = 0; i < NUM_APARATOS; i++) {
        printf("Ingrese el número de unidades mensuales para el aparato %d: ", i + 1);
        scanf("%d", &aparatos[i].unidades_mensuales);
    }
}

// Función para calcular el total de componentes requeridos cada mes
void calcularComponentesTotales(Aparato aparatos[], int total_componentes[]) {
    for (int i = 0; i < NUM_COMPONENTES; i++) {
        total_componentes[i] = 0;
    }

    for (int i = 0; i < NUM_APARATOS; i++) {
        for (int j = 0; j < aparatos[i].num_componentes; j++) {
            int componente = aparatos[i].componentes[j];
            total_componentes[componente] += aparatos[i].unidades_mensuales;
        }
    }
}

// Función para encontrar el componente más utilizado
int componenteMasUtilizado(int total_componentes[]) {
    int max_componente = 0;
    int max_uso = total_componentes[0];

    for (int i = 1; i < NUM_COMPONENTES; i++) {
        if (total_componentes[i] > max_uso) {
            max_uso = total_componentes[i];
            max_componente = i;
        }
    }
    return max_componente;
}

int main() {
    Aparato aparatos[NUM_APARATOS];
    int total_componentes[NUM_COMPONENTES];

    // Lectura de componentes de cada aparato
    leerComponentes(aparatos);

    // Lectura de unidades mensuales de cada aparato
    leerUnidadesMensuales(aparatos);

    // Cálculo del total de componentes requeridos cada mes
    calcularComponentesTotales(aparatos, total_componentes);

    // Mostrar el total de cada componente necesario
    printf("\nTotal de componentes necesarios cada mes:\n");
    for (int i = 0; i < NUM_COMPONENTES; i++) {
        if (total_componentes[i] > 0) {
            printf("Componente %d: %d unidades\n", i, total_componentes[i]);
        }
    }

    // Determinar el componente más utilizado
    int mas_utilizado = componenteMasUtilizado(total_componentes);
    printf("\nEl componente más utilizado es el %d con %d unidades al mes.\n",
           mas_utilizado, total_componentes[mas_utilizado]);

    return 0;
}
