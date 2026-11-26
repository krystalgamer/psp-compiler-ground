/* C++ declarations for main.cpp (the demo's own objects; no DWARF: class
   names, methods and vtable order from the symbol table, see
   tools/dwarf2cpp.py UTST99332 demo_duck main).  Layouts are only filled in
   as far as decompiled code needs them. */
#ifndef DEMO_DUCK_MAIN_HPP
#define DEMO_DUCK_MAIN_HPP

/* vtables and typeinfo stay in the module's data: never emit them here */
#pragma interface

#include <ostream>
#include <string>
#include <stdlib.h>

extern "C" {
#include "common.h"
}

#include <vector>

/* one header per part of the demo's code (in dependency order) */
#include "demo/math.hpp"
#include "demo/base.hpp"
#include "demo/sgl.hpp"
#include "demo/scene.hpp"
#include "demo/waterpatch.hpp"
#include "demo/apps.hpp"

#endif
