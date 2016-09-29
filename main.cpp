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
    int length = 0;
};

struct hash_Set{
//    TODO hash sets
};

bool compare_points(Point point1, Point point2){
    if (point1.x == point2.x and point1.y == point2.y) return true;
    else return false;
}

Node *move_to_pos(List &list, int pos){
    Node *node = list.head;
    if (pos == 0) return node;
    for (int i=0; i < pos; i++){
        if (node != list.tail)
            node = node->next;
        else return node;
    }
    return node;
}

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
    list.length += 1;
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
    list.length += 1;
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
    list.length -= 1;
}

int search_node(List &list, Point s_point, bool dir = 1){
    if (dir){
        for (int pos = 0; pos < list.length; pos++)
            if (compare_points(move_to_pos(list, pos)->point, s_point)) return pos;
    }else {
        for (int pos = list.length; pos > 0; pos--)
            if (compare_points(move_to_pos(list, pos)->point, s_point)) return pos;
    }
    return 0;
}

//TODO function 6

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
    Point add = {7, 5};
    for (int i=0; i<6; i++){
        Point a = {rand()%10, rand()%10};
        add_to_list(list, a);
    }
    print_list(list);
    cout << endl;
    add_node_before(list, add, move_to_pos(list, 3));
    print_list(list);
    cout << search_node(list, {7, 5}, 0);
    //add_node_before(list, add, list.tail);
    //delete_node(list, list.head->next);
    //print_list(list);
    return 0;
}