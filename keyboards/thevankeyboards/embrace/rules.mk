MCU = atmega32u4
F_CPU = 16000000
ARCH = AVR8
F_USB = 16000000

OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
OPT_DEFS += -DBOOTLOADER_SIZE=4096


NO_USB_STARTUP_CHECK = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes



NKRO_ENABLE = yes

#RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
CUSTOM_MATRIX = lite
ENCODER_ENABLE = yes
MIDI_ENABLE = no
AUDIO_ENABLE = no
BLUETOOTH_ENABLE = no
LTO_ENABLE = yes
SRC += matrix.c
