#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

class AtbashCipher{
private:
    // starting by initializing variables to use later
    string str_normal_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string str_encrypt_chars = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    string str_encrypt_2parts = "MLKJIHGFEDCBAZYXWVUTSRQPON";
    bool default_encryption = true;

    int get_pos_in_string(char c, string str_check) {
        // taking a string and getting its position in the alphabetic order
        c = toupper(c);
        int pos = int(str_check.find(c));
        return pos;
    }

    void encrypt_decrypt_char(char &chr) {
        // encrypting or decrypting by swapping the char by equivalent char in the cipher
        int pos = get_pos_in_string(chr, str_normal_chars);
        if (default_encryption){
            chr = str_encrypt_chars[pos];
        }
        else{
            chr = str_encrypt_2parts[pos];
        }
    }


    void remove_non_alpha(string &message){
        // removing anything in the message that is not a character
        string result;
        for(char chr: message){
            if(isalpha(chr))
                result += chr;
        }
        message = result;
    }

    void encrypt_decrypt_message(string &message) {
        // encrypting every character in the prepared message
        remove_non_alpha(message);
        for (char &value: message) {
            encrypt_decrypt_char(value);
        }
    }

    void print_welcome_menu(){
        cout << "AtbashCipher Menu: \n";
        cout << "1) Encrypt Message default\n";
        cout << "2) Decrypt Message default\n";
        cout << "3) Encrypt Message ( 2 parts )\n";
        cout << "4) Decrypt Message ( 2 parts )\n";
        cout << "5) Main Menu" << endl;
    }

    int take_choice(int start, int end){
        // making sure to take a valid choice  from [start, end]
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
        encrypt_decrypt_message(message);
        cout << "Encrypted message: \n" << message << endl;
    }

    void decryption_menu(){
        string message = get_message("decrypted");
        encrypt_decrypt_message(message);
        cout << "Decrypted message: \n" << message << endl;
    }

public:

    void run_AtbashCipher(){
        do {
            print_welcome_menu();
            int choice = take_choice(1, 5);

            switch (choice) {
                case 1: {
                    default_encryption = true;
                    encryption_menu();break;
                }
                case 2: {
                    default_encryption = true;
                    decryption_menu();break;
                }
                case 3:{
                    default_encryption = false;
                    encryption_menu();break;
                }
                case 4:{
                    default_encryption = false;
                    decryption_menu();break;
                }
                case 5: return;
            }
        } while (true);
    }
};


int main(){
    AtbashCipher encryption;
    encryption.run_AtbashCipher();

    return 0;
}
