#include "RandomStringGenerator.h"

String RandomStringGenerator::execute(int length)
{
    Serial.println("Generating Random String");
    const char charset[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM123456789";
    const int charsetLength = sizeof(charset) - 1;
    char buffer[length + 1];

    for (int i = 0; i < length; i++)
    {
        int index = random(0, charsetLength);
        buffer[i] = charset[index];
    }

    buffer[length] = '\0'; // Null terminator

    return String(buffer);
}