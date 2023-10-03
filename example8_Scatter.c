#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int myid, npes;
    float message[2]; // Changez le type de données en float et la taille du tableau en 2
    float *vector;
    float vector_rec[2]; // Changez la taille du tableau en 2

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &npes);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    if (myid == 0) {
        vector = (float *)malloc(2 * npes * sizeof(float)); // Modifiez la taille d'allocation
        for (int i = 0; i < 2 * npes; i++) { // Modifiez la plage de la boucle
            vector[i] = (float)i * 10.0 + 1.0; // Changez les valeurs de données
        }
    }
    else {
        vector = (float *)malloc(2 * sizeof(float)); // Modifiez la taille d'allocation
    }

    MPI_Scatter(vector, 2, MPI_FLOAT, vector_rec, 2, MPI_FLOAT, 0, MPI_COMM_WORLD); // Changez le type de données et la taille

    printf("Je suis %d, vector_rec : %.2f %.2f\n", myid, vector_rec[0], vector_rec[1]); // Changez le format d'affichage

    free(vector); // Libérez la mémoire allouée dynamiquement
    MPI_Finalize();
}



