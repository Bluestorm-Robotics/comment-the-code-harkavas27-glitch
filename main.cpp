/*
 * Comment the Code!
 * ===================================
 * 
 * Welcome to your second Git assignment!
 * 
 * Task: Below is a working program with NO comments. Your job is to add comments that explain what the code does and WHY each part exists.
 * This is a real-world skill—you'll often inherit uncommented code from teammates or past projects.
 *  Rules:
•	Add a file header block comment at the top
•	Add section headers (like // ===== HARDWARE OBJECTS =====)
•	Add inline comments explaining non-obvious lines
•	Add a block comment before each function explaining its purpose
  * Save this file (Ctrl+S on PC, Cmd+S on Mac)
  * Commit your changes using VS Code's Source Control panel
  * 4. Push your changes to GitHub


The Uncommented Code:

// ============================================
// YOUR NAME AND DATE GO HERE (uncomment and edit the line below):
// 
// Author: Sofiia Harkava
// Date:   Dec 5th 2025
// AI:  Not yet
// ============================================*/

// including the zumo library:

#include <Zumo32U4.h>

// naming the hardware elements:
 
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4OLED display;

// sets the mode variable to 0 initially
 
int mode = 0;

// the function to display the mode the robot is in (either waiting, ready, or running)
 
void showMode() {
    display.clear(); // clears the display
    display.setLayout21x8();
    display.gotoXY(0, 0); // set the cordinated the text will be displayed on
    display.print(F("Mode: ")); // displays the text
    display.print(mode); // displays the mode in which the robot is
    
    display.gotoXY(0, 2); // manipulates the screen on coordinates 0; 2
    if (mode == 0) { // this function tells the robot which mode to display depending on which button was pressed
        display.print(F("IDLE")); 
    } else if (mode == 1) {
        display.print(F("READY"));
    } else if (mode == 2) {
        display.print(F("RUNNING"));
    }
    
    display.gotoXY(0, 7);
    display.print(F("A:- B:+ C:Reset")); // displays the meaning of each button in respect to the mode
}
 
void setup() { // this function only runs once and tell the user that the program running is the mode selector
    Serial.begin(115200);
    Serial.println(F("Mode Selector"));
    showMode(); // runs the showmode function
}
 
void loop() { // this functions allows the button pressed to select the mode and runs multiple times bc its a loop
    if (buttonA.getSingleDebouncedPress()) { // buttonA decreases the mode by two units and blinks the yellow light once
        if (mode > 0) {
            mode--;
        }
        ledYellow(1); delay(50); ledYellow(0);
        showMode();
        Serial.print(F("Mode: ")); Serial.println(mode);
    }
    
    if (buttonB.getSingleDebouncedPress()) { //  buttonB adds two units to the mode value and blinks the yellow light once
        if (mode < 2) {
            mode++;
        }
        ledYellow(1); delay(50); ledYellow(0);
        showMode();
        Serial.print(F("Mode: ")); Serial.println(mode);
    }
    
    if (buttonC.getSingleDebouncedPress()) { //  buttonC set the mode to zero and blicnks the yellow light once
        mode = 0;
        ledYellow(1); delay(50); ledYellow(0);
        showMode();
        Serial.println(F("Mode reset to 0"));
    }
    
    delay(10); // wait 10 ms before running again
}
