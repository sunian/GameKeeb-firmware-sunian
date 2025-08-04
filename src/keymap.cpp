//#include "pico/stdlib.h"
#include <stdlib.h>

#include "inputs.hpp"
#include "keycode.h"
#include "persistence/functions.hpp"
#include "persistence/pages/runtime_remapping.hpp"

// https://github.com/picoruby/prk_firmware/wiki/Keycodes

const KeyMapping defaultKeymap[24] = {
    {&RectangleInput::left, KC_J},
    {&RectangleInput::right, KC_L},
    {&RectangleInput::down, KC_K},
    {&RectangleInput::up, KC_I},
    {&RectangleInput::mx, KC_V},
    {&RectangleInput::my, KC_B},
    {&RectangleInput::start, KC_ENTER},
    {&RectangleInput::cLeft, KC_LSFT},
    {&RectangleInput::cRight, KC_F},
    {&RectangleInput::cDown, KC_C},
    {&RectangleInput::cUp, KC_E},
    {&RectangleInput::a, KC_S},
    {&RectangleInput::b, KC_D},
    {&RectangleInput::x, KC_O},
    {&RectangleInput::y, KC_U},
    {&RectangleInput::z, KC_W},
    {&RectangleInput::l, KC_TAB},
    {&RectangleInput::r, KC_Q},
    {&RectangleInput::ls, KC_1},
    {&RectangleInput::ms, KC_2},
    {&RectangleInput::dLeft, KC_LEFT},
    {&RectangleInput::dRight, KC_RIGHT},
    {&RectangleInput::dDown, KC_DOWN},
    {&RectangleInput::dUp, KC_UP},
};

const KeyMapping remappedKeymap[24] = {
    { &RectangleInput::left, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.leftKey },
    { &RectangleInput::right, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.rightKey },
    { &RectangleInput::down, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.downKey },
    { &RectangleInput::up, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.upKey },
    { &RectangleInput::mx, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.mxKey },
    { &RectangleInput::my, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.myKey },
    { &RectangleInput::start, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.startKey },
    { &RectangleInput::cLeft, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.cLeftKey },
    { &RectangleInput::cRight, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.cRightKey },
    { &RectangleInput::cDown, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.cDownKey },
    { &RectangleInput::cUp, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.cUpKey },
    { &RectangleInput::a, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.aKey },
    { &RectangleInput::b, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.bKey },
    { &RectangleInput::x, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.xKey },
    { &RectangleInput::y, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.yKey },
    { &RectangleInput::z, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.zKey },
    { &RectangleInput::l, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.lKey },
    { &RectangleInput::r, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.rKey },
    { &RectangleInput::ls, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.lsKey },
    { &RectangleInput::ms, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.msKey },
    { &RectangleInput::dLeft, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.dLeftKey },
    { &RectangleInput::dRight, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.dRightKey },
    { &RectangleInput::dDown, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.dDownKey },
    { &RectangleInput::dUp, Persistence::read<Persistence::Pages::RuntimeRemapping>()->keyRemapping.dUpKey },
};

KeyMapping* getKeymap() {
  bool remapped = Persistence::isnt0xFF(
      Persistence::read<Persistence::Pages::RuntimeRemapping>()
          ->keyRemapping.configured);

  return remapped ? (KeyMapping*)remappedKeymap : (KeyMapping*)defaultKeymap;
}
