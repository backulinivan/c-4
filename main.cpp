#include <iostream>

using namespace std;

struct Point{
    int x, y;
    void print_point(){
        cout << "(" << x << ", " << y << ")" << endl;
    }

    bool compare_points(const Point &other){
        return x == other.x and y == other.y;
    }
};

struct Node{
    Point point;
    Node *next, *prev;
};

struct List{

    Node *beginning;
    Node *end;
    int length;

    List(){
        beginning = end = nullptr;
        length = 0;
    }

    void add_node(Point &point, Node *node){
        Node *add = new Node;
        add->point = point;
        if (beginning != nullptr) {
            if (node == nullptr) {
                cerr << "Invalid node!";
                exit(1);
            } else {
                add->prev = node;
                node->next = add;
                if (node == end){
                    add->next = nullptr;
                    end = add;
                } else {
                    add->next = node->next;
                    node->next->prev = add;
                }
            }
        } else {
            add->prev = nullptr;
            beginning = end = add;
        }
        length += 1;
    }

    void delete_node(Node *node){
        if (node != beginning and node != end) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
        } else if (node == end){
            end = node->prev;
            *node = nullptr;
        } else if (node == beginning){
            beginning = node->next;
            *node = nullptr;
        } else{
            cerr << "Invalid node!";
            exit(1);
        }
        length -= 1;
    }

    Node* search_node(const Point &s_point, bool dir = true) {
        Node *ptr = dir ? beginning : end;
        while (ptr) {
            if (ptr->point.compare_points(s_point))
                return ptr;
            if (dir)
                ptr = ptr->next;
            else
                ptr = ptr->prev;
        }
        return nullptr;
    }

    void print_list(){
        Node *temp = beginning;
        while(temp != nullptr){
            temp->point.print_point();
            temp = temp->next;
        }
    }
};

struct Tuple{
    int key;
    Node *value;
    Tuple(int _key, Node *_value){
        key = _key;
        value = _value;
    }
};

int hash(Point &point){
    return (point.x+point.y)%10;
}

class hash_List{
    List *keys[10];
    void add(const Tuple &pair){

    }
};

/*void delete_node(List &list, Node *node){
    if (node != list.beginning and node != list.end) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
    } else if (node == list.end){
        list.end = node->prev;
        *node = nullptr;
    } else if (node == list.beginning){
        list.beginning = node->next;
        *node = nullptr;
    } else{
        cerr << "Invalid node!";
        exit(1);
    }
    list.length -= 1;
}*/

int main() {
    List new_list;
    Point add = {7, 5};
    for (int i=0; i<6; i++){
        Point a = {rand()%10, rand()%10};
        new_list.add_node(a, new_list.end);
    }
    new_list.print_list();
    cout << endl;
    //add_node(list, add, move_to_pos(list, 3));
    //print_list(list);
    //cout << search_node(list, {7, 5}, 0);
    //add_node_before(list, add, list.tail);
    //delete_node(list, list.head->next);
    //print_list(list);
    return 0;
}