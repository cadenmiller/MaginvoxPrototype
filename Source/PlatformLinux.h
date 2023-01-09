#pragma once

#include <xcb/xcb.h>

class PlatformLinux
{

public:
    PlatformLinux();
    ~PlatformLinux();

    static 

private:
    xcb_connection_t* mConnection;
    
};