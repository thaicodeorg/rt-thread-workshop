---
title: "เอกสารอ้างอิงและงานวิจัย"
description: "รวบรุมเอกสารทางเทคนิค งานวิจัย และคู่มือการใช้งาน RT-Thread สำหรับนักศึกษาและผู้สนใจ"
---

# 📚 เอกสารอ้างอิงและงานวิจัย

รวบรวมเอกสารทางเทคนิค งานวิจัย และคู่มือการใช้งาน RT-Thread สำหรับศึกษาเพิ่มเติมและอ้างอิงในการทำโครงงาน

[← กลับหน้าหลัก](../index.md){ .md-button .md-button--secondary }

---

## งานวิจัย

| เอกสาร | รายละเอียด | บทคัดย่อ (Abstract) | เปิด |
|--------|-----------|----------------------|------|
| 📝 **Design and Implementation of Distributed Time-Triggered System Based on RT-Thread** | งานวิจัยเกี่ยวกับการออกแบบและพัฒนาระบบ Time-Triggered แบบกระจายบน RT-Thread | IoT ขับเคลื่อน Industry 4.0 แต่ TSN มาตรฐานการส่งข้อมูลไม่ครอบคลุม real-time ที่อุปกรณ์ปลายทาง งานนี้จึงออกแบบกลไก schedule thread แบบ time-triggered บน RT-Thread ให้ thread ทำงานตรงเวลาที่กำหนดล่วงหน้าตาม global clock เพื่อรับประกัน end-to-end delay | [📄 PDF](./Design%20and%20Implementation%20of%20Distributed%20Time-TriggeredSystem%20Based%20on%20RT-Thread.pdf) |
| 📝 **Real-Time Analysis of Event Response Based on RT-Thread** | การวิเคราะห์การตอบสนองเหตุการณ์แบบ Real-Time บน RT-Thread | ศึกษา real-time performance ของ event response ใน RT-Thread โดยใช้ low-latency piling timing analysis วัดเวลา schedule thread บน STM32L431RCT6 พบว่า error ~1.5 µs เทียบกับ logic analyzer และระบุว่า compilation optimization level กับ PendSV exception เป็นปัจจัยสำคัญที่มีผลต่อ real-time | [📄 PDF](./Real-Time_Analysis_of_Event_Response_Based_on_RT-Thread.pdf) |
| 📝 **Design of Ecological Environment Monitoring System Based on RT-Thread and Cloud Platform** | ระบบติดตามสภาพแวดล้อมเชิงนิเวศบน RT-Thread กับ Cloud Platform | เสนอระบบ monitoring สภาพแวดล้อมแบบ real-time ราคาประหยัด โดยใช้สถาปัตยกรรม 3 ชั้น (sensor + STM32 → LTE Cat.1/Ethernet → Alibaba Cloud + Deep Learning + Mobile Client) ผลทดสอบจริงลด latency เหลือ 120 ms ประหยัด memory 41.7% และเพิ่ม task scheduling efficiency 40% | [📄 PDF](./Design_of_Ecological_Environment_Monitoring_System_Based_on_RT-Thread_and_Cloud_Platform.pdf) |
| 📝 **The Design and Implementation of the RT-Thread Operating System** | เอกสารอธิบายการออกแบบและพัฒนา RT-Thread Operating System | หนังสือฉบับสมบูรณ์ (CRC Press) อธิบายโครงสร้าง RT-Thread ตั้งแต่ kernel: thread management, clock, synchronization, inter-thread communication, memory management, interrupt จนถึง component: Env, FinSH, device framework, VFS, network stack | [📄 PDF](./The_Design_and_Implementation_of_the_RT-Thread_Operating.pdf) |
| 📝 **The Design and Implementation of the RT-Thread Operating System (Qiu Yi Xiong et al.)** | ฉบับเต็มโดย Qiu Yi Xiong, Puxiang และ Tianlong Zhu | หนังสือเล่มเดียวกันกับรายการด้านบน แต่เป็นไฟล์ที่ระบุชื่อผู้แต่งไว้ในชื่อไฟล์ เนื้อหาครอบคลุม kernel และ component ของ RT-Thread พร้อมตัวอย่าง code และคำแนะนำการ port ไปบare hardware board | [📄 PDF](./The_Design_and_Implementation_of_the_RT-Thread_Operating_-_Qiu_Yi_Xiong_Puxiang_and_Tianlong_Zhu.pdf) |
| 📝 **RT-Thread and NB-IoT based in-vehicle environmental monitoring system** | ระบบติดตามสภาพแวดล้อมภายในรถยนต์บน RT-Thread กับ NB-IoT | ออกแบบระบบตรวจสอบสภาพแวดล้อมในรถ (อุณหภูมิ, CO₂, CO, ฝุ่น) โดยใช้ STM32 ผสมกับ NB-IoT เชื่อมต่อ cloud platform เมื่อค่าผิดปกติระบบแจ้งเตือนและอัปโหลดขึ้น cloud ได้ทันที มีลักษณะเด่นคือประหยัดพลังงาน ประหยัดไฟ และ real-time สูง | [📄 PDF](./RT-Thread_and_NB-IoT_based_in-vehicle_environmental_monitoring_system.pdf) |
| 📝 **Structure Design and Motion Control of Remote Tea Service Robot Based on RT-Thread** | การออกแบบโครงสร้างและควบคุมการเคลื่อนที่ของระบบรีโมท | ออกแบบหุ่นยนต์บริการชงชา (tea service robot) แบบ remote control โดยใช้ RT-Thread พร้อม WiFi module และกล้อง ทดสอบ response speed และ human-computer interaction พบว่า robot ตอบสนองเร็วและปฏิสัมพันธ์กับผู้ใช้ได้แม่นยำ | [📄 PDF](./Structure_Design_and_Motion_Control_of_Remote.pdf) |
| 📝 **Study and Analysis of the Message Queue Operation Mechanism Based on the Open-Source RT-Thread Architecture** | การศึกษาและวิเคราะห์กลไกการทำงานของ Message Queue บนโครงสร้าง RT-Thread แบบ Open-Source | วิเคราะห์โครงสร้าง ฟังก์ชัน และ scheduling timing ของ message queue ใน RT-Thread พร้อมตัวอย่าง programming แบบ step-by-step ชี้ให้เห็นว่า message queue ช่วยให้ thread สื่อสารกันได้อย่างมีประสิทธิภาพ มีค่าอ้างอิงสูงสำหรับการนำไปใช้งานจริง | [📄 PDF](./Study_and_Analysis_of_the_Message_Queue_Operation_Mechanism_Based_on_the_Open-Source_RT-Thread_Architecture.pdf) |

