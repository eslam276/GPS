#include <stdlib.h>
#include <string.h>


#include <SoftwareSerial.h>





String inputString = ""; // a string to hold incoming data
boolean stringComplete = false; // whether the string is complete
String signal = "$GPGLL";




int AvgBPS = 80 ;



char arr[100] = "Langtude = ";


void setup() 
{

  Serial.begin(9600);
  

  inputString.reserve(200);


}





void loop() {


 
  // put your main code here, to run repeatedly:
 if (stringComplete) {
        String BB = inputString.substring(0, 6);
        if (BB == signal) {
            String LAT = inputString.substring(7, 17);
            int LATperiod = LAT.indexOf('.');
            int LATzero = LAT.indexOf('0');
            if (LATzero == 0) {
                LAT = LAT.substring(1);
            }

            

            String LON = inputString.substring(20, 31);
            int LONperiod = LON.indexOf('.');
            int LONTzero = LON.indexOf('0');
            if (LONTzero == 0) {
                LON = LON.substring(1);
            }

              



            char arr[100] = "Latitude = ";

   



             char BPS[3];




   


              strcat(arr,LAT.c_str());
              strcat(arr," longtude = ");
              strcat(arr,LON.c_str());
              strcat(arr,"  AVG BPS = ");




              sprintf(BPS, "%d", AvgBPS);
              strcat(arr,BPS);

              

              Serial.println(arr);
              Serial.println("-------------------------------");




            

        }
         

        // Serial.println(inputString);
        // clear the string:
        inputString = "";
        stringComplete = false;
    }
}





void serialEvent() {
    while (Serial.available()) {
        // get the new byte:
        char inChar = (char) Serial.read();
        // add it to the inputString:
        inputString += inChar;
        // if the incoming character is a newline, set a flag
        // so the main loop can do something about it:
        if (inChar == '\n') {
            stringComplete = true;
        }
    }
}


