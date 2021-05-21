'use strict';
 
goog.provide('Blockly.Arduino.Mammoth');//注意脚本类别及路径名称
 
goog.require('Blockly.Arduino');

Blockly.Arduino.BH1745_begin = function() {
    var IST = this.getFieldValue('IST');
    Blockly.Arduino.definitions_['define_BH1745_1'] = '#include <BH1745.h>';
    Blockly.Arduino.definitions_['define_BH1745_2'] = 'BH1745 '+IST+' = BH1745();';
    var sda = this.getFieldValue('sda');
    var scl = this.getFieldValue('scl');
    var code = '';
    code += IST+'.begin(' + sda + ',' + scl + ');\n';
    return code;
};

Blockly.Arduino.BH1745_read = function() {
    var IST = this.getFieldValue('IST');
    var code = ''
    code += IST+'.read();\n';
    return code;
};

Blockly.Arduino.BH1745_readColor = function() {
    var IST = this.getFieldValue('IST');
    var code = '';
    code += IST+'.readColor()';
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};

Blockly.Arduino.BH1745_isDetectColor = function(){
    var IST = this.getFieldValue('IST');
    var color = this.getTitleValue('COLOR');
    var code = IST+'.isDetectColor('+IST+'.'+color+')';
    return [code, Blockly.Arduino.ORDER_ATOMIC];
}

Blockly.Arduino.BH1745_readColorValue = function(){
    var IST = this.getFieldValue('IST');
    var value = this.getTitleValue('VAR');
    
    var code = IST+'.'+value;
    return [code, Blockly.Arduino.ORDER_ATOMIC];
}

Blockly.Arduino.BH1745_setRgbcMode = function() {
    var IST = this.getFieldValue('IST');
    var value = this.getTitleValue('VAR');
    var code = ''
    code += IST+'.setRgbcMode('+IST+'.'+value+');\n';
    return code;
};

Blockly.Arduino.BH1745_setGain = function() {
    var IST = this.getFieldValue('IST');
    var value = this.getTitleValue('VAR');
    var code = ''
    code += IST+'.setGain('+IST+'.'+value+');\n';
    return code;
};

Blockly.Arduino.Motor_begin = function() {
    var IST = this.getFieldValue('IST');
    Blockly.Arduino.definitions_['define_Motor_1'] = '#include <motor.h>';
    Blockly.Arduino.definitions_['define_Motor_'+IST] = 'Motor '+IST+' = Motor();';
    var pin = this.getFieldValue('pin');
    var code = '';
    code += IST+'.begin(' + pin +');\n';
    return code;
};

Blockly.Arduino.Motor_setStatus = function() {
    var IST = this.getFieldValue('IST');
    var value = this.getTitleValue('VAR');
    var code = ''
    code += IST+'.setStatus('+value+');\n';
    return code;
};

Blockly.Arduino.Servo_begin = function() {
    var IST = this.getFieldValue('IST');
    Blockly.Arduino.definitions_['define_Servo_1'] = '#include <servo.h>';
    Blockly.Arduino.definitions_['define_Servo_'+IST] = 'MServo '+IST+'= MServo();';
    var pin = this.getFieldValue('pin');
    var code = ''
    code += IST+'.begin('+pin+');\n';
    return code;
};

Blockly.Arduino.Servo_setAngle = function() {
    var IST = this.getFieldValue('IST');
    var angle = Blockly.Arduino.valueToCode(this, 'angle',Blockly.Arduino.ORDER_ASSIGNMENT) || '0'; 
    var code = ''
    code += IST+'.setAngle('+angle+');\n';
    return code;
};