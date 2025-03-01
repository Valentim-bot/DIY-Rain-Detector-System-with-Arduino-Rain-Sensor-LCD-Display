#include <Adafruit_GFX.h> // Include the Adafruit GFX library for graphics functions
#include <Adafruit_SSD1306.h> // Include the Adafruit SSD1306 library for the OLED display

// OLED display configuration
#define SCREEN_WIDTH 128 // Define the OLED display width in pixels
#define SCREEN_HEIGHT 64 // Define the OLED display height in pixels
#define OLED_RESET -1 // Define the reset pin for the OLED display (-1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT); // Create an instance of the display object


// rainDrop pin A3 has a rainDrop attached to it. Give it a name:
int rainDrop = A3;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the rainDrop's pin an input:
  //pinMode(rainDrop, INPUT);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Check if the display initializes correctly with I2C address 0x3C
    Serial.println(F("SSD1306 allocation failed")); // Print error message if initialization fails
    while (true); // Stay in an infinite loop if initialization fails
  }
  
  display.clearDisplay(); // Clear the display buffer
  display.setTextSize(3); // Set text size to 2
  display.setTextColor(SSD1306_WHITE); // Set text color to white
  display.setCursor(0, 10); // Set cursor position at (0, 10)
  display.println(F("Initializing...")); // Print "Initializing..." on the display
  display.display(); // Update the display with the above settings
  delay(2000); // Wait for 2 seconds
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int rainDropState = digitalRead(rainDrop);
  // print out the state of the button:
  Serial.println(rainDropState);
   if (rainDropState == 0) { // Check if sensor value is greater than 500
     display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(15, 15);
    display.println(F("Rain Drop"));
    display.setCursor(15, 45);
    display.println(F("Detected."));
    display.display();

    
  } else { 

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(50, 0);
    display.println(F("NO"));
    display.setCursor(15, 20);
    display.println(F("Rain Drop"));
    display.setCursor(15, 45);
    display.println(F("Detected."));
    display.display();
 
   
  }

  delay(100);  // delay in between reads for stability
}
