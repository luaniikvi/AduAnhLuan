def insert_char_at_index(original_string, char_to_insert, index_to_insert):
    """
    Inserts a character into a string at a specified index.

    :param original_string: The original string where the character will be inserted.
    :param char_to_insert: The character to insert into the string.
    :param index_to_insert: The index at which to insert the character.
    :return: A new string with the character inserted.
    """
    if index_to_insert < 0 or index_to_insert > len(original_string):
        raise ValueError("Index is out of bounds.")

    # Create a new string with the character inserted at the specified index
    new_string = original_string[:index_to_insert] + char_to_insert + original_string[index_to_insert:]
    return new_string

string = input("input the string: ")
bacon = ""
i = 0
for char in string:
    if char == char.upper() :
        bacon += "A"
    else:
        bacon += "B"
    i+=1
    if i == 4:
        bacon += " "
        i=0

bacon = bacon[:-1]

print(bacon)
split_bacon = bacon.split(" ")
print(split_bacon)