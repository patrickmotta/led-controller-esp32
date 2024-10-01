#include <FastLED.h>

#define LED_PIN 12 
#define NUM_LEDS 8
#define BRIGHTNESS 64
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BUTTON_POWER_PIN 14
#define BUTTON_COLOR_BLUE_PIN 27 
#define BUTTON_COLOR_RED_PIN 26
#define BUTTON_COLOR_YELLOW_PIN 25
#define BUTTON_COLOR_WHITE_PIN 33

CRGB leds[NUM_LEDS];
bool ledStatus = true;
String color;

void setup() {
  pinMode(BUTTON_POWER_PIN, INPUT_PULLUP);
  pinMode(BUTTON_COLOR_BLUE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_COLOR_RED_PIN, INPUT_PULLUP);
  pinMode(BUTTON_COLOR_YELLOW_PIN, INPUT_PULLUP);
  pinMode(BUTTON_COLOR_WHITE_PIN, INPUT_PULLUP);

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  color = "white";  

  setColor(color);
  FastLED.show();
}

void loop() {

// Verifica se o botão de ligar/desligar foi pressionado
  if (digitalRead(BUTTON_POWER_PIN) == LOW) {   
    delay(50);  // Debouncing
    if (digitalRead(BUTTON_POWER_PIN) == LOW) { 
      ledStatus = !ledStatus;  

      if (ledStatus) {
        setColor(color);
      } else {
        setColor("black");
      }
      FastLED.show();

      while (digitalRead(BUTTON_POWER_PIN) == LOW) {
       // Espera até o botão ser solto
      }
    }
  }

  // Verifica se o botão de cor azul foi pressionado
  if (digitalRead(BUTTON_COLOR_BLUE_PIN) == LOW) {
    delay(50);
    if (digitalRead(BUTTON_COLOR_BLUE_PIN) == LOW) {
      setColor("blue"); 
      FastLED.show();
      while (digitalRead(BUTTON_COLOR_BLUE_PIN) == LOW) {
      }
    }
  }

   // Verifica se o botão de cor vermelha foi pressionado
  if (digitalRead(BUTTON_COLOR_RED_PIN) == LOW) {
    delay(50); 
    if (digitalRead(BUTTON_COLOR_RED_PIN) == LOW) {
      setColor("red");  
      FastLED.show();
      while (digitalRead(BUTTON_COLOR_RED_PIN) == LOW) {
      }
    }
  }

   // Verifica se o botão de cor amarela foi pressionado
  if (digitalRead(BUTTON_COLOR_YELLOW_PIN) == LOW) {
    delay(50);
    if (digitalRead(BUTTON_COLOR_YELLOW_PIN) == LOW) {
      setColor("yellow");
      FastLED.show();
      while (digitalRead(BUTTON_COLOR_YELLOW_PIN) == LOW) {
      }
    }
  }

   // Verifica se o botão de cor branca foi pressionado
  if (digitalRead(BUTTON_COLOR_WHITE_PIN) == LOW) {
    delay(50);
    if (digitalRead(BUTTON_COLOR_WHITE_PIN) == LOW) {
      setColor("white"); 
      FastLED.show();
      while (digitalRead(BUTTON_COLOR_WHITE_PIN) == LOW) {
      }
    }
  }
  
}

// Função para definir a cor
void setColor(String selectedColor) {
  for(int i = 0; i < NUM_LEDS; i++) {
    if (selectedColor == "white") {
      leds[i] = CRGB::White;
    } else if (selectedColor == "blue") {
      leds[i] = CRGB::Blue;
    } else if (selectedColor == "red") {
      leds[i] = CRGB::Red;
    } else if (selectedColor == "green") {
      leds[i] = CRGB::Green;
    } else if (selectedColor == "yellow") {
      leds[i] = CRGB::Yellow;
    } else {
      leds[i] = CRGB::Black;
    }
  }
}
