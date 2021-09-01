#ifndef UTIL_STRUCTS_H
#define UTIL_STRUCTS_H

struct Ident
{
    bool available;
    String id;
};

struct System{
    int timeLightOn;
    boolean newStatus;
    boolean automatic;
};

#endif