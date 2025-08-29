# เรียนรู้ Edge Impulse

![](./images/9_edge_impulse.png)

## Edge Impulse
Edge AI คือการพัฒนาและปรับใช้อัลกอริทึมปัญญาประดิษฐ์ (AI) และโปรแกรมบนอุปกรณ์ Edge หรืออุปกรณ์ปลายทาง มันเป็นรูปแบบหนึ่งของ Edge Computing ที่ข้อมูลจะถูกวิเคราะห์และประมวลผลใกล้กับจุดที่ข้อมูลถูกสร้างหรือเก็บรวบรวม Edge AI แตกต่างจาก AI บนคลาวด์ ซึ่งข้อมูลจะถูกส่งผ่านอินเทอร์เน็ตไปประมวลผลบนเซิร์ฟเวอร์ระยะไกล

ใน Machine Learning (ML) ข้อมูลจะถูกป้อนเข้าสู่กระบวนการฝึก สำหรับ Supervised Learning จะมีการให้ป้ายกำกับความจริง (ground-truth labels) พร้อมกับแต่ละตัวอย่างด้วย อัลกอริทึมการฝึกจะทำการปรับปรุงพารามิเตอร์ (หรือที่เรียกว่า "น้ำหนัก") ในโมเดล ML โดยอัตโนมัติ

โครงการ ML ส่วนใหญ่จะมีลำดับขั้นตอนคล้ายกันในการ เก็บข้อมูล, ตรวจสอบข้อมูล, ฝึกโมเดล ML และปรับใช้โมเดลนั้น การปรับแต่ง (Optimization) อาจรวมถึงหลายกระบวนการเพื่อลดขนาดและความซับซ้อนของโมเดล ML เช่น การตัดโหนดที่ไม่สำคัญออกจากเครือข่ายประสาท, การทำ Quantization เพื่อให้การทำงานมีประสิทธิภาพมากขึ้นบนฮาร์ดแวร์ราคาประหยัด และการคอมไพล์โมเดลให้รันบนฮาร์ดแวร์เฉพาะทาง (เช่น GPU และ NPU)

Edge Impulse เป็นแพลตฟอร์ม Edge AI ชั้นนำสำหรับการเก็บข้อมูล, ฝึกโมเดล และปรับใช้โมเดลเหล่านั้นไปยังอุปกรณ์ Edge ของคุณ มันให้กรอบงานแบบ End-to-End ที่สามารถเชื่อมต่อเข้ากับ workflow ของ Edge MLOps ของคุณได้อย่างง่ายดาย

## Create account [https://edgeimpulse.com/](https://edgeimpulse.com/)

![](./images/9_edge_impulse_web.png)  

![](./images/9_login.png)

## Create project

![](./images/9_create_new_project.png)

- ตั้งขื่อ ``RT-Thread-Object-Detection``
![](./images/9_project1.png)

![](./images/9_project2.png)

![](./images/9_project3.png)

- เลือก Target Device ``Renesas RA8D1 (Cortex-M85 480MHz)``
![](./images/9_project4.png)

- เริ่มต้น Project โดยกดปุ่ม ``Add Existing Data`` 
![](./images/9_project5.png)

![](./images/9_project6.png)

![](./images/9_project7.png)

- ถึงตอนนี้เรายังไม่ต้อง upload Data นะครับ 
- แนวทางการเก็บข้อมูล เลือกเมนู ``Data acquisition`` ใน เมนูทางด้านซ้ายมือ สามารถนำเข้าข้อมูลโดยการ upload รูปภาพที่ได้เตรียมไว้ก่อน หรือสามารถเชื่อมต่อกับ โทรศัพท์มือถือ 
  
![](./images/9_project8.png)

- กด link ``connect to device`` เพื่อเรียก QR code แล้วจึงใช้ โทรมือถือของเรา เชื่อมกับ platform ทำให้เราสามารถใช้ มือถือในการเก็บข้อมูล

![](./images/9_project9.png)

![](./images/9_project10.png)

- การเก็บข้อมูลโดยใช้มือถือ สามารถจัดเก็บแบบ Realtime ได้
![](./images/9_project11.png)

- รูปที่เก็บมาได้ นั้น ยังมีการ Label นะครับ (ทุกรูปก่อนที่นำเข้าสู่กระบวนการ train ต้องมีการ Label เพราะเป็นแบบ Supervise)
![](./images/9_project12.png)