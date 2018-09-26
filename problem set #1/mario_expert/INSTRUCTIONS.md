Mario
===

tl;dr
---

Implement a program that prints out a double half-pyramid of a specified height, per the below.

    $ ./mario
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####

Background
---

Toward the beginning of World 1-1 in Nintendo's Super Mario Brothers, Mario must hop over two "half-pyramids" of blocks as he heads toward a flag pole. Below is a screenshot.

![Super Mario Brothers](data:image/png;base64,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)


Specification
---

  -  Write, in a file called `mario.c` in your `~/workspace/pset1/mario/more/` directory, a program that recreates these half-pyramids using hashes (`#`) for blocks.

  -  To make things more interesting, first prompt the user for the half-pyramids' heights, a non-negative integer no greater than `23`. (The height of the half-pyramids pictured above happens to be 4, the width of each half-pyramid `4`, with an a gap of size `2` separating them.)

  -  If the user fails to provide a non-negative integer no greater than `23`, you should re-prompt for the same again.

  -  Then, generate (with the help of `printf` and one or more loops) the desired half-pyramids.

    Take care to left-align the bottom-left corner of the left-hand half-pyramid with the left-hand edge of your terminal window.


Usage
---

Your program should behave per the example below. Assumed that the underlined text is what some user has typed.

    $ ./mario
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####

    $ ./mario
    Height: 0

    $ ./mario
    Height: -5
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####

    $ ./mario
    Height: -5
    Height: five
    Height: 40
    Height: 24
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####
