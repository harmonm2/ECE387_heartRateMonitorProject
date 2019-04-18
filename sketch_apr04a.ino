int UpperThreshold = 518;
int LowerThreshold = 490;
String mode = "";
int age = 0; // input an age
    int reading = 0;
    float bpm = 0.0;
    bool IgnoreReading = false;
    bool FirstPulseDetected = false;
    unsigned long FirstPulseTime = 0;
    unsigned long SecondPulseTime = 0;
    unsigned long PulseInterval = 0;
void setup() {
  Serial.begin(38400); // default bluetooth module

}

void loop() {
if(Serial.available()>0){
  //if(mode == "age"){
  mode = Serial.read();
  }
  if(mode == "moderate"){
  reading = analogRead(0); 
      if(reading > UpperThreshold && IgnoreReading == false){
        if(FirstPulseDetected == false){
          FirstPulseTime = millis();
          FirstPulseDetected = true;
        }
        else{
          SecondPulseTime = millis();
          PulseInterval = SecondPulseTime - FirstPulseTime;
          FirstPulseTime = SecondPulseTime;
        }
        IgnoreReading = true;
      }
      if(reading < LowerThreshold){
        IgnoreReading = false;
      }  

      bpm = (1.0/PulseInterval) * 60.0 * 1000;
      //sendMessage(age);
  }
}

//void sendMessage(age){
//  mode = Serial.read();
  
//     if(age < 25){
//      if(bpm < 100){
//      Serial.print(bpm);
//      Serial.println(" BPM Work hard!");
//      Serial.flush();
//      }
//      if(bpm < 120 && bpm >= 100){
//      Serial.print(bpm);
//      Serial.println(" BPM Warm up");
//      Serial.flush();
//      }
//      if(bpm >= 120 && bpm<140){
//      Serial.print(bpm);
//      Serial.println(" BPM Fat burn");
//      Serial.flush();
//      }
//      if(bpm >= 140 && bpm < 160){
//      Serial.print(bpm);
//      Serial.println(" BPM Endurance");
//      Serial.flush();
//      }
//      if(bpm >= 160 && bpm < 180){
//      Serial.print(bpm);
//      Serial.println(" BPM Hardcore training");
//      Serial.flush();
//      }
//      if(bpm >= 180 && bpm < 200){
//      Serial.print(bpm);
//      Serial.println(" BPM Maximun effort");
//      Serial.flush();
//      }
//   }
//
//   if(age < 30 && age >= 25){
//      if(bpm < 98){
//      Serial.print(bpm);
//      Serial.println(" BPM Work hard!");
//      Serial.flush();
//      }
//      if(bpm < 117 && bpm >= 98){
//      Serial.print(bpm);
//      Serial.println(" BPM Warm up");
//      Serial.flush();
//      }
//      if(bpm >= 117 && bpm<137){
//      Serial.print(bpm);
//      Serial.println(" BPM Fat burn");
//      Serial.flush();
//      }
//      if(bpm >= 137 && bpm < 156){
//      Serial.print(bpm);
//      Serial.println(" BPM Endurance");
//      Serial.flush();
//      }
//      if(bpm >= 156 && bpm < 176){
//      Serial.print(bpm);
//      Serial.println(" BPM Hardcore training");
//      Serial.flush();
//      }
//      if(bpm >= 176 && bpm < 195){
//      Serial.print(bpm);
//      Serial.println(" BPM Maximun effort");
//      Serial.flush();
//      }
//   }
//
//      if(age >= 30 && age <35){
//      if(bpm < 95){
//      Serial.print(bpm);
//      Serial.println(" BPM Work hard!");
//      Serial.flush();
//      }
//      if(bpm < 144 && bpm >= 95){
//      Serial.print(bpm);
//      Serial.println(" BPM Warm up");
//      Serial.flush();
//      }
//      if(bpm >= 114 && bpm<133){
//      Serial.print(bpm);
//      Serial.println(" BPM Fat burn");
//      Serial.flush();
//      }
//      if(bpm >= 133 && bpm < 152){
//      Serial.print(bpm);
//      Serial.println(" BPM Endurance");
//      Serial.flush();
//      }
//      if(bpm >= 152 && bpm <171){
//      Serial.print(bpm);
//      Serial.println(" BPM Hardcore training");
//      Serial.flush();
//      }
//      if(bpm >= 171 && bpm < 190){
//      Serial.print(bpm);
//      Serial.println(" BPM Maximun effort");
//      Serial.flush();
//      }
//   }
//
//   if(age >= 35 && age < 40){
//      if(bpm < 93){
//      Serial.print(bpm);
//      Serial.println(" BPM Work hard!");
//      Serial.flush();
//      }
//      if(bpm < 111 && bpm >= 93){
//      Serial.print(bpm);
//      Serial.println(" BPM Warm up");
//      Serial.flush();
//      }
//      if(bpm >= 111 && bpm<130){
//      Serial.print(bpm);
//      Serial.println(" BPM Fat burn");
//      Serial.flush();
//      }
//      if(bpm >= 130 && bpm < 148){
//      Serial.print(bpm);
//      Serial.println(" BPM Endurance");
//      Serial.flush();
//      }
//      if(bpm >= 148 && bpm < 167){
//      Serial.print(bpm);
//      Serial.println(" BPM Hardcore training");
//      Serial.flush();
//      }
//      if(bpm >= 167 && bpm < 185){
//      Serial.print(bpm);
//      Serial.println(" BPM Maximun effort");
//      Serial.flush();
//      }
//   }
// if(age >= 40 && age < 45){
//      if(bpm < 90){
//      Serial.print(bpm);
//      Serial.println(" BPM Work hard!");
//      Serial.flush();
//      }
//      if(bpm < 108 && bpm >= 90){
//      Serial.print(bpm);
//      Serial.println(" BPM Warm up");
//      Serial.flush();
//      }
//      if(bpm >= 108 && bpm<126){
//      Serial.print(bpm);
//      Serial.println(" BPM Fat burn");
//      Serial.flush();
//      }
//      if(bpm >= 126 && bpm < 144){
//      Serial.print(bpm);
//      Serial.println(" BPM Endurance");
//      Serial.flush();
//      }
//      if(bpm >= 144 && bpm < 162){
//      Serial.print(bpm);
//      Serial.println(" BPM Hardcore training");
//      Serial.flush();
//      }
//      if(bpm >= 162 && bpm < 180){
//      Serial.print(bpm);
//      Serial.println(" BPM Maximun effort");
//      Serial.flush();
//      }
//   }
//   
//   if(age > 45){
//      if(bpm < 88){
//      Serial.print(bpm);
//      Serial.println(" BPM Work hard!");
//      Serial.flush();
//      }
//      if(bpm < 105 && bpm >= 88){
//      Serial.print(bpm);
//      Serial.println(" BPM Warm up");
//      Serial.flush();
//      }
//      if(bpm >= 105 && bpm<123){
//      Serial.print(bpm);
//      Serial.println(" BPM Fat burn");
//      Serial.flush();
//      }
//      if(bpm >= 123 && bpm < 140){
//      Serial.print(bpm);
//      Serial.println(" BPM Endurance");
//      Serial.flush();
//      }
//      if(bpm >= 140 && bpm < 158){
//      Serial.print(bpm);
//      Serial.println(" BPM Hardcore training");
//      Serial.flush();
//      }
//      if(bpm >= 158 && bpm < 175){
//      Serial.print(bpm);
//      Serial.println(" BPM Maximun effort");
//      Serial.flush();
//      }
//   }
//}
