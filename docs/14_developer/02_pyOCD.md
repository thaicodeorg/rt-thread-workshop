---
title: "การใช้งาน PyOCD เพื่ออัปโหลดเฟิร์มแวร์และดีบักบน Renesas Vision Board"
description: "ทำความเข้าใจหลักการทำงานของ PyOCD ผ่านชิป DAPLink (AT32F425KBU7) การติดตั้ง CMSIS-Pack สำหรับชิป Renesas RA8D1 ชุดคำสั่ง Flash และ GDB Server รวมถึงแนวทางแก้ไขปัญหาการเชื่อมต่อ SWD"
---


**PyOCD** คือเครื่องมือโอเพนซอร์ส (Open-source) แบบ Command-Line และ Python Library สำหรับใช้ **อัปโหลดเฟิร์มแวร์ (Flash)** และ **ดีบัก (Debug)** ไมโครคอนโทรลเลอร์ตระกูล **Arm Cortex-M** (เช่น Renesas RA8D1 ที่ใช้แกน Arm Cortex-M85) บนเครื่องคอมพิวเตอร์ผ่านโปรโตคอล **CMSIS-DAP**

---

### 1. บทบาทของ PyOCD ในระบบพัฒนาของ Vision Board

บนบอร์ด Renesas RA8D1 Vision Board มีชิปตัวกลาง `AT32F425KBU7` (`U10`) ที่รันเฟิร์มแวร์ **DAPLink** ซึ่งสื่อสารด้วยมาตรฐาน CMSIS-DAP อยู่บนบอร์ดแล้ว ทำให้ **PyOCD** ทำหน้าที่เป็นสะพานเชื่อมระหว่างซอฟต์แวร์บนคอมพิวเตอร์ (RT-Thread Studio, GDB, Terminal) กับชิปเป้าหมาย (`R7FA8D1BH`):

* **Flash Programming:** ลบหน่วยความจำ Flash และเขียนไฟล์ไบนารี (`.bin`, `.hex`, `.elf`) ลงในชิป RA8D1
* **GDB Server:** เปิดพอร์ต TCP (ค่าเริ่มต้นคือ `localhost:3333`) เพื่อให้โปรแกรมดีบักอย่าง `arm-none-eabi-gdb` หรือหน้าต่าง Debug ของ RT-Thread Studio เชื่อมต่อเข้ามาตั้ง Breakpoint, สั่งรันทีละบรรทัด (Step-by-step), และอ่านค่าใน Register หรือหน่วยความจำ RAM ได้
* **Target Support via CMSIS-Packs:** รองรับชิปตระกูล Arm Cortex-M ได้หลากหลายยี่ห้อโดยไม่ต้องแก้โค้ดตัวโปรแกรมหลัก เพียงแค่ดาวน์โหลดไฟล์ **CMSIS Device Family Pack (DFP)** ของชิปรุ่นนั้นๆ มาติดตั้งเพิ่ม (ซึ่งไฟล์ Pack นี้มีอัลกอริทึมการเขียน Flash เฉพาะของชิป Renesas RA8D1 บรรจุอยู่)

---

### 2. การทำงานเบื้องหลังเมื่อสั่ง Flash หรือ Debug

1. **Host Side:** คุณรันคำสั่ง `pyocd` ผ่าน Terminal หรือกดปุ่ม Download/Debug ใน RT-Thread Studio
2. **USB Communication:** PyOCD ส่งคำสั่งผ่านไลบรารี `hidapi` / `pyusb` ไปยังพอร์ต `USB-DBG` ของบอร์ด
3. **Probe Translation:** ชิป DAPLink (`U10`) รับคำสั่ง CMSIS-DAP แล้วแปลงเป็นสัญญาณไฟฟ้า **SWD (`SWDIO`, `SWCLK`, `RESET`)** ส่งเข้าชิปหลัก `RA8D1`
4. **Flash Algorithm Execution:** PyOCD โหลดโค้ดอัลกอริทึมขนาดเล็ก (Flash Algo จากไฟล์ Pack) เข้าไปพักใน SRAM ของชิป RA8D1 เพื่อใช้ควบคุมการเขียนข้อมูลลง Flash Memory จริงของชิป

