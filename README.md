# CSVtoMatrix

One day I needed to load a matrix from a CSV file into a C array.
I looked around the internet to borrow someone else's solution, but
I couldn't easily find an existing solution for this simple and
common task, which I think is surprising. (I'm sure someone has
posted about this before, I just couldn't easily find it). So I 
wrote my own solution. Maybe the next guy/gal will find this and
save an hour :)

Note, there is no support for white spaces, this is just a simple demo...

```
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
void readCSV(int n, int m, FILE *fp, double *mat)
```

## Contents

There are 4 files:
 * `README.md` is this file
 * `readCSV.c` is the source file
 * `matrix.csv` is a sample matrix
 * `Makefile` is a sample GNU makefile
