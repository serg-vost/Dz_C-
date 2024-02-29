#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

void splitLinkedList(Node* head, int x, Node** smallerHead, Node** largerHead) {  // Функция для разделения списка на два: элементы меньше x и элементы больше x
    Node* smallerTail = nullptr;  // Инициализация указателей на хвосты списков меньших и больших элементов
    Node* largerTail = nullptr;
    // Проход по списку и создание новых узлов в соответствующих списках
    Node* current = head;
    while (current) {
        Node* newNode = new Node(current->data);
        if (current->data < x) {
            // Добавление в список элементов меньше x
            if (*smallerHead == nullptr) {
                *smallerHead = newNode;
                smallerTail = *smallerHead;
            }
            else {
                smallerTail->next = newNode;
                smallerTail = newNode;
            }
        }
        else {
            // Добавление в список элементов больше или равных x
            if (*largerHead == nullptr) {
                *largerHead = newNode;
                largerTail = *largerHead;
            }
            else {
                largerTail->next = newNode;
                largerTail = newNode;
            }
        }
        current = current->next;
    }
}

void printLinkedList(Node* head) { // Функция для печати списка
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RUS"); // Создание и инициализация исходного списка
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(7);
    // Печать исходного списка
    std::cout << "Исходный список: ";
    printLinkedList(head);

    int x; // Ввод значения для разделения списка
    std::cout << "Введите значение для разделения списка: ";
    std::cin >> x;
    // Инициализация указателей на головы списков меньших и больших элементов
    Node* smallerHead = nullptr;
    Node* largerHead = nullptr;
    // Разделение списка на два
    splitLinkedList(head, x, &smallerHead, &largerHead);
    // Печать списка элементов меньше x
    std::cout << "Список элементов меньше " << x << ": ";
    printLinkedList(smallerHead);
    // Печать списка элементов больше или равных x
    std::cout << "Список элементов больше или равных " << x << ": ";
    printLinkedList(largerHead);

    return 0;
}