---

### 3. ชุดคำสั่ง PyOCD ที่ใช้บ่อยในการทำ Workshop และพัฒนาจริง

| คำสั่ง | หน้าที่การทำงาน |
| --- | --- |
| `pyocd list` | ตรวจสอบรายชื่อ Debugger Probe (เช่น DAPLink) ที่เสียบเชื่อมต่ออยู่กับคอมพิวเตอร์ |
| `pyocd pack find R7FA8D1BH` | ค้นหาไฟล์ CMSIS-Pack สำหรับชิป Renesas RA8D1 ในฐานข้อมูลออนไลน์ |
| `pyocd pack install R7FA8D1BH` | ดาวน์โหลดและติดตั้งไฟล์ Pack ของชิป RA8D1 ลงในเครื่อง |
| `pyocd flash -t R7FA8D1BH rtthread.bin` | เขียนไฟล์ `rtthread.bin` ลงในชิป `R7FA8D1BH` (หากเป็นไฟล์ `.bin` ระบบจะเขียนที่แอดเดรสเริ่มต้น `0x02000000` ของ RA8D1 ตามที่กำหนดใน Pack) |
| `pyocd erase -t R7FA8D1BH --chip` | ล้างข้อมูลทั้งหมดในหน่วยความจำ Flash ของชิป (ใช้แก้ปัญหาเมื่อเฟิร์มแวร์เดิมค้างหรือล็อกขา SWD) |
| `pyocd gdbserver -t R7FA8D1BH` | เปิดโหมด GDB Server เพื่อรอรับการเชื่อมต่อจาก `arm-none-eabi-gdb` หรือ IDE |
| `pyocd reset -t R7FA8D1BH` | สั่งรีเซ็ตชิปเป้าหมายผ่านสัญญาณ Hardware Reset ของ SWD |

---

### 4. การแก้ปัญหาที่พบบ่อยเมื่อใช้งาน PyOCD

* **ไม่พบ Probe (`No available debug probes are connected`):**
* ตรวจสอบว่าเสียบสาย USB-C เข้าช่อง **`USB-DBG`** (ช่องล่าง) ไม่ใช่ช่อง `USB-OTG`
* บน Linux อาจติดสิทธิ์การเข้าถึงพอร์ต USB ต้องเพิ่มไฟล์ `udev rules` ของ CMSIS-DAP; ส่วนบน Windows 10/11 ระบบจะเห็นไดรเวอร์ WinUSB/HID อัตโนมัติโดยไม่ต้องลงไดรเวอร์เพิ่ม


* **ไม่รู้จักชื่อชิปเป้าหมาย (`Target type R7FA8D1BH not recognized`):**
* ยังไม่ได้ติดตั้ง Pack ของ Renesas RA ให้รันคำสั่ง `pyocd pack update` ตามด้วย `pyocd pack install R7FA8D1BH` (หากเครื่องไม่มีอินเทอร์เน็ต สามารถใช้ Flag `--pack <path_to_file.pack>` ชี้ไปยังไฟล์ `.pack` ที่อยู่ในโฟลเดอร์ RT-Thread Studio หรือ RASC ได้โดยตรง)


* **เขียน Flash ไม่ผ่าน / เชื่อมต่อ SWD ไม่ได้:**
* หากโค้ดเก่าตั้งค่าขา `SWDIO`/`SWCLK` เป็น GPIO ธรรมดา หรือทำให้ CPU เข้าโหมด Deep Sleep ทันทีที่เปิดเครื่อง ให้กดปุ่ม **`USER/BOOT`** ค้างไว้แล้วกดปุ่ม **`RST`** เพื่อเข้าโหมด Bootloader จากนั้นค่อยสั่ง `pyocd erase -t R7FA8D1BH --chip` เพื่อล้างเฟิร์มแวร์เก่าออกครับ