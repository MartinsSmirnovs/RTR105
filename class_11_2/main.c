#include <stdio.h>
#include <string.h>

int main() {
    enum {
        S_SENTENCE        = 100,
        SHORT_WORD_LENGTH = 5
    };

    char sentence[S_SENTENCE];
    memset(sentence, 0, S_SENTENCE);

    printf("Please input a sentence:\n");
    fgets(sentence, S_SENTENCE, stdin);

    int shortWordsCount = 0;
    int wordsCount      = 0;

    for (int i = 0, letterCount = 0; i < S_SENTENCE; i++) {
        const char currentCharacter = sentence[i];

        if (currentCharacter == ' ' || currentCharacter == '.' || currentCharacter == '\n') {
            wordsCount++;

            if (letterCount <= SHORT_WORD_LENGTH) {
                shortWordsCount++;
            }

            letterCount = 0;

            if (currentCharacter == '.' || currentCharacter == '\n') {
                break;
            }
            continue;
        }
        letterCount++;
    }

    printf("Words in sentence: %d\n", wordsCount);
    printf("Short words in sentence: %d\n", shortWordsCount);

    return 0;
}
