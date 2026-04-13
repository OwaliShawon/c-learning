#include <stdio.h>
#include <string.h> // We need this to copy strings into char arrays!

// --- 1. Struct Definition ---
// A struct holds ALL these variables simultaneously.
struct Player {
    char name[50];
    int hp;
    float score;
};

// --- typedef Struct ---
// Much cleaner syntatic sugar! 
typedef struct {
    int id;
    int items;
} Inventory;

// --- 2. Union Definition ---
// A union reuses the exact same memory for ALL of these. 
// It is only as large as its largest member (the char array).
typedef union {
    int integerValue;
    float floatValue;
    char textValue[20];
} DataPacket;


int main() {
    printf("--- 1. Structs ---\n");
    struct Player p1;
    
    // We cannot do p1.name = "John", we must strictly copy the string memory
    strcpy(p1.name, "Paladin_John"); 
    p1.hp = 100;
    p1.score = 55.5f;

    printf("Player Name: %s\n", p1.name);
    printf("Player HP: %d\n", p1.hp);
    printf("Player Score: %.1f\n", p1.score);


    printf("\n--- 2. Typedef Structs ---\n");
    // Notice we don't need the 'struct' keyword here!
    Inventory inv1 = {204, 99}; // We can initialize it cleanly inline too!
    printf("Inventory ID [%d] holds %d items.\n", inv1.id, inv1.items);


    printf("\n--- 3. Unions ---\n");
    DataPacket packet;
    
    // If we write an int, the union holds that int fine.
    packet.integerValue = 42;
    printf("Packet Integer: %d\n", packet.integerValue);

    // DANGER: If we now write a float, the integer is destroyed because 
    // the union overwrites that exact shared memory space!
    packet.floatValue = 3.1415f;
    printf("Packet Float: %f\n", packet.floatValue);
    
    // The previously assigned integer is now corrupted garbage!
    printf("Oops! Packet Integer is now: %d\n", packet.integerValue);

    return 0;
}
