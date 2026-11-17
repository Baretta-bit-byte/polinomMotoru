# Seyrek Polinom Yoneticisi (C)

Bagli liste uzerinde seyrek polinom (sadece sifirdan farkli terimler) tutan kucuk bir C projesi.
Veri Yapilari dersine paralel bir calisma projesi.

## Ozellikler
- Terim ekleme (us sirasini ve birlestirmeyi koruyarak)
- Toplama, carpma, turev
- Horner yontemiyle deger hesaplama

## Derleme ve calistirma
```
make run
```
(AddressSanitizer acik: bellek hatalari otomatik raporlanir.)

## Ilerleme
- [ ] poly_create / poly_free / poly_term_count
- [ ] poly_add_term
- [ ] poly_evaluate
- [ ] poly_derivative
- [ ] poly_add
- [ ] poly_multiply

## Sonraki fikirler
- poly_multiply karmasikligi analizi, Karatsuba / FFT
- Ayni yapinin C++ sinifi olarak yeniden yazimi
