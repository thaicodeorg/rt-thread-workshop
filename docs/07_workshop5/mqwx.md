# ตั้งค่า การใช้งาน EMQX 
- เปิด Browser ไปที่ [https://www.emqx.com/en](https://www.emqx.com/en)
![](./images/5_emqx1.png)

- Click ปุ่ม ``Sign In`` และ เลือกการ การ login ด้วย Accout Gmail หรือ อื่นๆ
![](./images/5_emqx2.png)

![](./images/5_emqx3.png)

- Click New Deplyment
![](./images/5_emqx4.png)

![](./images/5_emqx5.png)

- เลื่อน ลงมาด้านล่าง ตั้งชื่อ โปรเจค ``mqtt-muict-server``  ท่านสามารถตั้งชื่อตามที่ต้องการได้เลย พร้อมแล้วก็กด Deploy ได้เลย
![](./images/5_emqx6.png)

- โดยการใช้งาน emqx จะเป็นการใช้บริการในรูปแบบเป็น server less (login แล้วสามารถใช้งานเลย) Click ตามรูปด้านล่าง
![](./images/5_emqx7.png)

![](./images/5_emqx8.png)

- **Add Authorization** ตั้งชื่อ Client ID ชื่อ muict-001
- Add Topic ``rt-thread-node1/pub/test``
  
![](./images/5_emqx9.png)

![](./images/5_emqx10.png)

- **Add Authentication**
![](./images/5_emqx11.png)

- **กลับ ไปยัง Overview** เพื่อ ทำการ Copy ค่าของ Address เอาไว้
- จากตัวอย่าง  
  - ``o08e80f7.ala.asia-southeast1.emqxsl.com``
  - MQTT Over TLS/SSL Port:  8883
  - WebSocket over TLS/SSL Poro: 8084
  - API Endpoint ``https://o08e80f7.ala.asia-southeast1.emqxsl.com:8443/api/v5``
![](./images/5_emqx12.png)
  
## เชื่อมต่อไปยัง Serverless ใช้ MQTTX  [https://mqttx.app/](https://mqttx.app/)
![](./images/5_emqx13.png)

![](./images/5_emqx14.png)

![](./images/5_emqx15.png)

![](./images/5_emqx16.png)

![](./images/5_emqx17.png)

## Application start 
- กด ``+New Connection`` เพื่อสร้าง Connection
![](./images/5_emqx18.png)

![](./images/5_emqx19.png)

- เชื่อมต่อประสบความสำเร็จ

![](./images/5_emqx20.png)

## Add Subsubscription 
- เราสร้าง topic ``rt-thread-node1/pub/test``  ไว้เรียบร้อยแล้ว
- จาก ui เราต้องสร้าง subscript ไว้ที่ ``rt-thread-node1/#``
- กดยืนยัน
![](./images/5_emqx21.png)

## Finish
![](./images/5_emqx22.png)

- Diagrame การสื่อสาร
![](./images/5_emqx23.png)




<div class="grid" markdown>
[<- กลับไปยัง IoT programing](./workshop5.md)
{ .card }
</div>