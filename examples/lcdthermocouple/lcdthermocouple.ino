/**************************************************
  热电偶传感器-MAX31855K
  采用SPI通讯方式
 ****************************************************/

#include <Adafruit_MAX31855.h>
#include <Adafruit_LiquidCrystal.h>
#include <cmath>

//通讯引脚定义
int thermoCLK = 3;
int thermoCS = 4;
int thermoDO = 5;

//初始化 模拟SPI
Adafruit_MAX31855 thermocouple(thermoCLK, thermoCS, thermoDO);
//初始化LCD引脚定义
Adafruit_LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup()
{
  //设置LCD的行和列的数量
  lcd.begin(16, 2);

  lcd.print("MAX31855 test");
  //等待MAX31855稳定
  delay(500);
}

void loop()
{
  //基本的读测试，打印当前温度
   lcd.setCursor(0, 0);
   lcd.print("Int. Temp = ");
   lcd.println(thermocouple.readInternal());
   lcd.print("  ");

   double c = thermocouple.readCelsius();
   lcd.setCursor(0, 1);
   if (std::isnan(c))
   {
     lcd.print("T/C Problem");
   }
   else
   {
     lcd.print("C = ");
     lcd.print(c);
     lcd.print("  ");
   }

   delay(1000);
}
