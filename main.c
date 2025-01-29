#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isInRange(int number, int min, int max) {
  return (min <= number) && (number <= max);
}

int mapInt(
  int number,
  int startOfRange,
  int endOfRange,
  int startOfNewRange,
  int endOfNewRange
) {
  // These should all be true
  assert(endOfRange > startOfRange);
  assert(endOfNewRange > startOfNewRange);
  assert(isInRange(number, startOfRange, endOfRange));

  // This would be more useful with floats and the second part isn't really necessary,
  // but this is a common function so I figured I'd implement it like this and I can use
  // it with floats later if I really need to
  if (startOfNewRange > startOfRange) {
    return (number - startOfRange + startOfNewRange) / ((endOfRange - startOfRange) / (endOfNewRange - startOfNewRange));
  } else {
    return (number - startOfRange + startOfNewRange) / ((endOfNewRange - startOfNewRange) / (endOfRange - startOfRange));
  }

  // Quick Sanity Check: Number 2 going from a range of 0-2 to 0-4:
  // ((2 - 0) + 0) / ((2 - 0) / (4 - 0))
  // 2 / 0.5
  // 4 ✔️ Correct
}

/*
ASCII Character Values
a: 97
z: 122
A: 65
Z: 90
*/

int main(){
  char ch;

  while (ch != '!') {
    printf("Enter a character (! to stop):  ");
    scanf(" %c", &ch);
    printf("Original character: %c\n", ch);

    // Show next letter if within a-y
    if (isInRange(ch, 97, 121)) {
      char following = ch + 1;
      printf("Following character:  %c\n", following);
    }

    // If lowercase, make uppercase
    if (isInRange(ch, 97, 122)) {
      ch = mapInt(ch, 97, 122, 65, 90);
    } else if (isInRange(ch, 65, 90)) { // And vice versa
    ch = mapInt(ch, 65, 90, 97, 122);
    }

    printf("Flipped character:  %c\n", ch);
    fflush(stdout);
  }
  return 0;
}
