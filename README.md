# Ready to use Anemometer with alarm

![Anemometer with alarm](https://www.imiconsystem.com/wp-content/uploads/2022/08/alarm.jpg)

Anemometer with alarm | วัดความเร็วลม เพื่อการแจ้งเตือน หรือควบคุมสั่งการอัตโนมัติ พร้อม Web Monitoring & WiFi management สำหรับ New Micromation Dev Board V.2 Lite with ESP32 ใช้ในการแสดงผลค่าต่างที่วัดได้ และการตั้งค่าต่างๆ ผ่านเว็บบราวเซอร์


## ฟีเจอร์การแสดงผลและสั่งงาน
- แสดงผลค่าความเร็วลม
- แสดงสถานะการควบคุมสั่งงานผ่าน RELAY
- แสดงสถานะเงื่อนไขสั่งงานที่ได้ตั้งค่าไว้ล่วงหน้า

## ฟีเจอร์การตั้งค่า
- ตั้งค่าการเชื่อมต่อ WiFi
- ตั้งค่าเงื่อนไขสั่งงาน RELAY
- ตั้งค่าชื่อและไอดีอุปกรณ์
- การตั้งค่าผ่าน WiFi AP Mode


## Compatible hardware
1. บอร์ดพัฒนา New Micromation Dev Board V.2 Lite with ESP32 [สั่งซื้อ](https://www.imiconsystem.com/product/new-micromation-dev-board-v-2-lite-with-esp32-and-enclosure/)
![New Micromation Dev Board V.2 Lite with ESP32](https://github.com/imiconsystem/micromation-rs485-weather-station/blob/bdf550019d738539710d173fe2b3f02d10287b3d/images/20220909_152200.jpg)

2. RS-FS-N01 RS485 Modbus เซ็นเซอร์วัดความเร็วลม Wind Speed Sensor [สั่งซื้อ](https://www.imiconsystem.com/product/new-micromation-dev-board-v-2-lite-with-esp32-and-enclosure/)
![RS-FS-N01 RS485 Modbus เซ็นเซอร์วัดความเร็วลม Wind Speed Sensor](https://www.imiconsystem.com/wp-content/uploads/2020/10/RS-FS-N01-3.jpg)

## Hardware setup

ใช้ Micromation – Lite with RS-485 Module ต่อใช้งานร่วมกับ Wind Speed Sensor RS-FS-N01 ผ่าน RTU / RS-485 ด้วยโปรโตคอล Modbus Protocol โดยใช้คอนโทรลเลอร์ ESP32 Dev Kit V1

** โปรดระมัดระวัง! อย่าต่อแหล่งจ่ายไฟ Power in และ usb ในเวลาเดียวกัน เพราะจะส่งผลให้บอร์ดได้รับความเสียหาย ในบางครั้งอาจรวมไปถึงคอมพิวเตอร์

### การต่อแบบปลอดภัย สำหรับใช้ในการทดสอบและพัฒนา

- วีธีการนี้ จะถอดแหล่งจ่ายไฟหลักออก แล้วใช้ micro usb สำหรับการจ่ายไฟบอร์ดและการทดสอบพัฒนา อ่านค่า Debug  , ใช้แหล่งจ่ายไฟภายนอกต่อกับเซ็นเซอร์

![การต่อแบบปลอดภัย สำหรับใช้ในการทดสอบและพัฒนา](https://www.imiconsystem.com/wp-content/uploads/2022/06/how2power-p1.png)



### การต่อแบบปลอดภัย สำหรับการใช้งานจริง
- วีธีการนี้เป็นลักษณะของการพัฒนาที่เสร็จสิ้นแล้ว โดยถอด micro usb ออก แล้วใช้แหล่งจ่าย DC Jack 9-28V ต่อเข้าที่ช่อง Power in โดยระดับแรงดันนี้ จะสัมพันธ์กับ Power out ที่ใช้จ่ายไฟให้กับเซ็นเซอร์

** โปรดสังเกตว่าเซ็นเซอร์ของคุณรองรับแรงดันในย่านนี้หรือไม่
![การต่อแบบปลอดภัย สำหรับการใช้งานจริง](https://www.imiconsystem.com/wp-content/uploads/2022/06/how2power-p2-460x460.png)


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
3. ดาวน์โหลดโค๊ดโปรแกรม https://github.com/imiconsystem/ready2u-anemometer-alarm/releases
4. เปิดไฟล์ ready2u-anemometer-alarm.ino
5. อัพโหลดไฟล์


## การใช้งานตั้งค่า 'SET MODE' 
- กด Switch ค้างไว้… แล้ว กด EN หรือ reset บน ESP32 1 ครั้ง จากนั้นรอ 2 วินาที จึงปล่อยปุ่ม Switch, Builtin LED บน ESP32 จะกระพริบเมื่อเข้าสู่ SET MODE
- จากนั้นเชื่อมต่อระบบผ่าน WiFi ด้วย SSID = "AnemoDevkit" ; Password = "dddddddd";

SET MODE ประกอบไปด้วย

1. ส่วนของการตั้งค่า WiFi Router เชื่อมต่อ WiFi เข้ากับ Router ที่บ้านหรือสำนักงาน
2. ส่วนของการตั้งค่า Set Max Values เงื่อนไขในการตั้งค่าจุดควบคุมสั่งงานผ่าน Relay
3. ส่วนของการตั้งค่า System Setting ใช้สำหรับ ตั้งค่าชื่อและไอดีอุปกรณ์
4. ส่วนของการตั้งค่า WiFi Access Point [AP Mode] เพื่อใช้ในการเข้าถึง/การจัดการ Micromation Dev Board V.2

## Factory Reset เพื่อกลับสู่ค่าเริ่มต้น 'RESET MODE'

- กด Switch ค้างไว้… แล้ว กด EN หรือ reset บน ESP32 1 ครั้ง จากนั้นรอ 6 วินาที จึงปล่อยปุ่ม Switch
- จากนั้นกด กด EN หรือ reset บน ESP32 อีก 1 ครั้ง โปรแกรมจะเข้าสู่ค่าเริ่มต้น
- เข้าสู่ SET MODE เพื่อทำการตั้งค่าใหม่
