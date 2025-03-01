const int button = 1;       // Кнопка
const int led_1 = 2;        // Первый светодиод
const int led_2 = 3;        // Второй светодиод

bool isBlinking = false;       // Состояние мигалки
bool buttonState = false;      // Текущее состояние кнопки
bool lastButtonState = false;  // Предыдущее состояние кнопки

unsigned long previousMillis = 0;  // Последнее время переключения светодиодов
const unsigned long interval = 300; // Интервал мигания (300 мс)

void setup() {
  pinMode(led_1, OUTPUT);  // Настраиваем первый светодиод как выход
  pinMode(led_2, OUTPUT);  // Настраиваем второй светодиод как выход
  pinMode(button, INPUT);  // Настраиваем кнопку как вход
}

void loop() {
  // Считываем состояние кнопки
  buttonState = digitalRead(button);

  // Переключаем режим мигалки при нажатии кнопки
  if (buttonState && !lastButtonState) {
    isBlinking = !isBlinking;
  }
  lastButtonState = buttonState;

  // Если режим мигания включен, управляем светодиодами
  if (isBlinking) {
    unsigned long currentMillis = millis();

    // Проверяем, прошло ли достаточно времени для переключения
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Переключаем состояние светодиодов
      static bool ledState = false; // Текущее состояние светодиодов
      ledState = !ledState;

      digitalWrite(led_1, ledState ? HIGH : LOW);
      digitalWrite(led_2, ledState ? LOW : HIGH);
    }
  } else {
    // Если режим мигания выключен, отключаем оба светодиода
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
  }
}
