# Ready to use RS485 Temperature and Humidity

ระบบวัดอุณหภูมิและความชื้น เพื่อการแจ้งเตือน หรือควบคุมสั่งการอัตโนมัติ พร้อม Web Monitoring & WiFi management สำหรับ New Micromation Dev Board V.2 Lite with ESP32 ใช้ในการแสดงผลค่าต่างที่วัดได้ และการตั้งค่าต่างๆ ผ่านเว็บบราวเซอร์

![RS485 Temperature and Humidity](https://github.com/imiconsystem/ready2u-rs485-tem-humi/blob/ceb66e98a28e992e84ce243050311125ebc9b003/images/cover.JPG)


## ฟีเจอร์การแสดงผลและสั่งงาน
- แสดงผลค่าอุณหภูมิและความชิ้น
- แสดงสถานะการควบคุมสั่งงานผ่าน RELAY
- แสดงสถานะเงื่อนไขสั่งงานที่ได้ตั้งค่าไว้ล่วงหน้า

## ฟีเจอร์การตั้งค่า
- ตั้งค่าการเชื่อมต่อ WiFi
- ตั้งค่าเงื่อนไขสั่งงาน RELAY
- ตั้งค่าชื่อและไอดีอุปกรณ์
- การตั้งค่าผ่าน WiFi AP Mode


## อุปกรณ์ที่ใช้ในระบบ
1. บอร์ดพัฒนา New Micromation Dev Board V.2 Lite with ESP32 [>> เรียนรู้เพิ่มเติมและสั่งซื้อ](https://www.imiconsystem.com/product/new-micromation-dev-board-v-2-lite-with-esp32-and-enclosure/)

2. BGT-WSD2 Atmospheric Temperature & Humidity Sensor Modbus RS485 เซ็นเซอร์วัดอุณหภูมิและความชื้นอากาศภายนอก [>> เรียนรู้เพิ่มเติมและสั่งซื้อ](https://www.imiconsystem.com/product/rs485-atmospheric-%e0%b9%80%e0%b8%8b%e0%b9%87%e0%b8%99%e0%b9%80%e0%b8%8b%e0%b8%ad%e0%b8%a3%e0%b9%8c%e0%b8%a7%e0%b8%b1%e0%b8%94%e0%b8%ad%e0%b8%b8%e0%b8%93%e0%b8%ab%e0%b8%a0%e0%b8%b9%e0%b8%a1%e0%b8%b4/)

3. RS-485 HUB [>> เรียนรู้เพิ่มเติมและสั่งซื้อ](https://www.imiconsystem.com/product/rs-485-hub/)


## การติดตั้งอปุกรณ์

ใช้ Micromation – Lite with RS-485 Module ต่อใช้งานร่วมกับ BGT-WSD2 เซ็นเซอร์อุณหภูมิและความชื้นอากาศ ผ่าน RTU / RS-485 ด้วยโปรโตคอล Modbus Protocol โดยใช้คอนโทรลเลอร์ ESP32 Dev Kit V1

![RS485 Temperature and Humidity](https://github.com/imiconsystem/ready2u-rs485-tem-humi/blob/main/images/4.jpg)

** โปรดระมัดระวัง! อย่าต่อแหล่งจ่ายไฟ Power in และ usb ในเวลาเดียวกัน เพราะจะส่งผลให้บอร์ดได้รับความเสียหาย ในบางครั้งอาจรวมไปถึงคอมพิวเตอร์


## Software setup
1. ดาวน์โหลดและติดตั้ง Arduino IDE https://www.arduino.cc/en/software
2. เพิ่มบอร์ด ESP32 board package สำหรับ Arduino IDE
- เข้าเมนู File > Preferences, ใส่ค่าใน "Additional Boards Manager URLs" ด้วย: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
- เข้าเมนู Tools > Board > Boards Manager..., พิมพ์ "esp32" ในช่องค้นหา, เลือกติดตั้งบอร์ด ****esp32**** รุ่นล่าสุด หากไม่เจอให้รีสาตาร์ทโปรแกรม Arduino IDE
- เข้าเมนู Tools -> Manage Libraries ติดตั้ง Library ต่อไปนี้
1. ezButton by ArduinoGetStarted.com Version 1.0.4 https://arduinogetstarted.com/tutorials/arduino-button-library

## Flash โปรแกรมลง ESP32
1. เข้าเมนู Tools เลือกบอร์ด DOIT ESP32 DEVKIT V1
2. เลือกพอร์ต
3. ดาวน์โหลดโค๊ดโปรแกรม https://github.com/imiconsystem/ready2u-rs485-tem-humi/releases
4. เปิดไฟล์ ready2u-rs485-tem-humi.ino
5. อัพโหลดไฟล์


## การใช้งานตั้งค่า 'SET MODE' 
- กด Switch ค้างไว้… แล้ว กด EN หรือ reset บน ESP32 1 ครั้ง จากนั้นรอ 2 วินาที จึงปล่อยปุ่ม Switch, Builtin LED บน ESP32 จะกระพริบเมื่อเข้าสู่ SET MODE
- จากนั้นเชื่อมต่อระบบผ่าน WiFi ด้วย SSID = "485THDevkit" ; Password = "dddddddd";

SET MODE ประกอบไปด้วย

1. ส่วนของการตั้งค่า WiFi Router เชื่อมต่อ WiFi เข้ากับ Router ที่บ้านหรือสำนักงาน
2. ส่วนของการตั้งค่า Set Max Values เงื่อนไขในการตั้งค่าจุดควบคุมสั่งงานผ่าน Relay
3. ส่วนของการตั้งค่า System Setting ใช้สำหรับ ตั้งค่าชื่อและไอดีอุปกรณ์
4. ส่วนของการตั้งค่า WiFi Access Point [AP Mode] เพื่อใช้ในการเข้าถึง/การจัดการ Micromation Dev Board V.2

## Factory Reset เพื่อกลับสู่ค่าเริ่มต้น 'RESET MODE'

- กด Switch ค้างไว้… แล้ว กด EN หรือ reset บน ESP32 1 ครั้ง จากนั้นรอ 6 วินาที จึงปล่อยปุ่ม Switch
- จากนั้นกด กด EN หรือ reset บน ESP32 อีก 1 ครั้ง โปรแกรมจะเข้าสู่ค่าเริ่มต้น
- เข้าสู่ SET MODE เพื่อทำการตั้งค่าใหม่