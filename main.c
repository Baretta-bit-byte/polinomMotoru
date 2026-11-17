#include <stdio.h>
#include <math.h>
#include "polynomial.h"

static int passed = 0, failed = 0;

#define CHECK(cond, name) do { \
    if (cond) { printf("[OK]   %s\n", name); passed++; } \
    else      { printf("[FAIL] %s\n", name); failed++; } \
} while (0)

#define NEAR(a, b) (fabs((a) - (b)) < 1e-9)

int main(void) {
    /* Test 1: karisik sirada ekleme -> 3x^2 + 2x + 1 */
    Polynomial *p = poly_create();
    CHECK(p != NULL, "create: NULL donmemeli");
    if (p == NULL) { printf("Once poly_create'i yaz.\n"); return 1; }

    CHECK(poly_term_count(p) == 0, "bos polinom 0 terimli");
    CHECK(NEAR(poly_evaluate(p, 5.0), 0.0), "sifir polinom her x'te 0");

    poly_add_term(p, 1, 0);
    poly_add_term(p, 3, 2);
    poly_add_term(p, 2, 1);
    printf("p = "); poly_print(p);
    CHECK(poly_term_count(p) == 3, "3 terim eklendi");
    CHECK(p->head && p->head->exp == 2, "liste azalan sirada (bas us = 2)");
    CHECK(NEAR(poly_evaluate(p, 2.0), 17.0), "p(2) = 17");

    /* Test 2: duplicate birlestirme ve sifirlanan terimin silinmesi */
    poly_add_term(p, 2, 1);               /* 4x */
    CHECK(poly_term_count(p) == 3, "ayni us birlestirildi");
    poly_add_term(p, -4, 1);              /* 0x -> silinmeli */
    CHECK(poly_term_count(p) == 2, "katsayisi 0 olan terim silindi");
    CHECK(NEAR(poly_evaluate(p, 2.0), 13.0), "3x^2 + 1 -> p(2) = 13");

    /* Test 3: toplama */
    Polynomial *q = poly_create();
    poly_add_term(q, 1, 2);
    poly_add_term(q, -1, 0);
    Polynomial *s = poly_add(p, q);       /* (3x^2+1) + (x^2-1) = 4x^2 */
    printf("p + q = "); poly_print(s);
    CHECK(s && poly_term_count(s) == 1, "toplama: 1 terim kaldi");
    CHECK(s && NEAR(poly_evaluate(s, 3.0), 36.0), "toplama: 4x^2 -> s(3) = 36");

    /* Test 4: carpma (x+1)(x-1) = x^2 - 1 */
    Polynomial *a = poly_create();
    Polynomial *b = poly_create();
    poly_add_term(a, 1, 1); poly_add_term(a, 1, 0);
    poly_add_term(b, 1, 1); poly_add_term(b, -1, 0);
    Polynomial *m = poly_multiply(a, b);
    printf("(x+1)(x-1) = "); poly_print(m);
    CHECK(m && poly_term_count(m) == 2, "carpma: ara terimler birbirini goturdu");
    CHECK(m && NEAR(poly_evaluate(m, 3.0), 8.0), "carpma: m(3) = 8");

    /* Test 5: turev: d/dx (3x^2 + 2x + 1) = 6x + 2 */
    Polynomial *r = poly_create();
    poly_add_term(r, 3, 2); poly_add_term(r, 2, 1); poly_add_term(r, 1, 0);
    Polynomial *d = poly_derivative(r);
    printf("r' = "); poly_print(d);
    CHECK(d && NEAR(poly_evaluate(d, 2.0), 14.0), "turev: r'(2) = 14");

    /* Test 6: seyrek polinom (us bosluklu) 2x^5 + 7 */
    Polynomial *sp = poly_create();
    poly_add_term(sp, 2, 5); poly_add_term(sp, 7, 0);
    CHECK(NEAR(poly_evaluate(sp, 2.0), 71.0), "seyrek: 2x^5 + 7 -> sp(2) = 71");

    poly_free(p); poly_free(q); poly_free(s); poly_free(a); poly_free(b);
    poly_free(m); poly_free(r); poly_free(d); poly_free(sp);

    printf("\n%d basarili, %d basarisiz\n", passed, failed);
    return failed ? 1 : 0;
}
