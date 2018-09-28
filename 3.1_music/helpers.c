// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    char *token;

    // get numerateur : substring prior "/"
    token = strtok(fraction, "/");
    int numerateur = atoi(token);

    // get denominateur : substring prior "/", i.e rest
    token = strtok(NULL, "/");
    int denominateur = atoi(token);

    //printf("%i / %i\n", numerateur, denominateur);

    int duration;
    // assuming Y is power of 2,
    for (int power = 0; pow(2, power) <= denominateur; power ++)
    {
        if (denominateur == pow(2, power))
        {
            duration = round(numerateur * pow(2, 3 - power));
        }
    }
    //printf("duration: %i", duration);

    return duration;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int semitone_from_a4 = 0;

    // the octave is the last character of note
    int octave = atoi(&note[strlen(note) - 1]);
    semitone_from_a4 += 12 * (octave - 4);

    //the note is the strlen-1 long substring of note
    // create the substing by removing the end of the string (octava)
    //printf("%i>%i | note: %s", octave, semitone_from_a4, note);
    note[strlen(note) - 1] = '\0';
    //printf(" | new note: %s", note);
    if (strcmp(note, "C") == 0)
    {
        semitone_from_a4 += -9;
    }
    else if (strcmp(note, "C#") == 0 || strcmp(note, "Db") == 0)
    {
        semitone_from_a4 += -8;
    }
    else if (strcmp(note, "D") == 0)
    {
        semitone_from_a4 += -7;
    }
    else if (strcmp(note, "D#") == 0 || strcmp(note, "Eb") == 0)
    {
        semitone_from_a4 += -6;
    }
    else if (strcmp(note, "E") == 0)
    {
        semitone_from_a4 += -5;
    }
    else if (strcmp(note, "F") == 0)
    {
        semitone_from_a4 += -4;
    }
    else if (strcmp(note, "F#") == 0 || strcmp(note, "Gb") == 0)
    {
        semitone_from_a4 += -3;
    }
    else if (strcmp(note, "G") == 0)
    {
        semitone_from_a4 += -2;
    }
    else if (strcmp(note, "G#") == 0 || strcmp(note, "Ab") == 0)
    {
        semitone_from_a4 += -1;
    }
    else if (strcmp(note, "A") == 0)
    {
        semitone_from_a4 += 0;
    }
    else if (strcmp(note, "A#") == 0 || strcmp(note, "Bb") == 0)
    {
        semitone_from_a4 += 1;
    }
    else if (strcmp(note, "B") == 0)
    {
        semitone_from_a4 += 2;
    }
    else
    {
        printf("\nError: unknown note\n");
        return 1;
    }

    return round(440 * pow(2, semitone_from_a4 / 12.));
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}