#pragma once

#include <xcb/xcb.h>

class PlatformLinux
{

public:
    PlatformLinux();
    ~PlatformLinux();

private:
    xcb_connection_t* mConnection;
    
};