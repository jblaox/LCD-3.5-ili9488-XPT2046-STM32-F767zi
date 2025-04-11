#ifndef XPT2046_TOUCH_H_
#define XPT2046_TOUCH_H_

#include "main.h"
#include <stdbool.h>

/*** Redefine if necessary ***/

// Warning! Use SPI bus with < 2.5 Mbit speed, better ~650 Kbit to be save.

#define XPT2046_IRQ_Pin       Touch_IRQ_Pin
#define XPT2046_IRQ_GPIO_Port Touch_IRQ_GPIO_Port
#define XPT2046_CS_Pin        Touch_CS_Pin
#define XPT2046_CS_GPIO_Port  Touch_CS_GPIO_Port

#define MOSI_GPIO_Port        Touch_DIN__MOSI_GPIO_Port
#define MOSI_Pin              Touch_DIN__MOSI_Pin
#define SCK_GPIO_Port         Touch_SCK_GPIO_Port
#define SCK_Pin               Touch_SCK_Pin
#define CS_GPIO_Port          Touch_CS_GPIO_Port
#define CS_Pin                Touch_CS_Pin
#define MISO_GPIO_Port        Touch_Out__MISO_GPIO_Port
#define MISO_Pin              Touch_Out__MISO_Pin

//#define Touch_DIN__MOSI_Pin GPIO_PIN_7
//#define Touch_DIN__MOSI_GPIO_Port GPIOF
//#define Touch_Out__MISO_Pin GPIO_PIN_8
//#define Touch_Out__MISO_GPIO_Port GPIOF
//#define Touch_CS_Pin GPIO_PIN_9
//#define Touch_CS_GPIO_Port GPIOF
//#define Touch_SCK_Pin GPIO_PIN_1
//#define Touch_SCK_GPIO_Port GPIOG
//#define XPT2046_IRQ_Pin       IRQ_Pin
//#define XPT2046_IRQ_GPIO_Port IRQ_GPIO_Port
//#define XPT2046_CS_Pin        CS_Pin
//#define XPT2046_CS_GPIO_Port  CS_GPIO_Port

// change depending on screen orientation
#define XPT2046_SCALE_X 479
#define XPT2046_SCALE_Y 319

// to calibrate uncomment UART_Printf line in ili9341_touch.c
#define XPT2046_MIN_RAW_X 202
#define XPT2046_MAX_RAW_X 3829
#define XPT2046_MIN_RAW_Y 188
#define XPT2046_MAX_RAW_Y 3927

// call before initializing any SPI devices
bool XPT2046_TouchPressed();
bool XPT2046_TouchGetCoordinates(volatile  uint16_t* x, volatile  uint16_t* y);

#endif /* XPT2046_TOUCH_H_ */
