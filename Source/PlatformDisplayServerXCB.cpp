#include <stdexcept>

#include "PlatformDisplayServerXCB.h"


PlatformDisplayServerXCB::PlatformDisplayServerXCB()
{
    mConnection = xcb_connect(nullptr, nullptr);
}

PlatformDisplayServerXCB::~PlatformDisplayServerXCB()
{
    xcb_disconnect(mConnection);
}


PlatformWindowXCB::Pla