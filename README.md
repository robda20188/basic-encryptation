# Crypt
An extremely basic terminal encryption program made with C.

# How it works
The program encrypts displacing an array of symbols. For example, if the displacement is 2, the array of symbols displaced will look like this:
|9|0|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|1|2|3|4|5|6|7|8|
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|1|2|3|4|5|6|7|8|9|0|

So if we encrypt `"hello"` the result will be: `"jgnnq"`. To decrypt this, we will need to know the displacement with which it was encrypted (in this case 2).

So this program uses a private key encryptation method because the person who encrypts an the person who decrypts have to know the private key (displacement).

# How to run
First, you clone the repository
```sh
git clone https://github.com/robda20188/basic-encryption
```

You create the binary file
```sh
gcc crypt.c -o fileName
```
And then you run it
```sh
./fileName
```
