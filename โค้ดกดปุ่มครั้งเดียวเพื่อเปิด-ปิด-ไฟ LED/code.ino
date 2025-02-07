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

const int LED_PIN = 9;     // ขา LED
const int BUTTON_PIN = 2;   // ขาปุ่มกด

bool ledState = false;       // สถานะของ LED
bool lastButtonState = HIGH; // สถานะก่อนหน้าของปุ่ม

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // ใช้ Pull-up resistor ภายใน

  Serial.begin(9600); // เปิด Serial Monitor ที่ baud rate 9600
  Serial.println("Arduino Ready!"); // แสดงข้อความเมื่อเริ่มทำงาน
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  // เช็คว่ามีการกดปุ่ม (LOW = กด)
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState; // สลับสถานะ LED
    digitalWrite(LED_PIN, ledState ? HIGH : LOW); // เปิด/ปิด LED

    // แสดงผลใน Serial Monitor
    Serial.print("Button Pressed! LED is now ");
    Serial.println(ledState ? "ON" : "OFF");

    delay(200); // หน่วงเวลาเพื่อป้องกันการกดซ้ำ (Debounce)
  }

  lastButtonState = buttonState; // อัปเดตสถานะล่าสุดของปุ่ม
}
