/**
 * Proje: Otomatik Balık Yemleme Sistemi
 * Yazar: Gökhan Kapucuoğlu
 * Açıklama: 28BYJ-48 step motor kullanarak hassas kontrollü yemleme sistemi.
 * Versiyon: 1.0.0
 */

#include <Arduino.h>

// --- Yapılandırma Ayarları ---
const int STEP_DELAY_MS = 3;         // Adımlar arası bekleme süresi (Hız ayarı)
const int STEPS_PER_ROTATION = 512;  // 360 derecelik tam tur için gereken standart değer
const int FEEDING_AMOUNT = 32;       // Yemleme miktarı (Döngü sayısı ile ayarlanır)

// Pin Tanımlamaları (Daha temiz bir kurulum için dizi/array kullanımı)
const int motorPins[] = {7, 6, 5, 4}; // Sırasıyla: IN1, IN2, IN3, IN4

// --- Fonksiyon Prototipleri ---
void executeStepSequence();

void setup() {
    // Tüm motor pinlerini döngü kullanarak ÇIKIŞ (OUTPUT) olarak başlat
    for (int i = 0; i < 4; i++) {
        pinMode(motorPins[i], OUTPUT);
    }
}

void loop() {
    // Yemleme rotasyonunu başlat
    for (int i = 0; i < FEEDING_AMOUNT; i++) {
        executeStepSequence();
    }

    /** * Yemleme Aralığı (Bekleme Süresi)
     * 1.000 ms = 1 saniye
     * 3.600.000 ms = 1 saat
     * 86.400.000 ms = 24 saat
     * Şu an test için 1 saniye ayarlanmıştır.
     */
    delay(1000); 
}

/**
 * 28BYJ-48 step motor için tek bir 4-adımlı sekans çalıştırır
 */
void executeStepSequence() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(motorPins[i], HIGH);
        delay(STEP_DELAY_MS);
        digitalWrite(motorPins[i], LOW);
    }
}