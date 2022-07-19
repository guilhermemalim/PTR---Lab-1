#include <stdio.h>
#include "Integral.h"
#include "DString.h"
#include "Matrix.h"

void teste_integrate() {

    double t1(double a) {
        return a;
    }
    printf("Integral de y=x entre 0 e 10: %lf\n", integrate(t1, 0, 10));

    double t2(double a) {
        return a*a;
    }
    printf("Integral de y=x*x entre 0 e 10: %lf\n", integrate(t2, 0, 10));
}

void teste_dstring() {
    char* s1 = "Teste_";
    puts(s1);
    DString *ds1 = create_dstring_from_char(s1);
    printf("%d\n", ds1->size);
    puts(get_dstring_buffer(ds1));

    char* s2 = "DString";
    puts(s2);
    DString *ds2 = create_dstring_from_char(s2);
    printf("%d\n", ds2->size);
    puts(get_dstring_buffer(ds2));

    DString *ds3 = concatenar_dstrings(ds1, ds2);
    printf("%d\n", get_dstring_size(ds3));
    puts(get_dstring_buffer(ds3));

    destroyDString(ds1);
    destroyDString(ds2);
    destroyDString(ds3);
}

void teste_matrix() {
    unsigned int nlins = 3, ncols = 3;
    Matrix* m1 = matrix_ones(nlins, ncols);
    Matrix* id = matrix_identity(nlins, ncols);

    print_matrix(m1);
    printf("FIM\n");
    print_matrix(id);

    MResponse response1 = matrix_mul(m1, id);
    printf("FIM\n");
    print_matrix(response1.m);
    
    printf("Det m1: %lf\n", matrix_det(m1));
    printf("Det id: %lf\n", matrix_det(id));

    Matrix *m2 = create_random_matrix(4,4);
    printf("FIM\n");
    print_matrix(m2);
    printf("Det m2: %lf\n", matrix_det(m2));

    MResponse rm2_1 = matrix_inversa(m2);
    Matrix *m2_1 = rm2_1.m;
    printf("Erro na inversao: %d\n", rm2_1.erro);
    printf("FIM\n");
    print_matrix(m2_1);

    MResponse mul = matrix_mul(m2, m2_1);
    Matrix *m3 = mul.m;

    printf("FIM\n");
    print_matrix(m3);


    matrix_free(m1);
    matrix_free(id);
    matrix_free(m2);
    matrix_free(m2_1);
    matrix_free(m3);
}

int main() {

    printf("Hey\n");

    // teste_integrate();
    // teste_dstring();

    teste_matrix();

    return 0;
}
