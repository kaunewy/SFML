#pragma once
#pragma warning (disable : 4275)

/// STL
#include <iostream>
#include <string>
#include <fstream>

/// OLD
#include <math.h>
#include <conio.h>
#include <functional>
#include <typeindex>
#include <typeinfo>
#include "Color.h"

/// Collections
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>

/// SFML
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/NetWork.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"


#define MSG(_msg) _msg << "(" << __FILE__ << " : " << __LINE__ << ")"
#define ERROR(_msg) cerr << "Error =>" << MSG(_msg) << endl
#define LOG(_msg) cout << "Verbosity : " << _verbosity " // " << _msg << endl
#define FATAL(_msg) cout << RED << MSG(_msg) << COLORRESET << endl
#define DISPLAY(_msg) cout << MSG(_msg) << endl
#define WARNING(_msg) cout << "Warning => " <<  MSG(_msg) << endl

using namespace std;
using namespace sf;


#define FORCEINLINE __forceinline
#define INLINE __inline
#define CAST(_type, _expr) static_cast<_type>(_expr)
#define Super __super
#define SLEEP(_duration) sleep(_duration);
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
