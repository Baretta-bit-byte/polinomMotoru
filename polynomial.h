#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/*
 * Seyrek polinom: sadece katsayisi 0 olmayan terimler tutulur.
 *
 * DEGISMEZ KURALLAR (invariants) - tum fonksiyonlar bunlara uymali:
 *   1. Liste us (exp) degerine gore AZALAN sirada tutulur.
 *   2. Ayni usse sahip iki terim olamaz (varsa birlestirilir).
 *   3. Katsayisi 0 olan terim listede bulunamaz.
 *   4. Bos liste (head == NULL) sifir polinomu temsil eder.
 */

typedef struct Term {
    double coef;
    int exp;
    struct Term *next;
} Term;

typedef struct {
    Term *head;
} Polynomial;

/* Bos (sifir) polinom olusturur. */
Polynomial *poly_create(void);

/* Polinomun tum dugumlerini ve polinomun kendisini serbest birakir. */
void poly_free(Polynomial *p);

/* coef * x^exp terimini ekler. Ayni us varsa katsayilar toplanir;
 * toplam 0 olursa terim silinir. Degismez kurallari korumalidir. */
void poly_add_term(Polynomial *p, double coef, int exp);

/* Polinomdaki terim sayisini dondurur. */
int poly_term_count(const Polynomial *p);

/* a + b -> YENI bir polinom. a ve b degismez. */
Polynomial *poly_add(const Polynomial *a, const Polynomial *b);

/* a * b -> YENI bir polinom. a ve b degismez. */
Polynomial *poly_multiply(const Polynomial *a, const Polynomial *b);

/* p'nin turevi -> YENI bir polinom. */
Polynomial *poly_derivative(const Polynomial *p);

/* p(x) degerini Horner yontemiyle hesaplar. */
double poly_evaluate(const Polynomial *p, double x);

/* Okunabilir bicimde yazdirir (hazir verildi). */
void poly_print(const Polynomial *p);

#endif
