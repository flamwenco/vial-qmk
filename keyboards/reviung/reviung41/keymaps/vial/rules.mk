VIA_ENABLE = yes
VIAL_ENABLE = yes
<<<<<<< HEAD

CONSOLE_ENABLE = no
LTO_ENABLE = yes

ifndef CONVERT_TO
	# Disable QMK Settings when using a ProMicro to reduce size:
	QMK_SETTINGS = no
else
	# Enable Mouse Keys when when not using a ProMicro as there will be space:
	MOUSEKEY_ENABLE = yes
endif
=======
VIAL_INSECURE = yes
RGBLIGHT_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no
QMK_SETTINGS = no
COMBO_ENABLE = no
TAP_DANCE_ENABLE = no
>>>>>>> c322bc8cf5 (reviung41 map)
