#include <stdio.h>

enum AccelRange {
    AFS_2G = 0, AFS_4G = 1, AFS_8G = 2, AFS_16G = 3 
};

enum Bandwidth {
    BW_500Hz = 6 
};

enum OpMode {
    MODE_Normal = 0 
};

struct AccelConfig {
    enum AccelRange gRange; 
    enum Bandwidth bandwidth; 
    enum OpMode mode; 
    unsigned char AccConfigValue; 
};

int main() {
    struct AccelConfig sensor; 
    
    // Value assignments
    sensor.gRange = AFS_8G; 
    sensor.bandwidth = BW_500Hz; 
    sensor.mode = MODE_Normal; 

    // Bitwise operation: Shifting and combining
    sensor.AccConfigValue = (sensor.mode << 5) | (sensor.bandwidth << 2) | (sensor.gRange);

    // Outputs
    printf("AccConfigValue(Decimal): %d\n", sensor.AccConfigValue); 
    printf("AccConfigValue(Hexadecimal): 0x%x\n", sensor.AccConfigValue); 
    

    printf("AccConfigValue(Binary): 0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (sensor.AccConfigValue >> i) & 1);
    }
    printf("\n");

    return 0;
}