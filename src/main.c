// Guilherme Matheus - 21950880
// Odalisio Neto - 21950520

#include <stdio.h>
#include "Integral.h"
#include "DString.h"
#include "Matrix.h"

void teste_integrate() {
    printf("\n--- TESTE INTEGRAL ---\n");

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
    printf("\n--- TESTE DSTRING ---\n");

    char* s1 = "Teste_";
    printf("String base: %s\n", s1);
    DString *ds1 = create_dstring_from_char(s1);
    printf("DString criada a partir do char*: %s %d\n", get_dstring_buffer(ds1), ds1->size);

    char* s2 = "DString";
    printf("String base: %s\n", s2);
    DString *ds2 = create_dstring_from_char(s2);
    printf("DString criada a partir do char*: %s %d\n", get_dstring_buffer(ds2), ds2->size);

    DString *ds3 = concatenar_dstrings(ds1, ds2);
    printf("String concatenada: %s %d\n", get_dstring_buffer(ds3), get_dstring_size(ds3));

    destroyDString(ds1);
    destroyDString(ds2);
    destroyDString(ds3);
}

void teste_matrix() {
    printf("\n--- TESTE MATRIX ---\n");

    unsigned int nlins = 3, ncols = 3;

    // Teste de criação e apply
    void teste1() {
        printf("\n--- TESTE CRIACAO E APPLY ---\n");
        Matrix* m1 = matrix_ones(nlins, ncols);
        Matrix* m2 = matrix_zeros(nlins, ncols);
        Matrix* id = matrix_identity(nlins, ncols);

        printf("Matriz de 1s:\n");
        print_matrix(m1);

        printf("Matriz de 0s:\n");
        print_matrix(m2);

        printf("Matriz identidade:\n");
        print_matrix(id);

        double aplicacao(double a) {
            return 8*a;
        }

        Matrix* m3 = matrix_apply(aplicacao, m1);
        printf("Matriz resultante da aplicacao de 8x:\n");
        print_matrix(m3);

        matrix_free(m1);
        matrix_free(m2);
        matrix_free(m3);
        matrix_free(id);
    }

    // Teste de operações com escalar
    void teste2() {
        printf("\n--- TESTE DE OPERACOES COM ESCALAR ---\n");
        Matrix* m1 = matrix_ones(nlins, ncols);

        printf("Matriz de 1s:\n");
        print_matrix(m1);

        double c = 5;

        Matrix *m2 = matrix_sum_com_escalar(c, m1);
        printf("Resultado da soma +%lf:\n", c);
        print_matrix(m2);

        Matrix *m3 = matrix_dif_com_escalar(c, m1);
        printf("Resultado da subtração -%lf:\n", c);
        print_matrix(m3);

        Matrix *m4 = matrix_mul_com_escalar(c, m1);
        printf("Resultado da multiplicacao x%lf:\n", c);
        print_matrix(m4);

        matrix_free(m1);
        matrix_free(m2);
        matrix_free(m3);
        matrix_free(m4);
    }

    // Teste de operações com matrix
    void teste3() {
        printf("\n--- TESTE DE OPERACOES COM MATRIZ ---\n");
        Matrix* m1 = create_random_matrix(nlins, ncols);
        Matrix* m2 = create_random_matrix(nlins, ncols);

        printf("Matriz m1:\n");
        print_matrix(m1);

        printf("Matriz m2:\n");
        print_matrix(m2);

        MResponse rm3 = matrix_sum(m1, m2);
        Matrix* m3 = rm3.m;
        printf("Resultado da soma entre matrizes:\n");
        print_matrix(m3);

        MResponse rm4 = matrix_dif(m1, m2);
        Matrix* m4 = rm4.m;
        printf("Resultado da subtração entre matrizes:\n");
        print_matrix(m4);

        MResponse rm5 = matrix_mul(m1, m2);
        Matrix* m5 = rm5.m;
        printf("Resultado da multiplicacao entre matrizes:\n");
        print_matrix(m5);

        matrix_free(m1);
        matrix_free(m2);
        matrix_free(m3);
        matrix_free(m4);
        matrix_free(m5);
    }

    // Teste de determinante, matriz inversa e cofator
    void teste4() {
        printf("\n--- TESTE DE DETERMINANTE E MATRIZ INVERSA ---\n");
        Matrix* m1 = create_random_matrix(nlins, ncols);

        printf("Matriz m1:\n");
        print_matrix(m1);

        printf("Determinante de m1: %lf\n", matrix_det(m1));

        MResponse rm2 = matrix_inversa(m1);
        Matrix *m2 = rm2.m;

        printf("Matriz inversa de m1:\n");
        print_matrix(m2);

        Matrix *m3 = matrix_get_cofactor(m1, 0, 0);
        printf("Matriz cofator indice 0,0 de m1:\n");
        print_matrix(m3);

        matrix_free(m1);
        matrix_free(m2);
        matrix_free(m3);
    }

    // TODO arrumar o teste
    // Teste de matriz inversa com um zero na diagonal principal
    void teste5() {
        printf("\n--- TESTE MATRIZ INVERSA COM 0 NA DP ---\n");
        Matrix* m1 = create_random_matrix(nlins, ncols);
        VALUES(m1, 1, 1) = 0;
        
        MResponse response_inv = matrix_inversa(m1);
        Matrix *m2 = response_inv.m;

        printf("Matriz m1:\n");
        print_matrix(m1);

        printf("Matriz inversa:\n");
        print_matrix(m2);

        matrix_free(m1);
        matrix_free(m2);
    }

    teste1();
    teste2();
    teste3();
    teste4();
    teste5();
}

int main() {
    printf("Alunos: \n");
    printf("Guiherme Matheus - 21950880\n");
    printf("Odalisio Neto - 21950520\n");
    printf("\n");
    printf("Aplicando alguns testes nas ADTs criadas\n");

    teste_integrate();
    teste_dstring();

    teste_matrix();

    return 0;
}