---

## คู่มือการใช้งาน และ เอกสารอื่น ๆ

| เอกสาร | รายละเอียด | บทคัดย่อ (Abstract) | เปิด |
|--------|-----------|----------------------|------|
| 📘 **RT-Thread User Guide (General MCU)** | คู่มือการใช้งาน RT-Thread สำหรับ General MCU (ภาษาอังกฤษ) | คู่มือใช้งาน RT-Thread บน Nsing General MCU (N32G45x, N32G4FR, N32WB452, N32G43x, N32L40x, N32L43x) อธิบายตั้งแต่ kernel overview, thread management, clock, interrupt, memory ไปจนถึงตัวอย่าง semaphore, mutex, message queue, mailbox และ event | [📄 PDF](./EN_UG_General_MCU_RT_Thread_User_Guide.pdf) |
| 📗 **RT-Thread Board Port and Application Development** | คู่มือการพอร์ตบอร์ดและพัฒนาแอปพลิเคชันบน RT-Thread | เอกสาร Application Note จาก NXP อธิบายสถาปัตยกรรม RT-Thread (kernel → component → software package) startup sequence รวมถึงขั้นตอนการ port libCPU/BSP สำหรับบอร์ดใหม่ และตัวอย่างการพัฒนาแอปพลิเคชัน | [📄 PDF](./RT-Thread%20Board%20Port%20and%20Application%20Development.pdf) |
| 📙 **RT-Thread Documentation** | เอกสารฉบับสมบูรณ์ของ RT-Thread (ครอบคลุม Kernel, Driver, Component) | เอกสารฉบับสมบูรณ์สร้างโดย Doxygen ครอบคลุม User Guide, Kernel (object, thread, clock/timer, semaphore, mutex, event, mailbox, message queue, memory, interrupt), kernel porting และ component เช่น device framework, file system, network | [📄 PDF](./rt-thread-documentation.pdf) |

---

*เอกสารทั้งหมดใช้เพื่อการศึกษาและอ้างอิงเท่านั้น*
