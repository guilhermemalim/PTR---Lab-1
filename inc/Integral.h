// Guilherme Matheus - 21950880
#ifndef _INTEGRAL_H_
#define _INTEGRAL_H_

#define DELTA_0 0.0001

typedef double (*F_integravel)(double);

double _area_trapezio(double a, double b, double h);

/*
    @param double a :: limite inferior
    @param double b :: limite superior
    @param int metodo |>
                        0 -> trapézio
                        <> 0 :: (não implementado)
    @param double delta
*/
double integrate(F_integravel f, double a, double b);

#endif
