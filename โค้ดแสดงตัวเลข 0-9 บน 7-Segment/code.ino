/*
 * MIT License
 * 
 * Copyright (c) 2025 CyberKitty404
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

 const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // ขา a-g ของ 7-Segment
const int dpPin = 9; // ขาจุดทศนิยม (ถ้าใช้)

const byte numbers[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

int counter = 9; // เริ่มที่ 9

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(dpPin, OUTPUT);
}

void loop() {
  while (counter >= 0) {
    showDigit(counter);
    delay(1000); // นับถอยหลังทุก 1 วินาที
    counter--; // ลดค่าทีละ 1
  }
}

void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(numbers[num], i));
  }
  digitalWrite(dpPin, HIGH); // เปิดจุดทศนิยม
  delay(500);
  digitalWrite(dpPin, LOW); // ปิดจุดทศนิยม
}
