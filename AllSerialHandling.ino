
//////////
/////////  All Serial Handling Code,
/////////  It's Changeable with the 'outputType' variable
/////////  It's declared at start of code.
/////////

void serialOutput(){   // Decide How To Output Serial.
  switch(outputType){
    case PROCESSING_VISUALIZER:
      sendDataToSerial('S', Signal);     // goes to sendDataToSerial function
      break;
    case SERIAL_PLOTTER:  // open the Arduino Serial Plotter to visualize these data
      Serial.print(BPM);
      Serial.print(",");
      Serial.print(IBI);
      Serial.print(",");
      Serial.println(Signal);
      break;
      case SERIAL_MONITOR:
      Serial.print(BPM);
      
      Serial.print(",");
      Serial.print(steps);
      Serial.print(",");
      Serial.print(" 28C");
      Serial.print(",");
      
      if(BPM < 30){Serial.print("Consult Doctor");}
       if(BPM > 30 && BPM <120){Serial.print("Normal");}
      
      if(BPM > 120){Serial.print("Consult Doctor");
      
      } 
      Serial.print(",");
     //Serial.print("Critical");
      
      if(sensorValue < 400 )
      {
        if(BPM >120)
        {
        Serial.print("Critical");
        }
        else
        { 
          Serial.print("Nill");
          }
      }
      else
      {
       
          Serial.print("Nill");
          
        }
      
      Serial.print(";");
      //Serial.print(sensorValue);
      
      break;
    default:
      break;
  }

}

//  Decides How To OutPut BPM and IBI Data
void serialOutputWhenBeatHappens(){
  switch(outputType){
    case PROCESSING_VISUALIZER:    // find it here https://github.com/WorldFamousElectronics/PulseSensor_Amped_Processing_Visualizer
      sendDataToSerial('B',BPM);   // send heart rate with a 'B' prefix
      sendDataToSerial('Q',IBI);   // send time between beats with a 'Q' prefix
      break;

    default:
      break;
  }
}

//  Sends Data to Pulse Sensor Processing App, Native Mac App, or Third-party Serial Readers.
void sendDataToSerial(char symbol, int data ){
    Serial.print(symbol);
    Serial.println(data);
  }
