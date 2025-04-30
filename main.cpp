#include <iostream>
using namespace std;

class Node
{
public:
    char info;
    Node *next;
    Node *back;
    Node() {}
    Node(char c) : info(c), next(nullptr), back(nullptr) {}
};



class DoubleLinkedList
{
private:
public:
    Node *head , *tail ;
    int length = 0;
    DoubleLinkedList() : head(nullptr), tail(nullptr), length(0) {}
    DoubleLinkedList(string word) // Constructor for initializing the list with the word characters
    {
        if(!word.empty()) // handling if the inserted word is empty
        {
            Node *firstCharNode = new Node();
            firstCharNode->info = word[0];
            length++;
            head = firstCharNode, tail = firstCharNode;
            for (int i = 1; i < word.size(); ++i)
            {
                Node *newNode = new Node();
                newNode -> info = word[i];
                tail->next = newNode;
                newNode -> back = tail;
                tail = newNode;
                length++;
            }
        }
    }

    ~DoubleLinkedList()
    {
        while(head !=nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(char newChar, int position, bool isReplace = false)
    {
        if ((position < 1 || position > length+1) && isReplace == false )
        {
            cout<<"Position is out of range, Acceptable range for insertion: 1-"<<length+1<<" inclusive"<<endl;
            return ;
        }
        Node *toBeAdded = new Node(newChar);

        if (position == 1) // insert as the first element
        {
            toBeAdded->next = head;
            head = toBeAdded;
            length++;
            return;
        }
        else if (position == length+1) // inserting as the last element
        {
            tail->next = toBeAdded;
            toBeAdded->back = tail;
            tail = toBeAdded;
            length++;
            return;
        }
        else
        {
            Node *beforePosition;
            Node *afterPosition;
            Node *it = head;
            for (int i = 1; i <= position; ++i)
            {
                if (i == position-1)
                    beforePosition = it;
                it = it->next;
            }
            afterPosition = beforePosition -> next;

            toBeAdded->next = beforePosition->next;
            beforePosition->next = toBeAdded;
            toBeAdded->back = afterPosition->back;
            afterPosition->back = toBeAdded;
            length++;
        }
    }

    void deletePosition(int position)
    {
        if (position < 1 || position > length)
        {
            cout<<"Position is out of range, Acceptable range for deletion: 1-"<<length<<" inclusive"<<endl;
            return ;
        }
        if (position == 1) // first element
        {
            Node *temp = head;
            head = head -> next;
            if (head == 0 ) // only element
                tail = head;
            delete temp;
            length--;
            return;
        }
        else if (position == length) // last element
        {
            Node *beforeTail = head;
            Node *toBeDeleted = tail;
            while (beforeTail -> next != tail)
                beforeTail = beforeTail->next;
            tail = beforeTail;
            tail->next = 0;
            delete toBeDeleted;
            length--;
            return;
        }
        else // element in the middle of the list
        {
            Node *beforePosition;
            Node *afterPosition;
            Node *toBeDeleted = head;
            for (int i = 1; i < position; ++i)
            {
                if (i == position-1)
                    beforePosition = toBeDeleted;
                toBeDeleted = toBeDeleted->next;
            }
            afterPosition = beforePosition -> next;

            beforePosition -> next = toBeDeleted->next;
            afterPosition->back = toBeDeleted->back;
            length--;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != 0)
        {
            cout<<temp->info;
            temp = temp->next;
        }
        cout<<endl;
    }

    int stringLength()
    {
        return length;
    }

    void concat(const DoubleLinkedList &other) // assigned as const as we won't change the parameter
    {
        if (other.head == nullptr) // other list is empty
            return;
        if (head == nullptr) // the list is empty
        {
            Node* current = other.head;
            while (current != nullptr)
            {
                insert(current->info, length + 1);
                current = current->next;
            }
        }
        else
        {
            Node* current = other.head;
            while (current != nullptr)
            {
                insert(current->info, length + 1);
                current = current->next;
            }
        }
    }

    void substring(int start, int len)
    {
        DoubleLinkedList subList("D"); /// 'D' is a dummy character which will be deleted after extracting the substring
        if (start < 1 || start > length || len <= 0 || start + len - 1 > length) // checking for the edge cases that would fail the code
            cout<<"Substring data is not valid \n";
        Node *current = head;
        for (int i = 1; i < start; ++i)
            current = current->next;
        for (int i = 0; i < len && current != nullptr; ++i)
        {
            subList.insert(current->info, subList.length+1);
            current = current->next;
        }
        subList.deletePosition(1); // deleting the dummy character 'D'
        cout<<"Sublist is: ";
        subList.display();
    }

    int search(const string &str) // assigned as const as we won't change the parameter
    {
        if (str.empty() || str.length() > length)
        {
            cout<<"substring is empty or data is not valid\n";
            return -1; // return value of not found as return type is int
        }
        Node *current = head;
        for (int i = 1; i <= length-str.length()+ 1; ++i)
        {
            Node *temp = current;
            int j = 0;
            while (j < str.length() && temp->info == str[j] && temp!= 0)
            {
                temp = temp->next;
                j++;
            }
            if (j == str.length())
                return i; // index of first occurrence
            current = current->next;
        }
        return -1; // return value of not found as return type is int
    }

    void replace(const string &oldStr, const string &newStr) // assigned as const as we won't change the parameter
    {
        bool isReplace = true;
        int index = search(oldStr); // getting index of first occurrence of the substring to be replaced
        if (index == -1)
        {
            cout<<"substring is not found in the list to be replaced \n";
            return;
        }
        while (index != -1)
        {
            for (int i = 0; i < oldStr.length(); ++i) // deleting the old substring from list
                deletePosition(index);

            for (int i = 0; i < newStr.length(); ++i)  // inserting the new substring
                insert(newStr[i], index + i , isReplace);

            index = search(oldStr);
        }
    }
};



int main()
{
    string input1, input2;

    cout << "Enter string to add to list 1: ";
    cin >> input1;
    DoubleLinkedList list1(input1);

    cout << "Enter string to add to list 2: ";
    cin >> input2;
    DoubleLinkedList list2(input2);

    list1.concat(list2);
    cout << "Concatenated Lists: ";
    list1.display();
    cout<<"String length after concat: "<<list1.stringLength()<<endl;

    int position;
    cout << "Choose a character by a 1-indexed value to remove: ";
    cin >> position;
    list1.deletePosition(position);
    cout << "List after removal: ";
    list1.display();

    int start, length;
    cout << "Enter index and length to get substring: " << endl;
    cout << "index (1-index value): ";
    cin >> start;
    cout << "length: ";
    cin>> length;
    cout << "Substring: ";
    list1.substring(start, length);

    string searchString;
    cout << "Search for a string in the list: (NOTE: function is Case-Sensitive)\n";
    cin >> searchString;
    int index = list1.search(searchString);
    if (index != -1)
        cout << "Found at index " << index <<"  -> NOTE: 1-indexed answer"<< endl;
    else
        cout << "String not found" << endl;

    string oldString, newString;
    cout << "Enter 2 substrings to replace one with another: "<<endl;
    cout << "old string: ";
    cin >> oldString;
    cout << "new string: ";
    cin>> newString;
    list1.replace(oldString, newString);
    cout << "List after replacement: ";
    list1.display();


    return 0;
}
