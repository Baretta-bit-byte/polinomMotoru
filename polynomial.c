#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynomial.h"

/* ---------------- SENIN ISIN: TODO'lari doldur ---------------- */

Polynomial *poly_create(void) {
    /* TODO: malloc ile Polynomial ayir, head'i NULL yap.
     * Ipucu: malloc basarisiz olursa ne donmeli? */
    return NULL;
}

void poly_free(Polynomial *p) {
    /* TODO: Tum Term dugumlerini gez ve free et, sonra p'yi free et.
     * Ipucu: free(cur) yaptiktan sonra cur->next'e bakamazsin! */
    (void)p;
}

void poly_add_term(Polynomial *p, double coef, int exp) {
    /* TODO: Uc durumu dusun:
     *   (a) listenin basina eklenecek (en buyuk us ya da liste bos)
     *   (b) arada / sonda yeni dugum eklenecek
     *   (c) ayni us zaten var -> katsayilari topla; 0 olduysa dugumu SIL
     * Ipucu: coef == 0 gelirse hicbir sey yapma.
     * Ipucu: kayan noktali sayilarda 0 kontrolu icin fabs(x) < 1e-12 kullan.
     * Ipucu: "onceki dugumu" takip eden bir gosterici (prev) isini kolaylastirir. */
    (void)p; (void)coef; (void)exp;
}

int poly_term_count(const Polynomial *p) {
    /* TODO: Listeyi gez ve say. */
    (void)p;
    return -1;
}

Polynomial *poly_add(const Polynomial *a, const Polynomial *b) {
    /* TODO: Iki sirali listeyi birlestir (merge-sort'un merge adimi gibi).
     * Kolay yol: a ve b'nin her teriminini poly_add_term ile yeni polinoma ekle.
     * Zor/verimli yol: iki gostericiyle tek geciste birlestir. Once kolayi yap! */
    (void)a; (void)b;
    return NULL;
}

Polynomial *poly_multiply(const Polynomial *a, const Polynomial *b) {
    /* TODO: a'nin her terimini b'nin her terimiyle carp:
     *   katsayilar carpilir, uslar toplanir. Sonucu poly_add_term ile biriktir.
     * Dusun: bu algoritmanin karmasikligi nedir? */
    (void)a; (void)b;
    return NULL;
}

Polynomial *poly_derivative(const Polynomial *p) {
    /* TODO: c*x^n -> (c*n)*x^(n-1). Sabit terim (us 0) turevde kaybolur. */
    (void)p;
    return NULL;
}

double poly_evaluate(const Polynomial *p, double x) {
    /* TODO: Horner yontemi.
     * DIKKAT: seyrek listede usler atlayabilir (ornek: 3x^5 + 2).
     * Bir terimden siradakine gecerken us farki kadar x ile carpman gerekir.
     * Ipucu: Once pow() ile saf hali yaz, testleri gecir, sonra Horner'a cevir. */
    (void)p; (void)x;
    return 0.0;
}

/* ---------------- HAZIR: bunu yazman gerekmiyor ---------------- */

void poly_print(const Polynomial *p) {
    if (p == NULL) { printf("(NULL)\n"); return; }
    if (p->head == NULL) { printf("0\n"); return; }

    for (const Term *t = p->head; t != NULL; t = t->next) {
        double c = t->coef;
        if (t != p->head) {
            printf(c < 0 ? " - " : " + ");
            c = fabs(c);
        } else if (c < 0) {
            printf("-");
            c = fabs(c);
        }
        if (t->exp == 0)            printf("%g", c);
        else {
            if (fabs(c - 1.0) > 1e-12) printf("%g", c);
            printf("x");
            if (t->exp != 1) printf("^%d", t->exp);
        }
    }
    printf("\n");
}
