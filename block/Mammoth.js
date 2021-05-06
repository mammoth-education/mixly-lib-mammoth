'use strict';
 
goog.provide('Blockly.Blocks.Mammoth');
goog.require('Blockly.Blocks');

//颜色传感器
Blockly.Blocks.BH1745_begin = {

    init: function() {
  
      this.appendDummyInput("")
      .appendField("颜色传感器")
      .appendField(new Blockly.FieldTextInput("bh"), "IST")
      .appendField("设置引脚")
      .appendField("SDA")
      .appendField(new Blockly.FieldDropdown(profile.default.digital), "sda")
      .appendField("SCL")
      .appendField(new Blockly.FieldDropdown(profile.default.digital), "scl")
      this.setColour("#00A29A");
      this.setInputsInline(true);
      this.setPreviousStatement(true);
      this.setNextStatement(true);
      this.setTooltip("BH1745 设置引脚 SDA SCL");
      this.setHelpUrl('');
  }
  
};

Blockly.Blocks.BH1745_read = {

    init: function() {
  
      this.appendDummyInput("")
          .appendField("颜色传感器")
          .appendField(new Blockly.FieldTextInput("bh"), "IST")
          .appendField("读值");
      this.setColour("#00A29A");
      this.setInputsInline(true);
      this.setPreviousStatement(true);
      this.setNextStatement(true);
      this.setTooltip("BH1745 读值");
      this.setHelpUrl('');
  }
  
};

Blockly.Blocks.BH1745_readColor = {
    init: function() {
        this.appendDummyInput("")
        .appendField("颜色传感器")
        .appendField(new Blockly.FieldTextInput("bh"), "IST")
        .appendField("读颜色");
        this.setColour("#00A29A");
        this.setOutput(true,Number);
        this.setInputsInline(true);
        this.setTooltip('颜色识别');
    }
};

Blockly.Blocks.BH1745_isDetectColor = {
    init:function(){
        var COLOR = [
            ["红色",'RED'],
            ["橙色",'ORANGE'],
            ["黄色",'YELLOW'],
            ["绿色",'GREEN'],
            ["青色",'CYAN'],
            ["蓝色",'BLUE'],
            ["紫色",'PURPLE']
        ];
        this.appendDummyInput()
            .appendField("颜色传感器")
            .appendField(new Blockly.FieldTextInput("bh"), "IST")
            .appendField("判断颜色")
            .appendField(new Blockly.FieldDropdown(COLOR),'COLOR');
        this.setColour("#00A29A");
        this.setOutput(true, Boolean);
        this.setInputsInline(true);
        this.setTooltip("判断是否为所选颜色")
    }
};

Blockly.Blocks.BH1745_readColorValue = {
    init:function(){
        var VAR = [
            ["红色",'red'],
            ["绿色",'green'],
            ["蓝色",'blue'],
            ["RGB",'rgb'],
            ["色相",'hue'],
            ["饱和度",'saturation'],
            ["亮度",'lightness']
        ];
        this.appendDummyInput()
            .appendField("颜色传感器")
            .appendField(new Blockly.FieldTextInput("bh"), "IST")
            .appendField("获取")
            .appendField(new Blockly.FieldDropdown(VAR),'VAR')
            .appendField("值");
        this.setColour("#00A29A");
        this.setOutput(true,Number);
        this.setInputsInline(true);
        this.setColour("#00A29A");
        this.setTooltip("判断是否为所选颜色")
    }
};

Blockly.Blocks.BH1745_setRgbcMode = {
    init:function(){
        var VAR = [
            ["8位",'RGBC_8_BIT'],
            ["16位",'RGBC_16_BIT']
        ];
        this.appendDummyInput()
            .appendField("颜色传感器")
            .appendField(new Blockly.FieldTextInput("bh"), "IST")
            .appendField("设置RGB模式为")
            .appendField(new Blockly.FieldDropdown(VAR),'VAR');
        this.setColour("#00A29A");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setTooltip("设置RBG模式")
    }
};

Blockly.Blocks.BH1745_setGain = {
    init:function(){
        var VAR = [
            ["1倍",'GAIN_1X'],
            ["2倍",'GAIN_2X'],
            ["16倍",'GAIN_16X']
        ];
        this.appendDummyInput()
            .appendField("颜色传感器")
            .appendField(new Blockly.FieldTextInput("bh"), "IST")
            .appendField("设置增益为")
            .appendField(new Blockly.FieldDropdown(VAR),'VAR');
        this.setColour("#00A29A");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setTooltip("设置增益")
    }
};

//电机
Blockly.Blocks.Motor_begin = {

    init: function() {
  
      this.appendDummyInput("")
      .appendField("电机")
      .appendField(new Blockly.FieldTextInput("motor"), "IST")
      .appendField("设置引脚")
      .appendField(new Blockly.FieldDropdown(profile.default.digital), "pin")
      this.setColour("#00A29A");
      this.setInputsInline(true);
      this.setPreviousStatement(true);
      this.setNextStatement(true);
      this.setTooltip("设置电机引脚");
      this.setHelpUrl('');
  }
  
};

Blockly.Blocks.Motor_setStatus = {
    init:function(){
        var VAR = [
            ["开",'1'],
            ["关",'0'],
        ];
        this.appendDummyInput()
            .appendField("电机")
            .appendField(new Blockly.FieldTextInput("motor"), "IST")
            .appendField("设置状态为")
            .appendField(new Blockly.FieldDropdown(VAR),'VAR');
        this.setColour("#00A29A");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setTooltip("设置电机状态");
    }
};

//舵机
Blockly.Blocks.Servo_begin = {

    init: function() {
  
      this.appendDummyInput("")
      .appendField("舵机")
      .appendField(new Blockly.FieldTextInput("servo"), "IST")
      .appendField("设置引脚")
      .appendField(new Blockly.FieldDropdown(profile.default.digital), "pin")
      this.setColour("#00A29A");
      this.setInputsInline(true);
      this.setPreviousStatement(true);
      this.setNextStatement(true);
      this.setTooltip("设置舵机引脚");
      this.setHelpUrl('');
  }
  
};

Blockly.Blocks.Servo_setAngle = {
    init:function(){
        this.appendDummyInput()
            .appendField("舵机")
            .appendField(new Blockly.FieldTextInput("servo"), "IST")
            .appendField("设置角度为(0~270)");
        this.appendValueInput("angle");
        this.setColour("#00A29A");
        this.setInputsInline(true);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setTooltip("设置电机状态");
    }
};