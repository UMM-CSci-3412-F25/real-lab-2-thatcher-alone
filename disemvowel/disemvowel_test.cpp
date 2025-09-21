#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char const* result = disemvowel((char*) "");
  ASSERT_STREQ("", result);
  free((void*) result);
  result=NULL;
}

TEST(Disemvowel, HandleNoVowels) {
  char const* result = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", result);
  free((void*) result);
  result=NULL;
}

TEST(Disemvowel, HandleOnlyVowels) {
  char const* result = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", result);
  free((void*) result);
  result=NULL;
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char const* result = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", result);
  free((void*) result);
  result=NULL;
}

TEST(Disemvowel, HandlePunctuation) {
  char const* result = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", result);
  free((void*) result);
  result=NULL;
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char const* result = disemvowel(str);
  ASSERT_STREQ("xyz", result);

  free(str);
  free((void*) result);
  str=NULL;
  result=NULL;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
