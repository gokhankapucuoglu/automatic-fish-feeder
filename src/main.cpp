/**
 * Project: Automatic Fish Feeder System / Otomatik Balık Yemleme Sistemi
 * Author: Gökhan Kapucuoğlu
 * Description: High torque continuous/daily stepper motor controller.
 * Açıklama: Yüksek torklu sürekli/günlük step motor kontrolcüsü.
 * Version: 1
 */

#include <Arduino.h>

// --- Configuration Settings / Yapılandırma Ayarları ---

// EN: Motor speed and coil charge time (3ms is ideal for high torque to overcome friction)
// TR: Motor hızı ve bobin dolum süresi (Sürtünmeyi yenmek ve güç için 3ms idealdir)
const int STEP_DELAY_MS = 3;         

// EN: Number of cycles for feeding amount (Used in real-world daily mode)
// TR: Yemleme miktarını belirleyen döngü sayısı (Günlük gerçek modda kullanılır)
const int FEEDING_AMOUNT = 32; 

// EN: Motor driver IN1, IN2, IN3, IN4 pins
// TR: Motor sürücü IN1, IN2, IN3, IN4 pinleri
const int motorPins[] = {7, 6, 5, 4}; 

// EN: 8-Step Half-Step Sequence matrix for maximum torque
// TR: Maksimum güç için 8-Adımlı Yarım Adım sekans matrisi
const int stepSequence[8][4] = {
  {1, 0, 0, 0}, 
  {1, 1, 0, 0}, 
  {0, 1, 0, 0}, 
  {0, 1, 1, 0}, 
  {0, 0, 1, 0}, 
  {0, 0, 1, 1}, 
  {0, 0, 0, 1}, 
  {1, 0, 0, 1}  
};

// EN: Main function to drive the motor one full 8-step sequence
// TR: Motoru bir tam 8-adımlı sekans döndüren ana fonksiyon
void executeStepSequence() {
    for (int stepIndex = 0; stepIndex < 8; stepIndex++) {
        for (int pinIndex = 0; pinIndex < 4; pinIndex++) {
            digitalWrite(motorPins[pinIndex], stepSequence[stepIndex][pinIndex]);
        }
        // EN: Wait for the motor to mechanically complete the step
        // TR: Motorun adımı fiziksel olarak atması için bekle
        delay(STEP_DELAY_MS); 
    }
}

// --- Main Setup / Ana Kurulum ---
void setup() {
    // EN: Set 4 motor pins as OUTPUT using a loop
    // TR: 4 adet motor pinini döngü ile ÇIKIŞ (OUTPUT) olarak ayarla
    for (int pinIndex = 0; pinIndex < 4; pinIndex++) {
        pinMode(motorPins[pinIndex], OUTPUT);
    }
}

// --- Main Loop / Ana Döngü ---
void loop() {
    // =========================================================================
    // 1. TEST / EXHIBITION MODE (Continuous Rotation)
    // 1. TEST / STANT MODU (Sürekli Dönüş)
    // =========================================================================
    // EN: Active for exhibition. The motor will spin continuously without delay.
    // TR: Stant için aktif. Motor bekleme yapmadan hiç durmadan dönecektir.
    executeStepSequence();

    /*
    // =========================================================================
    // 2. REAL WORLD USAGE MODE (Feeding Once a Day)
    // 2. GERÇEK KULLANIM MODU (Günde 1 Kez Yemleme)
    // =========================================================================
    // EN: To use this mode, delete the "executeStepSequence();" line above,
    // and remove the block comment symbols (/* and * /) around this section.
    // TR: Bu modu kullanmak için yukarıdaki "executeStepSequence();" satırını silin
    // ve bu bölümün etrafındaki çoklu yorum işaretlerini (/* ve * /) kaldırın.
    
    // EN: Rotate the motor for the desired amount (FEEDING_AMOUNT)
    // TR: İstediğimiz miktar kadar (FEEDING_AMOUNT) motoru döndür
    for (int loopCount = 0; loopCount < FEEDING_AMOUNT; loopCount++) {
        executeStepSequence();
    }
    
    // EN: Wait 24 hours to run once a day (1 Sec = 1000 ms -> 24 Hours = 86,400,000 ms)
    // TR: Günde 1 kere çalışması için 24 saat bekle 
    delay(86400000); 
    */
}