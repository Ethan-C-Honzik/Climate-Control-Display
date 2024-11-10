#include <Adafruit_SSD1306.h>

#define LOGO_HEIGHT 32
#define LOGO_WIDTH 40

// 'ClimateControls', 40x32px
const unsigned char climateFeetFace[] PROGMEM = {
    0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00,
    0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x78, 0x00, 0x00, 0xff, 0xf0, 0xfc, 0x00, 0x00,
    0xff, 0xf8, 0xfc, 0x00, 0x00, 0xff, 0xf0, 0xfc, 0x00, 0x00, 0xff, 0xe0, 0xfc, 0x00, 0x00, 0x03,
    0xc0, 0xfc, 0x0f, 0x80, 0x03, 0x80, 0x78, 0x0f, 0x80, 0x03, 0x00, 0x00, 0x0f, 0x80, 0x02, 0x00,
    0x00, 0x0f, 0x80, 0x00, 0x00, 0xf8, 0x0f, 0x80, 0x00, 0x01, 0xfc, 0x0f, 0x80, 0x00, 0x03, 0xfc,
    0xff, 0xf8, 0x00, 0x03, 0xfc, 0x7f, 0xf0, 0x00, 0x07, 0xf8, 0x3f, 0xe0, 0xe0, 0x0f, 0xf8, 0x1f,
    0xc1, 0xf8, 0x0f, 0xf0, 0x0f, 0x83, 0xfe, 0x1f, 0xe0, 0x07, 0x07, 0xff, 0xff, 0xe0, 0x02, 0x0f,
    0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xc3,
    0xff, 0x00, 0x00, 0xff, 0x80, 0xff, 0x00, 0x01, 0xff, 0x00, 0x1c, 0x00, 0x03, 0xfe, 0x00, 0x00,
    0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00};

// 'ClimateControlsFeet', 40x32px
const unsigned char climateFeet[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
    0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00,
    0x00, 0xfc, 0x0f, 0x80, 0x00, 0x00, 0x78, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00,
    0x00, 0x0f, 0x80, 0x00, 0x00, 0xf8, 0x0f, 0x80, 0x00, 0x01, 0xfc, 0x0f, 0x80, 0x00, 0x03, 0xfc,
    0xff, 0xf8, 0x00, 0x03, 0xfc, 0x7f, 0xf0, 0x00, 0x07, 0xf8, 0x3f, 0xe0, 0xe0, 0x0f, 0xf8, 0x1f,
    0xc1, 0xf8, 0x0f, 0xf0, 0x0f, 0x83, 0xfe, 0x1f, 0xe0, 0x07, 0x07, 0xff, 0xff, 0xe0, 0x02, 0x0f,
    0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xc3,
    0xff, 0x00, 0x00, 0xff, 0x80, 0xff, 0x00, 0x01, 0xff, 0x00, 0x1c, 0x00, 0x03, 0xfe, 0x00, 0x00,
    0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00};

// 'ClimateControlsFace', 40x32px
const unsigned char climateFace[] PROGMEM = {
    0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00,
    0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x78, 0x00, 0x00, 0xff, 0xf0, 0xfc, 0x00, 0x00,
    0xff, 0xf8, 0xfc, 0x00, 0x00, 0xff, 0xf0, 0xfc, 0x00, 0x00, 0xff, 0xe0, 0xfc, 0x00, 0x00, 0x03,
    0xc0, 0xfc, 0x00, 0x00, 0x03, 0x80, 0x78, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xfc,
    0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0xe0, 0x0f, 0xf8, 0x00,
    0x01, 0xf8, 0x0f, 0xf0, 0x00, 0x03, 0xfe, 0x1f, 0xe0, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x0f,
    0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xc3,
    0xff, 0x00, 0x00, 0xff, 0x80, 0xff, 0x00, 0x01, 0xff, 0x00, 0x1c, 0x00, 0x03, 0xfe, 0x00, 0x00,
    0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00};

// 'ClimateControlsFeetDefrost', 40x32px
const unsigned char climateFeetDefrost[] PROGMEM = {
    0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x07, 0xff, 0x80, 0x00, 0x00, 0x3e, 0x00, 0xf8, 0x00, 0x00,
    0x60, 0x00, 0x0c, 0x00, 0x00, 0x40, 0x00, 0x04, 0x78, 0x00, 0x60, 0x82, 0x0c, 0xfc, 0x00, 0x61,
    0xc7, 0x0c, 0xfc, 0x00, 0x33, 0xef, 0x98, 0xfc, 0x00, 0x30, 0x82, 0x18, 0xfc, 0x00, 0x18, 0x82,
    0x30, 0xfc, 0x0f, 0x8f, 0xff, 0xe0, 0x78, 0x0f, 0x80, 0x82, 0x00, 0x00, 0x0f, 0x80, 0x82, 0x00,
    0x00, 0x0f, 0x80, 0x82, 0x00, 0xf8, 0x0f, 0x80, 0x00, 0x01, 0xfc, 0x0f, 0x80, 0x00, 0x03, 0xfc,
    0xff, 0xf8, 0x00, 0x03, 0xfc, 0x7f, 0xf0, 0x00, 0x07, 0xf8, 0x3f, 0xe0, 0xe0, 0x0f, 0xf8, 0x1f,
    0xc1, 0xf8, 0x0f, 0xf0, 0x0f, 0x83, 0xfe, 0x1f, 0xe0, 0x07, 0x07, 0xff, 0xff, 0xe0, 0x02, 0x0f,
    0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xc3,
    0xff, 0x00, 0x00, 0xff, 0x80, 0xff, 0x00, 0x01, 0xff, 0x00, 0x1c, 0x00, 0x03, 0xfe, 0x00, 0x00,
    0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00};

// 'ClimateControlsDefrost', 40x32px
const unsigned char climateDefrost[] PROGMEM = {
    0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0x81, 0xfe, 0x00, 0x03,
    0xf8, 0x00, 0x1f, 0xc0, 0x0f, 0xe0, 0x00, 0x07, 0xf0, 0x3f, 0x00, 0x00, 0x00, 0xfc, 0x7c, 0x00,
    0x00, 0x00, 0x3e, 0x70, 0x00, 0x00, 0x00, 0x0e, 0x60, 0x00, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00,
    0x00, 0x06, 0x30, 0x00, 0x00, 0x00, 0x0e, 0x38, 0x00, 0x00, 0x00, 0x1c, 0x38, 0x01, 0x00, 0x80,
    0x1c, 0x18, 0x03, 0x81, 0xc0, 0x1c, 0x1c, 0x07, 0xc3, 0xe0, 0x38, 0x0c, 0x0f, 0xe7, 0xf0, 0x30,
    0x0e, 0x03, 0x81, 0xc0, 0x70, 0x06, 0x03, 0x81, 0xc0, 0x60, 0x07, 0x03, 0x81, 0xc0, 0xe0, 0x07,
    0x03, 0x81, 0xc0, 0xe0, 0x03, 0x03, 0x81, 0xc0, 0xc0, 0x03, 0x83, 0x81, 0xc1, 0xc0, 0x01, 0xc3,
    0x81, 0xc3, 0x80, 0x01, 0xc3, 0x81, 0xc3, 0x80, 0x00, 0xe3, 0x81, 0xc7, 0x00, 0x00, 0xff, 0xff,
    0xff, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00, 0x03, 0x81, 0xc0, 0x00, 0x00, 0x03, 0x81, 0xc0,
    0x00, 0x00, 0x03, 0x81, 0xc0, 0x00, 0x00, 0x03, 0x81, 0xc0, 0x00, 0x00, 0x03, 0x81, 0xc0, 0x00};