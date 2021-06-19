# Password Manager++
Password Manager++ or PM++ is a basic local password manager that allows easy access to your usernames and passwords and remembers them in a safe manner. Password manager encrypts your passwords with an alphabetical encryption key and jambles the letters around to make it harder for attackers or guests to view saved passwords. Ofcourse, it is not the best, it is definetly better than saving all your passwords in a txt file without any protection or encryption.

To compile it yourself, you can simply open up the soloution and build.
To download an already compiled version, simply refer to the bin folder in the repository.

# How to use to program
Once you have downloaded PM++, you will see an exe file. Simple make a folder on your desktop (or anywhere you wish) and name it something like "Password manager" or something you won't forget. Put the exe in that folder and simply run it.
It will ask you to make a password as a first time setup. If you forget this password, it is theoritically not possible to retrieve the passwords, however, due to poor design, it is possible. That however won't be covered in this tutorial.

After performing first time set up, you will be prompted for an encryption key to use PM++ with. 
To generate an encryption and decryption key, simply refer to: https://www.dcode.fr/deranged-alphabet-generator or enter genrandom when prompted to generate a random valid encryption key. Make sure to take note of this.
This will return a deranged alphabet which you can use as a key. Everytime you launch PM++, you will have to provide this key so make sure to keep it safe. If you do not want to enter encryption key, refer to "How to not enter encryption key everytime".

Once logged in, simply read the commands available and experiment with them.

# How to not enter encryption key everytime

For ease of use, PM++ exe accepts a command line argument as your encryption key. With that in mind, you can use it to make a bat file which launches PM++ like such. If you don't understand, simply follow the instructions bellow:
1. Open notepad
2. Type: ./PasswordManager.exe [ENCRYPTION KEY]
3. Press file > Save as and save it in the same folder that PasswordManager.exe is present as a bat file

And you are done. Simply, everytime you wish to launch password manager without the need of entering your encryption key, you can just run the bat file.
