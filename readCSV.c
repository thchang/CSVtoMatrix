#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function: readCSV
 * -----------------
 * read a nXm matrix from a CSV file into a flat array in row-major ordering
 *
 * n: the number of rows
 *
 * m: the number of cols
 *
 * fp: pointer to FILE object for the CSV file containing (one row per line)
 *
 * mat: pointer to a block of memory of size sizeof(double)*n*m, into which
 *      the matrix will be loaded on output
 */
void readCSV(int n, int m, FILE *fp, double *mat) {
    // Declare tokens and buffers
    char line[4096];
    char *token;
    // Read m lines of the file
    for (int i = 0; i < n; i++) {
        // Read a line from the file
        fscanf(fp, "%s", line);
        token = strtok(line, ",");
        // Parse the line into a row of mat
        for (int j = 0; j < m; j++) {
		    mat[i*m + j] = strtod(token, NULL);
            token = strtok(NULL, ","); // Trick to strip each entry off
        }
    }
    return;
}

/*
 * Driver code
 * -----------
 * Reads in matrix dimensions and the path to an input CSV files from the
 * command line, extracts the matrix from the file, stores in row-major
 * ordering, and prints it back out.
 *
 * Accepts 3 command line arguments:
 *
 * argv[1]: the number of rows in the matrix
 *
 * argv[2]: the number of cols in the matrix
 *
 * argv[3]: the relative/absolute path to a CSV file containing the
 *          matrix
 */
int main(int argc, char *argv[]) {
    // Declare file pointers and arrays
    FILE *fp;
	double *mat;
    // Check the command line args
    if (argc != 4) {
        printf("Error! 3 command line args expected!\n");
        return -1;
    }
    // Read problem dimensions
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    // Allocate memory for f and x
    mat = (double *) malloc(n * m * sizeof(double));
    // Open file
    if ((fp = fopen(argv[3], "r")) == NULL) {
        printf("Error! Could not open %s\n", argv[3]);
        return -2;
    }
	// Read the CSV file into a matrix
    printf("\nReading matrix from %s...\n", argv[3]);
	readCSV(n, m, fp, mat);
	// Close the file
    fclose(fp);
    // Print the matrix to stdout
    printf("\nThe matrix is:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf", mat[i*m + j]);
            if (j < m - 1)
                printf(", ");
            else
                printf("\n");
        }
    }
    printf("\n");
    // Free memory and return
	free(mat);
    return 0;
}
