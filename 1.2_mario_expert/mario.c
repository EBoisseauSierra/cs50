#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get pyramyd height
    int height = -1;
    while (height < 0 || height > 23)
    {
        height = get_int("Size: ");
    }

    // display pyramid (level 0 = top)
    for (int level = 0; level < height; level++)
    {
        // compute length for current level
        int block_amount = level + 1;
        int space_amount = height - block_amount;
        int gap_amount = 2;

        // print blank
        for (int space = 0; space < space_amount; space ++)
        {
            printf(" ");
        }

        // print left side
        for (int block = 0; block < block_amount; block ++)
        {
            printf("#");
        }

        // print gap
        for (int space = 0; space < gap_amount; space ++)
        {
            printf(" ");
        }

        // print right side
        for (int block = 0; block < block_amount; block ++)
        {
            printf("#");
        }

        //end of level
        printf("\n");
    }
}