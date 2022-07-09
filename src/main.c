#include <stdio.h>
#include "Integral.h"
#include "DString.h"

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

int main() {

    printf("Hey\n");

    teste_integrate();
    teste_dstring();

    return 0;
}
