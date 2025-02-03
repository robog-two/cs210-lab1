#include <stdio.h>
#include <stdbool.h>

bool isInRange(int number, int min, int max) {
  return (min <= number) && (number <= max);
}

int main(){
  char ch;

  while (ch != '!') {
    printf("Enter a character (! to stop):  ");
    scanf(" %c", &ch);
    printf("Original character: %c\n", ch);

    // Show next letter if within a-y
    if (isInRange(ch, 'a', 'y')) {
      char following = ch + 1;
      printf("Following character:  %c\n", following);
    }

    /*
    ASCII Character Values
    a: 97
    z: 122
    A: 65
    Z: 90

    A-Z comes before a-z, and a-z are 32 characters after
    Therefore flipping the 32's place bit with XOR
    changes the case of the letter.
    */

    if (isInRange(ch, 'a', 'z') || isInRange(ch, 'A', 'Z')) {
      // ^ is a bitwise XOR e.g. A -> a looks like 1000001 ^ 0100000 -> 1100001
      ch = ch ^ 32;
      printf("Flipped character:  %c\n", ch);
    }

    fflush(stdout);
  }
  return 0;
}
