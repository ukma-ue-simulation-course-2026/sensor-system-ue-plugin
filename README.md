# SensorSystem UE Plugin

Слід перевірити, що плагін **SensorSystem**:
- правильно підключений до UE5 проєкту
- доступний у Blueprint
- коректно викликає C++ функції
- повертає очікувані значення

---

# Швидкий тест
## 1. Додати плагін до проекту і увімкнути плагін
В Unreal Editor:
Edit → Plugins → SensorSystem → Enabled ✔

Перезапустити Editor, якщо потрібно.

## 2. Створити будь якого BP_Actor

## 3. Додати виклик функції `Sensor Ping`

У Event Graph свого BP_Actor:

<img width="983" height="210" alt="image" src="https://github.com/user-attachments/assets/a7365dd1-f4e0-48ab-b765-d1779faca3b2" />

---

# Очікуваний результат

## 🔹 Blueprint (Print String)

Подвоєне вхідня значення

(бо функція повертає `InputValue * 2`)

## 🔹 Перевірка C++ логів

Відкрити:

Window → Developer Tools → Output Log
Очікуваний лог:

SensorPing called with: *InputValue*

<img width="532" height="170" alt="image" src="https://github.com/user-attachments/assets/c69751da-665f-4bc2-b27f-5095745da688" />

---

<br/><br/><br/>
# Щоб додати *гіроскоп* до якогось Actor:
## 1. Додати до Actor компоненти Gyroscope та Battery:
<img width="320" height="156" alt="image" src="https://github.com/user-attachments/assets/61876c73-fcd2-462a-87e8-2e160b58b297" />


## 2. Встановити в цьому Actor необхідні поля (головний StaticMesh, та додану на попередньому кроці батарею) для гіроскопа при запуску
<img width="1124" height="296" alt="image" src="https://github.com/user-attachments/assets/f16487cc-44c7-4b2f-b2fe-66e7e4f62191" />


## 3. Щоб читати дані з гіроскопа, слід викликати `Get Angular Velocity` з компонента `Gyroscope`
<img width="593" height="246" alt="image" src="https://github.com/user-attachments/assets/a9cc9aa3-cf6b-4aa8-a73b-19f2a3dda8f8" />


## 4. Щоб дивитися заряд батареї, слід читати поле `Battery` з компонента `Battery`
<img width="524" height="182" alt="image" src="https://github.com/user-attachments/assets/d4b411cd-f9fc-437e-968a-ba6172e2da1c" />

<br/><br/><br/>
# Візуальний сеснор MK1Eyeball
Так само додається до блупрінта як і героскоп, має зафіксовані значення FieldOfView і відстані на яку може дивитись.
Щоб побачити дебажну відображення того що саме зараз бачить датчик використовуйте консольну команду Sensors.VisibilityDebugShow 1

!ВАЖЛИВО! щоб датчик міг бачити цілі важливо щоб вони були позначені тегом Target
<img width="532" height="452" alt="image" src="https://github.com/user-attachments/assets/be1084f4-88bb-4ee7-a812-12c67efe0fbe" />


