void print_bits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31;  // Start with the leftmost bit
    
    for (i = 0; i < 32; i++) {
        unsigned int bit = (num & mask) ? 1 : 0;
        printf("%d", bit);
        
        // Shift the mask to the right by 1 position
        mask >>= 1;
    }
    
    printf("\n");
}

int main() {
    unsigned int num;
    
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    
    printf("Bits representation: ");
    print_bits(num);
    
    return 0;
}
