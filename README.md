# SimpleLED
Данная библиотека упрощает работу со светодиодами, в частности светодиодными лентами, разработана для использования в качестве компактного встраиваемого модуля. Библиотека включает в себя функции установки цвета посредством RGB или HSV, регулировки общей яркости. Для использования библиотеки требуется 3 свободных цифровых PWM пина (например 3, 5,
6).

# Пример использования
```c++
#include <SimpleLED.h>

SimpleLED diode(3, 5, 6); // использование пина 3 для красного, 5 для зелёного, 6 для синего цветового канала.
float progress = 0;
float val = 0.025;

void setup() 
{
  diode.SetDefColor(SL_WHITE); // установка всех цветовых каналов на максимум (т.е. белый цвет)
}

void loop() 
{
  diode.SetBrightness(progress); // установка яркости каждую итерацию цикла
  progress = progress + val;
  if (progress <= 0 || progress >= 255) {
    val = -val;
  }
}
```
## Использование динамичного изменения с пк
```c++
void loop() 
{  
  if(Serial.available() > 0) //При доступности данных
  {
    byte incomingBytes[3];
    Serial.readBytes(incomingBytes, 3); // Считывание байтов
    SimpleLED.SetColor(incomingBytes[0], incomingBytes[1], incomingBytes[2]); // Назначение цвета
  }
}
```
# Схемы использования
Для управления светодиодными лентами вам необходимо собрать данную ниже схему трижды, для каждого цветового канала.<br>
Внимание! Используйте только подходящие по напряжению блоки питания, иначе вы можете сжечь вашу ленту.<br>
Схема для использования с лентами:

![Preview](http://i.imgur.com/JCjWYK9.png)

Схема для использования с группами светодиодов:

![Preview](http://i.imgur.com/TqwseeC.png)

# Установка
Для начала, скачайте архив этого репозитория (нажмите <a href="https://github.com/SNMetamorph/SimpleLED/archive/master.zip">сюда</a>).<br> 
После, откройте Arduino IDE -> выберите в меню "Скетч" -> Подключить библиотеку -> Добавить .ZIP библиотеку -> найти и выберите ранее скачанный архив.<br> Установка завершена.

# Функции
<b>void SetColor(byte red, byte green, byte blue)</b> - установка цветовой величины для каждого канала.<br>
<b>void SetHSVColor(float hue, float saturation, float brightness)</b> - установка цветовой величины для каждого канала, посредством цветовой модели HSV.<br>
<b>bool SetDefColor(int num)</b> - установка объявленного цвета (подробнее в разделе Объявленные цвета).<br>
<b>SL_RGB GetColor()</b> - возвращает структуру с последним установленным цветом (подробнее смотрите в разделе Структуры).<br>
<b>void SetBrightness(float value)</b> - установка яркости для всех цветовых каналов.<br>
<b>void Flush()</b> - отключение всех цветовых каналов, эквивалентно функции SetColor(0, 0, 0).<br>

# Структуры
Библиотека содержит в себе данные структуры:
```c++
struct SL_RGB 
{
	byte r, g, b;
};

struct SL_PIN 
{
	int r, g, b;
};
```
Пример извлечения цветов из структуры:
```c++
#include <SimpleLED.h>

SimpleLED diode(3, 5, 6);

void setup()
{
  Serial.begin(9600);
  diode.SetColor(255, 128, 20);
}

void loop()
{
  SL_RGB color = diode.GetColor();
  Serial.println(color.r); // результат - 255
  Serial.println(color.g); // результат - 128
  Serial.println(color.b); // результат - 20
}
```
# Объявленные цвета
Конструктив раздела: название директивы цвета - число для цвета - эквивалент функции SetColor().<br>
Пример использования таких цветов в коде: obj.SetDefColor(SL_GREEN) или obj.SetDefColor(2), также можно использовать obj.SetColor(0, 255, 0)<br>

```c++
SL_WHITE - 0 - obj.SetColor(255, 255, 255)
SL_RED - 1 - obj.SetColor(255, 0, 0)
SL_GREEN - 2 - obj.SetColor(0, 255, 0)
SL_BLUE - 3 - obj.SetColor(0, 0, 255)
```

