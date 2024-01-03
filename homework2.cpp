// Copy and paste your code here

#include <iostream>
#include <vector>
#include "feedback.h"

#include <string>
#include <sstream>
using namespace std;


class Node{
public:
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = nullptr;
    }

    Node(){}
    ~Node(){}
};

class LinkedList{
public:
    Node * head;
    bool isFull;
    int count;
    LinkedList(){
        head = nullptr;
        count = 0;
        isFull = false;
    }

    ~LinkedList(){

    }

    void display(){
        Node * ptr;
        ptr = head;
        while (ptr != NULL){
            cout << (*ptr).data << " ";
            ptr = (*ptr).next;
        }
    }

    void insert(int data) {
        // If the list is empty or the new node is less than the head
        if (head == nullptr || data < head->data) {
            Node* new_node = new Node(data);
            new_node->next = head;
            head = new_node;
            count++;
        }
            // If the new node is equal to the head, don't insert it
        else if (data == head->data) {

        }
        else {
            Node* current = head;
            // Traverse the list to find the appropriate position for the new node
            while (current->next != nullptr && current->next->data < data) {
                current = current->next;
            }
            // If the new node already exists, don't insert it
            if (current->next != nullptr && current->next->data == data) {
            }
            else {
                Node* new_node = new Node(data);
                new_node->next = current->next;
                current->next = new_node;
                count++;
            }
        }
    }

    bool containsData(int data)
    {
        Node *temp = new Node();

        temp = head;

        while (temp->next!= nullptr)
        {
            if(temp->data == data)
            {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    bool checkIsFull()
    {
        if(count==9){
            isFull = true;
        }

        return isFull;
    }



};

int to_int(char karakter) {
    if (karakter == '0') {
        return 0;
    } else if (karakter == '1') {
        return 1;
    } else if (karakter == '2') {
        return 2;
    } else if (karakter == '3') {
        return 3;
    } else if (karakter == '4') {
        return 4;
    } else if (karakter == '5') {
        return 5;
    } else if (karakter == '6') {
        return 6;
    } else if (karakter == '7') {
        return 7;
    } else if (karakter == '8') {
        return 8;
    } else if (karakter == '9') {
        return 9;
    } else{
        return -1;
    }
}



int main() {
    LinkedList possibles1, impossibles1, possibles2, impossibles2, possibles3, impossibles3;
    stringstream xx;
    int num;
    int Game_id;
    cout<<"Please enter a game ID."<<endl;
    cin >> Game_id;
    bool exitBool = true;
    string guess;
    while(exitBool) {

        cout<<"Enter your guess."<<endl;
        cin >> guess;

        if(!isdigit(guess[0])||!isdigit(guess[1])||!isdigit(guess[2]))
        {
            cout<<"Invalid guess. Enter your guess."<<endl;
            continue;
        }

        if(guess[0]== ' ' || guess[1]== ' ' || guess[2]==' ')
        {
            cout<<"Invalid guess. Enter your guess."<<endl;
            continue;
        }

        if(guess.length()>=4)
        {
            cout<<"Invalid guess. Enter your guess."<<endl;
            continue;
        }

        cout << "Linked lists:" << endl;
        string secr;
        secr = get_the_feedback(guess, Game_id);
        for (int i = 0; i < 3; i++) {
            int num_guess = to_int(guess[i]);
            if (secr[i] == 'G') {
                if (i == 0) {
                    for (int j = 0; j < 10; j++) {
                        if (num_guess == j)
                            continue;

                        impossibles1.insert(j);
                    }

                    possibles1.insert(num_guess);
                    impossibles2.insert(num_guess);
                    impossibles3.insert(num_guess);
                    cout << "Slot: 1" << endl;
                    cout << "Impossibles: ";
                    impossibles1.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles1.display();
                    cout << endl<<endl;

                } else if (i == 1) {

                    for (int j = 0; j < 10; j++) {
                        if (num_guess == j)
                            continue;

                        impossibles2.insert(j);
                    }

                    possibles2.insert(num_guess);
                    impossibles3.insert(num_guess);
                    impossibles1.insert(num_guess);
                    cout << "Slot: 2" << endl;
                    cout << "Impossibles: ";
                    impossibles2.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles2.display();
                    cout << endl<<endl;
                } else {

                    for (int j = 0; j < 10; j++) {
                        if (num_guess == j)
                            continue;

                        impossibles3.insert(j);
                    }

                    possibles3.insert(num_guess);
                    impossibles1.insert(num_guess);
                    impossibles2.insert(num_guess);
                    cout << "Slot: 3" << endl;
                    cout << "Impossibles: ";
                    impossibles3.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles3.display();
                    cout << endl<<endl;
                }

            } else if (secr[i] == 'Y') {
                if (i == 0) {
                    impossibles1.insert(num_guess);

                    if (!impossibles2.containsData(num_guess)) {
                        possibles2.insert(num_guess);
                    }

                    if (!impossibles3.containsData(num_guess)) {
                        possibles3.insert(num_guess);
                    }

                    cout << "Slot: 1" << endl;
                    cout << "Impossibles: ";
                    impossibles1.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles1.display();
                    cout << endl<<endl;
                } else if (i == 1) {
                    impossibles2.insert(num_guess);

                    if (!impossibles1.containsData(num_guess)) {
                        possibles1.insert(num_guess);
                    }

                    if (!impossibles3.containsData(num_guess)) {
                        possibles3.insert(num_guess);
                    }
                    cout << "Slot: 2" << endl;
                    cout << "Impossibles: ";
                    impossibles2.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles2.display();
                    cout << endl<<endl;
                } else {
                    impossibles3.insert(num_guess);

                    if (!impossibles2.containsData(num_guess)) {
                        possibles2.insert(num_guess);
                    }

                    if (!impossibles1.containsData(num_guess)) {
                        possibles1.insert(num_guess);
                    }
                    cout << "Slot: 3" << endl;
                    cout << "Impossibles: ";
                    impossibles3.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles3.display();
                    cout << endl<<endl;
                }
            } else if (secr[i] == 'R') {
                if (i == 0) {
                    impossibles1.insert(num_guess);
                    impossibles2.insert(num_guess);
                    impossibles3.insert(num_guess);
                    cout << "Slot: 1" << endl;
                    cout << "Impossibles: ";
                    impossibles1.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles1.display();
                    cout << endl<<endl;

                } else if (i == 1) {
                    impossibles1.insert(num_guess);
                    impossibles2.insert(num_guess);
                    impossibles3.insert(num_guess);
                    cout << "Slot: 2" << endl;
                    cout << "Impossibles: ";
                    impossibles2.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles2.display();
                    cout << endl<<endl;

                } else {
                    impossibles1.insert(num_guess);
                    impossibles2.insert(num_guess);
                    impossibles3.insert(num_guess);
                    cout << "Slot: 3" << endl;
                    cout << "Impossibles: ";
                    impossibles3.display();
                    cout << endl;
                    cout << "Possibles: ";
                    possibles3.display();
                    cout << endl<<endl;

                }
            }
        }

        if(impossibles1.checkIsFull() && impossibles2.checkIsFull() && impossibles3.count>8) {
            exitBool = false;
        }
        if(impossibles1.checkIsFull() && impossibles3.checkIsFull() && impossibles2.count>8) {exitBool = false;}
        if(impossibles2.checkIsFull() && impossibles3.checkIsFull() && impossibles1.count>8) {exitBool = false;}


    }



    return 0;
}


