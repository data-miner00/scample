#ifndef SHAUN_H
#define SHAUN_H

#define what int

// union uses the same memory location across fields
union test {
    char field1[50];
    int field2 :7; // with bitfields
};

#endif
