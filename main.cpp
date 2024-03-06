#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

class AtbashCipher{
private:
    string str_normal_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string str_encrypt_chars = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    int get_pos_in_string(char c, string str_check) {
        c = toupper(c);
        int pos = int(str_check.find(c));
        return pos;
    }
public:
    void encrypt_char(char &chr) {
        int pos = get_pos_in_string(chr, str_normal_chars);
        chr = str_encrypt_chars[pos];
    }

    void decrypt_char(char &chr) {
        int pos = get_pos_in_string(chr, str_encrypt_chars);
        chr =  str_normal_chars[pos];
    }


};

class run_ciphers{
private:
    int cipher_num = 2;
    AtbashCipher atbash_cipher;

    void encrypt_char(char &chr) {
        switch (cipher_num) {
            case 2:{
                atbash_cipher.encrypt_char(chr);break;
            }

        }

    }

    void decrypt_char(char &chr) {
        switch (cipher_num) {
            case 2: {
                atbash_cipher.decrypt_char(chr);break;
            }
        }
    }

    void remove_non_alpha(string &message){
        string result;
        char x= ' ';
        for(char chr: message){
            if (cipher_num==2)
                x = 'A';
            if(isalpha(chr)|| chr == x)
                result += chr;
        }
        message = result;
    }

    void encrypt_message(string &message) {
        remove_non_alpha(message);
        for (char &value: message) {
            encrypt_char(value);
        }
    }

    void decrypt_message(string &message) {
        remove_non_alpha(message);
        for (char &value: message) {
            decrypt_char(value);
        }
    }

    void print_welcome_menu(){
        cout << "AtbashCipher Menu: \n";
        cout << "1) Encrypt Message\n";
        cout << "2) Decrypt Message\n";
        cout << "3) Main Menu" << endl;
    }

    int take_choice(int start, int end){
        int choice;
        cout << "Enter choice from (" << start << "-" << end << "):";
        cin >> choice;
        if (cin.fail() || choice < start || choice > end) {
            cout << "Error!! invalid input." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return take_choice(start, end);
        }
        return choice;
    }

    string get_message(string type){
        string message;
        cout << "Enter message to " << type << ":";
        cin.ignore();
        getline(cin, message);
        return  message;
    }

    void encryption_menu(){
        string message = get_message("encrypt");
        encrypt_message(message);
        cout << "Encrypted message: \n" << message << endl;
    }

    void decryption_menu(){
        string message = get_message("decrypted");
        decrypt_message(message);
        cout << "Decrypted message: \n" << message << endl;
    }

public:

    void run_Cipher(){
        do {
            print_welcome_menu();
            int choice = take_choice(1, 3);

            switch (choice) {
                case 1: {
                    encryption_menu();break;
                }
                case 2: {
                    decryption_menu();break;
                }
                case 3: return;
            }
        } while (true);
    }
};


int main(){
    run_ciphers encryption;
    encryption.run_Cipher();

    return 0;
    }
