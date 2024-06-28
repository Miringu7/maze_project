#include "../inc/main.h"
void loadMap(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    // Read the world map data from the file
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
            if (fscanf(file, "%d", &worldMap[i][j]) != 1)
            {
                fprintf(stderr, "Error reading data from file\n");
                fclose(file);
                return;
            }
        }
    }

    // Close the file
    fclose(file);
}