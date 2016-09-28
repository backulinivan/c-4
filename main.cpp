#include <iostream>

using namespace std;

struct Point{
    int x, y;
};

struct Node{
    Point point;
    Node *next, *prev;
};

struct List{
    Node *head = nullptr;
    Node *tail = nullptr;
};

/*Node move_to_pos(List *list, int pos){
    Node *node = list->head;
    for (int i=0; i < pos; i++){
        node = node->next;
    }
}*/

void add_to_list(List &list, Point &point){
    Node *temp = new Node;
    temp->next = nullptr;
    temp->point = point;
    if (list.head != nullptr){
        temp->prev = list.tail;
        list.tail->next = temp;
        list.tail = temp;
    }
    else{
        temp->prev = nullptr;
        list.head = list.tail = temp;
    }
}

void add_node_before(List &list, Point &point, Node *node){
    Node *add = new Node;
    add->point = point;
    add->next = node;
    if (node == list.head){
        list.head = add;
        add->prev = nullptr;
    }else if (node == nullptr){
        cerr << "Invalid node!";
        exit(1);
    } else{
        add->prev = node->prev;
        node->prev->next = add;
        node->prev = add;
    }
}

void delete_node(List &list, Node *node){
    if (node != list.head and node != list.tail) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    } else if (node == list.tail){
        list.tail = node->prev;
    } else if (node == list.head){
        list.head = node->next;
    } else{
        cerr << "Invalid node!";
        exit(1);
    }
}

void print_point(Point &point){
    cout << "(" << point.x << ", " << point.y << ")" << endl;
}

void print_list(List &list){
    Node *temp = list.head;
    while(temp != nullptr){
        print_point(temp->point);
        temp = temp->next;
    }
}

int main() {
    List list;
    Point add = {20, 20};
    for (int i=0; i<6; i++){
        Point a = {rand()%10, rand()%10};
        add_to_list(list, a);
    }
    print_list(list);
    cout << endl;
    add_node_before(list, add, list.tail);
    delete_node(list, list.head->next);
    print_list(list);
    return 0;
}