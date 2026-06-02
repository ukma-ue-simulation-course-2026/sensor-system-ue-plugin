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
