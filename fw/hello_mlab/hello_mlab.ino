#include <Wire.h>
#include <U8g2lib.h>

#define LED_PIN 25

// Konstruktor pro SH1106 128x64 (hardwarové I2C)
// Používáme orientaci U8G2_R0, reset pin nepoužíváme (U8X8_PIN_NONE)
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


// Bitmapa loga MLAB (40x26 pixelů), přesný binární zápis bez prvního prázdného sloupce
const unsigned char mlab_logo_bits[] PROGMEM = {
  0b11111111, 0b11111111, 0b00000000,
  0b11111111, 0b11111111, 0b00000001,
  0b11111111, 0b11111111, 0b00000011,
  0b11111111, 0b11111111, 0b00000111,
  0b11111111, 0b11111111, 0b00001111,
  0b11111111, 0b11111111, 0b00011111,
  0b11111111, 0b11111111, 0b00111111,
  0b11111111, 0b11111111, 0b01111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b00000000, 0b11111111,
  0b11111111, 0b11111111, 0b11111111,
  0b11111111, 0b11111111, 0b11111111,
  0b11111111, 0b11111111, 0b11111111,
  0b11111111, 0b11111111, 0b11111111,
  0b11111111, 0b11111111, 0b11111111,
  0b11111111, 0b11111111, 0b11111111,
  0b11111111, 0b11111111, 0b11111111,
  0b11111111, 0b11111111, 0b11111111
};

// Funkce vykreslí bitmapu do středu displeje
void drawMLABLogoCentered() {
  int logo_width = 24;
  int logo_height = 25;

  int x = (128 - logo_width) / 2; // Střed displeje (šířka 128 px)
  int y = (64 - logo_height) / 2; // Střed displeje (výška 64 px)

  u8g2.drawXBMP(x, y, logo_width, logo_height, mlab_logo_bits);
}




void setup() {
  // Nastavení I2C pinů pro Raspberry Pi Pico
  Wire.setSDA(12);
  Wire.setSCL(13);
  Wire.begin();

  // Inicializace OLED displeje
  u8g2.begin();
  
  // Zobrazení textu na displeji
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 8, "Ahoj!   OLED02A");
    // u8g2.drawStr(0, 25, "OLED02A");
    u8g2.drawStr(0, 64, "MLAB.cz");

    drawMLABLogoCentered();


  } while (u8g2.nextPage());

  // Nastavení LED pinu jako výstup
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Blikání vestavěné LED (pin 25) s periodou 500 ms
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
