
from os import path

file_path = input("\nCreate file (please enter the path to file): ")

if path.exists(file_path):
    print("\n\tFile already exists!")
    ans = input("\nDo you want to use this file? (y/n)\n-> ")

    if ans == 'y' or ans == 'Y':
        file = open(file_path, "a")
        ans = input("\nDo you want to erase all content? (y/n)\n-> ")

        if ans == 'y' or ans == 'Y':
            print("\n\tErasing...\n")
            file.seek(0)
            file.truncate()

        else:
            pass

    else:
        exit()

else:
    print("\n\tCreating new file...\n")
    file = open(file_path, "a")
    run=True
    while run==True:
        line=input()
        file.write(line)
        file.write('\n')
        if keyboardinterupt:
            break
file.close()
