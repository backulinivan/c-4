#include <iostream>

using namespace std;

struct Point{
    double x, y;
};

struct Node{
    Point point;
    Node *next, *prev;
};

struct List{
    Node *head = nullptr;
    Node *tail = nullptr;
};

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

void add_node_before(Point &point, Node &node){
    Node *add = new Node;
    temp = node.prev;
    add->next = node;
    add->prev = temp;
    add->point = point;
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
    Point a = {rand(), rand()}, b = {rand(), rand()};
    List list;
    add_to_list(list, a);
    add_to_list(list, b);
    print_list(list);
    return 0;
}