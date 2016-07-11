/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 
 
int main(int argc, char* argv[])
{
    // TODO
    typedef uint8_t BYTE;
    // Opening the .raw file
    
    FILE* card = fopen("card.raw", "r");
    FILE* out_fp = NULL;
    char jpgFileName[8];
    
    if (card == NULL) {
        printf("File doesn't exist");
        return 1;
    }
    BYTE buffer[512];
    //buffer = malloc(512);
    int jpgNumber = 0;
    
    // While not EOF
    while (feof(card) == 0) {
        
        fread(&buffer, 512, 1, card);
        if (feof(card) == 1) {
                break;
            }
        // Find the beginning of the jpg file
        if (
            buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 ||  buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)
            ) 
            {
            
            if (jpgNumber != 0) {
                fclose(out_fp);
            }
            
            // Open a new jpg
        
        
            sprintf(jpgFileName, "%03d.jpg", jpgNumber);
            out_fp = fopen(jpgFileName, "w");
    
            jpgNumber++;
            }
        
        
            if (jpgNumber != 0) {
                fwrite(&buffer, 512, 1, out_fp);
            }
            
           
        
    }
    // Close remaining files
    fclose(out_fp);
    fclose(card);
    
}