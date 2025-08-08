#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
	{36+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
	{36+1, 6,hsv}
#define SET_NUMPAD(hsv) \
	{36+16, 1, hsv}, \
	{36+23, 3, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
	{36+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
	{1, 6, hsv}, \
	{36+1, 6, hsv}

enum sofle_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _FN,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BS   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    | Mute  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | GUI  | Alt  | FN   |Lower | / Space /       \ Enter\  |Raise | Left | Down | Right|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_BASE] = LAYOUT(
  KC_ESC,  KC_1,  KC_2,    KC_3,    KC_4,  KC_5,                      KC_6,  KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,  KC_T,                      KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
  KC_LCTL, KC_A,  KC_S,    KC_D,    KC_F,  KC_G,                      KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,  KC_B,  XXXXXXX,   KC_MUTE, KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
                  KC_LGUI, KC_LALT, FN,    LOWER, KC_SPC,    KC_ENT,  RAISE, KC_LEFT, KC_DOWN, KC_RIGHT
),

/*
 * LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BS   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |-------.    ,-------|   *  |   4  |   5  |   6  |   +  |  =   |
 * |------+------+------+------+------+------|       |    | Mute  |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|   /  |   1  |   2  |   3  |   -  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | GUI  | Alt  | FN   |Lower | / Space /       \ Enter\  |Raise | Left |   0  |  .   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_LOWER] = LAYOUT(
  _______, KC_1,  KC_2,    KC_3,    KC_4,  KC_5,                          KC_6,    KC_7,  KC_8, KC_9,  KC_0,    _______,
  _______, KC_1,  KC_2,    KC_3,    KC_4,  KC_5,                          KC_6,    KC_7,  KC_8, KC_9,  KC_0,    _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_ASTR, KC_4,  KC_5, KC_6,  KC_PLUS, KC_EQL,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_SLSH, KC_1,  KC_2, KC_3,  KC_MINS, _______,
                  _______, _______, _______, _______, _______,   _______, _______, _______, KC_0, KC_DOT
),

/*
 * RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  | BS   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctrl |   `  |   ~  |   /  |   {  |   [  |-------.    ,-------|   ]  |   }  |   \  |   -  |   =  |  |   |
 * |------+------+------+------+------+------|       |    | Mute  |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |   _  |   +  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | GUI  | Alt  | FN   |Lower | / Space /       \ Enter\  |Raise | Left | Down | Right|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_RAISE] = LAYOUT(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_GRV,  KC_TILD, KC_SLSH, KC_LCBR, KC_LBRC,             KC_RBRC, KC_RCBR, KC_BSLS, KC_MINS, KC_EQL,  KC_PIPE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,KC_UNDS, KC_PLUS, _______,
                  _______, _______, _______, _______, _______,    _______,  _______, _______, KC_0, KC_DOT
),

/*
 * FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctrl |      | Sleep|      |      |      |-------.    ,-------| Home | Pgdn | Pgup | End  | Vol+ | F12  |
 * |------+------+------+------+------+------|       |    | Mute  |------+------+------+------+------+------|
 * |LShift|      |      | Calc |      | Boot |-------|    |-------| Mute |      |  Up  |      | Vol- |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | GUI  | Alt  | FN   |Lower | / Space /       \ Enter\  |Raise | Left | Down | Right|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_FN] = LAYOUT(
  _______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                         KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_DEL,
  _______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                         KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
  _______, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_VOLU, KC_F12,
  _______, XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, QK_BOOT, XXXXXXX, _______, KC_MUTE, XXXXXXX, KC_UP, XXXXXXX, KC_VOLD, _______,
                  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];

// Base
const rgblight_segment_t PROGMEM layer_base_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_CYAN));

// Lower
const rgblight_segment_t PROGMEM layer_lower_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_BLUE),
	SET_UNDERGLOW(HSV_BLUE),
	SET_NUMPAD(HSV_BLUE)
);

// Raise
const rgblight_segment_t PROGMEM layer_raise_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_AZURE));

// FN
const rgblight_segment_t PROGMEM layer_fn_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_RED));

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	layer_base_lights,
	layer_lower_lights,
	layer_raise_lights,
	layer_fn_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _FN));

    	return state;
}

void keyboard_post_init_user(void) {
	// Set the solid color effect (on by default) to off.
	rgblight_sethsv(HSV_OFF);

	rgblight_layers = my_rgb_layers;
}
#endif

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
	oled_write_P(PSTR("\n\n"), false);
	oled_write_P(PSTR("LAYER:\n"), false);

	switch (get_highest_layer(layer_state)) {
		case _LOWER:
			oled_write_P(PSTR("Lower"), false);
           		break;
		case _RAISE:
            		oled_write_P(PSTR("Raise"), false);
           		break;
    		case _FN:
        		oled_write_P(PSTR(" Fn  "), false);
            		break;
        	default:
            		oled_write_P(PSTR(" Base"), false);
    	}
    	oled_write_P(PSTR("\n\n"), false);
    	oled_write_P(PSTR("Sofle\n  RBG"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}
#endif

