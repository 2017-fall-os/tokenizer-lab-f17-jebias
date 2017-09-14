When the test file runs it will ask for a string.
The assumption is that the user will type either letters, numbers, or a combination of both.
Mytoc will consider numbers as words if they are in between delimiters.
Mytoc by default will use a space as the delimiter.
for some reason, when using scanf to get input from the user, special characters (e.g. \267p\267 or \307u\307) appear after the word. For now I am just disregarding this. I know the issue is with how I am getting input from the user because mytoc works fine if I hardcode a string for char *str, such as setting char *str = "hello world". With a hardcoded string, mytoc works fine.