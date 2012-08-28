#include <SPI.h>

int serial_putc(char c, FILE *) {
  Serial.write(c);
  return 0;
}

void printf_begin() {
  Serial.begin(57600);
  fdevopen(&serial_putc, 0);
}