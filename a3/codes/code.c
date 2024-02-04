#include <stdio.h>
#include <math.h>

void linespace(int start, int stop, int step, int* n_values, double* x_values, double* y_values, int num_values) {
    for (int i = 0; i < num_values; ++i) {
        n_values[i] = start + i * step;
        // Let the values of y(0) be 5 and d_y be 10.
        y_values[i] = 5 + n_values[i]*10; 
        //corresponding values of x(0) = 8.0/15 and d_x = 38.0/75
        x_values[i] = 8.0/15 + n_values[i]*38.0/75;
    }
}

int main() {
    // Define the range and step size
    int start = 0;
    int stop = 5;
    int step = 1;

    // Calculate the number of values in the range
    int num_values = (stop - start) / step + 1;

    // Allocate arrays to store the generated values
    int n_values[num_values];
    double x_values[num_values];
    double y_values[num_values];

    // Call the linespace function
    linespace(start, stop, step, n_values, x_values, y_values, num_values);

    // Save data to a file
    FILE* file = fopen("output.dat", "w");

    if (file != NULL) {
        for (int i = 0; i < num_values; ++i) {
            fprintf(file, "%d %.2lf %.2lf\n", n_values[i], x_values[i], y_values[i]);
        }

        fclose(file);
        printf("Data saved to 'output.dat'.\n");
    } else {
        printf("Error opening file for writing.\n");
    }

    return 0;
}

