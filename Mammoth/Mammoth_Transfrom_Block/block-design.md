# Block design

Block design for Mixly

## 电机

### begin

- Block Design: 电机 设置引脚 [pin]
- Return: None
- Generator:
  - defination: `#include <motor.h>\Motor motor = Motor();`
  - code: `motor.begin(<pin>);`

### 电机设置状态

- Block Design: 电机 设置状态 [0/1]
- Return: None
- Generator:
  - code: `motor.setStatus(<0/1>);`


## 颜色传感器

### begin

- Block Design: 颜色传感器 设置引脚 SDA [pin] SCL [pin]
- Return: None
- Generator:
  - defination: `#include <BH1745.h>\nBH1745 bh = BH1745();`
  - code: `bh.begin(<sda>, <scl>);`

### read color

- Block Design: 颜色传感器 读颜色
- Return: byte
- Generator:
  - code: `bh.readColor();`

### detect color

- Block Design: 颜色传感器 检测到 [红色/橙色/黄色/绿色/青色/蓝色/紫色]
- Return: bool
- Generator:
  - code: `bh.isDetectColor(bh.RED/ORANGE/YELLOW/GREEN/CYAN/BLUE/PURPLE);`

### read

- Block Design: 颜色传感器 读值
- Return: None
- Generator:
  - code: `bh.read();`

### Red/Green/Blue/Clear

- Block Design: 颜色传感器 读 [RGB/R/G/B/H/S/L] 值
- Return: long
- Generator:
  - code: `bh.red/green/blue/rgb/hue/saturation/lightness;`

### #Set RGBC Mode

- Block Design: 颜色传感器 设置RGB模式为 [8位/16位]
- Return: None
- Generator:
  - code: `bh.setRgbcMode(bh.RGBC_8_BIT/bh.RGBC_16_BIT);`

### Set Gain

- Block Design: 颜色传感器 设置增益为 [1倍/2倍/16倍]
- Return: None
- Generator:
  - code: `bh.setGain(bh.GAIN_1X/bh.GAIN_2X/bh.GAIN_16X);`
