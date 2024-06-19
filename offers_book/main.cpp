#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Offers{
    vector<double> values;
    vector<int> amounts;
    public:
        Offers(){};
        void insert_offer(int position, double value, int amount){
            if (values.empty()){
                values.push_back(value);
                amounts.push_back(amount);
            }
            else{
            if (value > 0)
                values.insert(values.begin() + position, value);
            if (amount > 0)
                amounts.insert(amounts.begin() + position, amount);
            }
        }
        void modify_offer(int position, double value, int amount){
            if (value > 0)
                values[position] = value;
            if (amount > 0)
                amounts[position] = amount;
        }
        void remove_offer(int position){
            values.erase(values.begin() + position);
            amounts.erase(amounts.begin() + position);
        }
        void print_book(){
            for(int i = 0; i < values.size(); i++){
                cout << endl;
                cout << i + 1 << "," << values[i] << "," << amounts[i] << endl;
            }
        }
};


int main()
{
    int n = 0, action = 0, amount = 0, position = 0, j = 0, str_pos = 0;
    double value;
    cout << "Enter how many notifications will happen: " << endl;
    cin >> n;
    Offers book;
    cout << "Now enter the instructions for each notification formatted for 'POSITION, ACTION, VALUE, AMMOUNT', one per line: " << endl;
    string aux_input, token;
    string delimiter = ",";
    for(int i = 0; i < n; i++){
        j = 0;
        cin >> aux_input;
        while ((str_pos = aux_input.find(delimiter)) != string::npos) {
            token = aux_input.substr(0, str_pos);
            switch(j){
                case 0:
                    position = stoi(token) - 1;
                    break;
                case 1:
                    action = stoi(token);
                    break;
                case 2:
                    value = stod(token);
                    break;
            }
            aux_input.erase(0, str_pos + delimiter.length());
            j++;
        }
        amount = stoi(aux_input);
        switch(action){
            case 0:
                book.insert_offer(position, value, amount);
                break;
            case 1:
                book.modify_offer(position, value, amount);
                break;
            case 2:
                book.remove_offer(position);
                break;
        }
    }
    book.print_book();
    return 0;
}

