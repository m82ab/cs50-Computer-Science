from cs50 import get_string


while True:
    # Receive input from the user
    str = get_string('Text: ')
    # Initial values of functions
    Contents = 0
    i = 0
    alphabets = 0
    sentences = 0
    specific = 0
    words = 1
    sentences = 0
    if (str):
        # Repeat the loop
        for i in range(len(str)):
            if (str[i].isalpha()):
                alphabets += 1
            elif (str[i].isnumeric()):
                figure += 1
            elif (str[i] == ' ' and str[i + 1]):
                words += 1
            elif (str[i] == '?' or str[i] == '!' or str[i] == '.'):
                sentences += 1
            else:
                specific += 1
        # Get L - the average number of letters per 100 words in the text
        L = float(alphabets / words * 100)

        # Get S - the average number of sentences per 100 words in the text
        S = float(sentences / words * 100)

        # Legibility
        Contents = round((float)(0.0588 * L - 0.296 * S - 15.8))

        # Output
        if (Contents >= 16):
            print('Grade 16+')
        elif (Contents < 1):
            print('Before Grade 1')
        else:
            print('Grade ', Contents)

        break